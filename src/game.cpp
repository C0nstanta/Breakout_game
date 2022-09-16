//
// Created by parallels on 9/15/22.
//
#include "../headers/game.h"


// get current time
uint64_t now() {
    timeval tv{};
    gettimeofday(&tv, nullptr);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

void Game::init_texts() {
    loader.text_loader(greeting_vec_, "greeting.txt");
    loader.text_loader(help_vec_, "help.txt");
    loader.text_loader(restart_vec_, "restart.txt");

}

Drawer Game::init_drawer(Drawer& dro) {
    dro.initX();
    dro.display_window();
    dro.create_gc();
    dro.color_map();
    return  dro;
}

void Game::start() {
    Drawer drawer(xinfo_);
    init_texts();
    init_drawer(drawer);

    Ball ball_;
    Paddle padd_;

    float FPS = 30;
    uint64_t lastRepaint = 0;
    std::vector<int16_t> random_color;
    uint16_t lives_num = 3;

    // load a larger font
    XFontStruct * font;
    font = XLoadQueryFont (xinfo_.display, "8x16");
    XSetFont (xinfo_.display, xinfo_.gc, font->fid);

    while (true) {

        // process if we have any events
        process_catcher (xinfo_, padd_, ball_, lives_num);

        uint64_t end = now();
        if (end - lastRepaint > 1000000 / FPS) {
            // clear background
            xinfo_.pixmap = xinfo_.window;
            XClearWindow(xinfo_.display, xinfo_.pixmap);
            if (start_game_ == True) {

                if (!help_vec_.empty()) {
                    help_vec_.pop_back();
                    help_vec_.pop_back();
                }

                help_vec_.push_back(new Text(800, 30, "Score: " + std::to_string(score_)));
                help_vec_.push_back(new Text(800, 50, "Lives left: " + std::to_string(lives_num)));
                drawer.x_draw(help_vec_);

                if (blocks_.empty()) {
                    random_color = rectangle_->blocks_creator(xinfo_, drawer, blocks_,
                                                              3, 80, 25);
                }

                rectangle_->paint_block(xinfo_, drawer, blocks_, random_color);
                XSetForeground(xinfo_.display, xinfo_.gc,
                               BlackPixel(xinfo_.display, drawer.get_screen()));

                //repaint walls blocks etc
                repainter(xinfo_, drawer, ball_, padd_);

                // update ball position
                ball_.set_ball_pos_x(ball_.get_ball_pos_x() + ball_.get_ball_move_x());
                ball_.set_ball_pos_y(ball_.get_ball_pos_y() + ball_.get_ball_move_y());

                if (shoot_the_ball_ == False) {
                    ball_.set_ball_pos_x(padd_.get_pad_x() + padding_width / 2);
                    ball_.set_ball_pos_y(win_height - 400);
                }

                //end game
                if (ball_.get_ball_pos_y() + ball_size / 2 > drawer.get_win_attr().height) {
                    XClearWindow(xinfo_.display, xinfo_.window);
//                        help_vec_.clear();
                    drawer.x_draw(restart_vec_);

                    start_game_ = False;
                    stop_game_ = True;
                    --lives_num;
                }

                // bounce ball
                block_wall_checker(ball_,padd_);
                // bounce blocks
                block_bounce_checker(xinfo_, ball_, blocks_, score_, random_color);
            }
            else {
                if (!stop_game_) {
                    drawer.x_draw(greeting_vec_);
                    XFillRectangle(xinfo_.display, xinfo_.pixmap, xinfo_.gc, padd_.get_pad_x(),
                                   padd_.get_pad_y(), padding_width, padding_height);
                }
                else if(!restart_flag) {
                    drawer.x_draw(greeting_vec_);
                    XFlush(xinfo_.display);

                }
                else {
                    if (lives_num < 1) {
                        restart_vec_.clear();
                        restart_vec_.push_back(new Text(550, 350, "Zero Lives left"));
                        restart_vec_.push_back(new Text(550, 380, "Press Q - to quit"));
                        restart_vec_.push_back(new Text(550, 410, "Press R - to main menu"));
                    }
                    else {
                        restart_vec_.pop_back();
                        restart_vec_.push_back(new Text(550, 350, "Lives left: " + std::to_string(lives_num)));
                    }
                    drawer.x_draw(restart_vec_);
                    XFlush(xinfo_.display);
                }
            }

            XFillRectangle(xinfo_.display, xinfo_.pixmap, xinfo_.gc, padd_.get_pad_x(),
                           padd_.get_pad_y(),
                           padding_width, padding_height);

            XCopyArea(xinfo_.display, xinfo_.pixmap, xinfo_.window, xinfo_.gc, 0, 0, win_width,
                      win_height, 0, 0);

            XFlush(xinfo_.display);
            lastRepaint = now(); // remember when the paint happened
        }

        lastRepaint = now();
        // IMPORTANT: sleep for a bit to let other processes work
        if (XPending(xinfo_.display) == 0) {
            usleep(1000000 / FPS - (now() - lastRepaint));
        }

        if (quit_flag) { break; }
    }
    XCloseDisplay(xinfo_.display);
}


void Game::block_wall_checker(Ball& ball_, Paddle& padd_) {
    //padding bounce
    if ( ( (ball_.get_ball_pos_x() - ball_size/2 >= padd_.get_pad_x()) &&
           ( (ball_.get_ball_pos_x() + ball_size/2 <= padd_.get_pad_x() + padding_width) )
         ) && ( ball_.get_ball_pos_y() >= padd_.get_pad_y() - 5 &&
                ball_.get_ball_pos_y() <= padd_.get_pad_y() + 5 )

            ) {

        ball_.set_ball_move_x(ball_.get_ball_move_x() /* + rand() % 5 + (-2) */);
        ball_.set_ball_move_y(-ball_.get_ball_move_y() /* + rand() % 5 + (-2) */);
    }

    // left wall bounce
    if ( (ball_.get_ball_pos_x() >= 10 - ball_size/2) &&
         (ball_.get_ball_pos_x() <= 10 + ball_size) ) {

        ball_.set_ball_move_x(-ball_.get_ball_move_x() /* + rand() % 5 + (-2) */);
        ball_.set_ball_move_y(ball_.get_ball_move_y() /* + rand() % 5 + (-2) */);
    }

    //right wall bounce
    if ( (ball_.get_ball_pos_x()  <= win_width - 10 + ball_size/2) &&
         (ball_.get_ball_pos_x()  >= win_width - 10 - ball_size) )  {

        ball_.set_ball_move_x(-ball_.get_ball_move_x() /* + rand() % 5 + (-2) */);
        ball_.set_ball_move_y(ball_.get_ball_move_y() /* + rand() % 5 + (-2) */);
    }

    //ceiling bounce
    if ( (ball_.get_ball_pos_y() >= 130 - ball_size) &&
         (ball_.get_ball_pos_y() <= 130 + ball_size) )  {

        ball_.set_ball_move_x(ball_.get_ball_move_x() /* + rand() % 5 + (-2) */);
        ball_.set_ball_move_y(-ball_.get_ball_move_y() /* + rand() % 5 + (-2) */);
    }
}

void Game::block_bounce_checker(XInfo& xinfo_, Ball& ball_, std::vector<Rectangle*>& blocks_, uint16_t& score_,
                          std::vector<int16_t>& random_color) {
    int erase = false;
    for (size_t i = 0; i < blocks_.size(); ++i) {
        //bottom block side
        if ( (ball_.get_ball_pos_x()  >= blocks_[i]->get_x() - ball_size/2 &&
              ( ball_.get_ball_pos_x() <= blocks_[i]->get_x() + 80 + ball_size/2)
             ) && ( (blocks_[i]->get_y() + 25 - ball_size/2 <= ball_.get_ball_pos_y()) &&
                    (blocks_[i]->get_y() + 25 + ball_size/2 >= ball_.get_ball_pos_y())
             )
                ) {

            ball_.set_ball_move_x(ball_.get_ball_move_x() /* + rand() % 5 + (-2) */);
            ball_.set_ball_move_y(-ball_.get_ball_move_y() /* + rand() % 5 + (-2) */);
            erase = true;
        }
            // ceiling block side
        else if ( (ball_.get_ball_pos_x()  >= blocks_[i]->get_x() - ball_size &&
                   ( ball_.get_ball_pos_x() <= blocks_[i]->get_x() + 80 + ball_size)
                  ) && ( (ball_.get_ball_pos_y() <= blocks_[i]->get_y() + ball_size) &&
                         (ball_.get_ball_pos_y() >= blocks_[i]->get_y() - ball_size)
                  )
                ) {

            ball_.set_ball_move_x(ball_.get_ball_move_x() /* + rand() % 5 + (-2) */);
            ball_.set_ball_move_y(-ball_.get_ball_move_y() /* + rand() % 5 + (-2) */);
            erase = true;
        }
        // left block wall
        else if ( (ball_.get_ball_pos_x() + ball_size <= blocks_[i]->get_x()) &&
                (ball_.get_ball_pos_x() - ball_size >= blocks_[i]->get_x())
                &&
                ( (ball_.get_ball_pos_y() <= blocks_[i]->get_y() + 25 + ball_size) &&
                        (ball_.get_ball_pos_y() >= blocks_[i]->get_y() - ball_size)
                        )
                )
        {
            ball_.set_ball_move_x(-ball_.get_ball_move_x() /* + rand() % 5 + (-2) */);
            ball_.set_ball_move_y(ball_.get_ball_move_y() /* + rand() % 5 + (-2) */);
            erase = true;

        }
        // right block wall
        else if ( ( (ball_.get_ball_pos_x() >= blocks_[i]->get_x() + 80 + ball_size / 2 - 1) && // - ball_size/2
                    (ball_.get_ball_pos_x() <= blocks_[i]->get_x() + 80 + ball_size + 3) ) &&
                ((ball_.get_ball_pos_y() <= blocks_[i]->get_y() + 25) &&
                        (ball_.get_ball_pos_y() >= blocks_[i]->get_y()))
                ) {

            ball_.set_ball_move_x(-ball_.get_ball_move_x() /* + rand() % 5 + (-2) */);
            ball_.set_ball_move_y(ball_.get_ball_move_y() /* + rand() % 5 + (-2) */);
            erase = true;
        }

        if(erase == true) {
            score_ += blocks_[i]->get_score();
            if (blocks_[i]->get_score() == 1) {
                blocks_.erase(blocks_.begin() + i);
                random_color.erase(random_color.begin() + i);
                --i;
            }
            else {
                blocks_[i]->set_score(blocks_[i]->get_score() - 1);
                random_color[i] = (blocks_[i]->get_score() - 1);
            }

            XFlush(xinfo_.display);
            return;
        }
    }
}

void Game::repainter(XInfo& xinfo_, Drawer& drawer, Ball& ball_, Paddle& padd_) {

    //draw 3 block
    XSetForeground(xinfo_.display, xinfo_.gc, drawer.red_.pixel);
    XFillRectangle(xinfo_.display, xinfo_.pixmap, xinfo_.gc,
                   win_width - 150, 10, 80, 25);

    XSetForeground(xinfo_.display, xinfo_.gc, drawer.green_.pixel);
    XFillRectangle(xinfo_.display, xinfo_.pixmap, xinfo_.gc,
                   win_width - 150, 45, 80, 25);

    XSetForeground(xinfo_.display, xinfo_.gc, drawer.blue_.pixel);
    XFillRectangle(xinfo_.display, xinfo_.pixmap, xinfo_.gc,
                   win_width - 150, 80, 80, 25);

    // draw paddle
    XFillRectangle(xinfo_.display, xinfo_.pixmap, xinfo_.gc,
                   padd_.get_pad_x(), padd_.get_pad_y(), padding_width, padding_height);

    XSetForeground(xinfo_.display, xinfo_.gc,
                   BlackPixel(xinfo_.display, drawer.get_screen()));
    // draw ball from centre
    XFillArc(xinfo_.display, xinfo_.pixmap, xinfo_.gc,
             ball_.get_ball_pos_x() - ball_size / 2,
             ball_.get_ball_pos_y() - ball_size / 2,
             ball_size, ball_size,
             0, 360 * 64); // angles ...

    // draw the borders
    XDrawLine(xinfo_.display, xinfo_.window, xinfo_.gc,
              10, 130, win_width - 10, 130);

    XDrawLine(xinfo_.display, xinfo_.window, xinfo_.gc,
              10, win_height - 10, 10, 130);

    XDrawLine(xinfo_.display, xinfo_.window, xinfo_.gc,
              win_width - 10, win_height - 10, win_width - 10, 130);
}

void Game::process_catcher (XInfo& xInfo, Paddle& padd_, Ball& ball_, uint16_t& lives_num) {
    if (XPending(xinfo_.display) > 0) {
        XNextEvent(xinfo_.display, &event);

        switch (event.type) {
            // mouse button press
            case ButtonPress:
                std::cout << "Click" << std::endl;
                break;
            case KeyPress: // any keypress
                KeySym key;
                char letter[10];
                uint16_t i = XLookupString((XKeyEvent *) &event, letter, 10, &key, nullptr);

                // move right
                if (i == 1 && letter[0] == 'd') {
                    if (padd_.get_pad_x() + padd_.get_pad_width() + 20 <= win_width) {
                        padd_.set_pad_x(padd_.get_pad_x() + 20);
                    } else {
                        padd_.set_pad_x(win_width - padding_width);
                    }
                }

                // move left
                if (i == 1 && letter[0] == 'a') {
                    if (padd_.get_pad_x() - 20 >= 0) {
                        padd_.set_pad_x(padd_.get_pad_x() - 20);
                    } else {
                        padd_.set_pad_x(0);
                    }
                }

                if (i == 1 && letter[0] == 'w') {
                    if (padd_.get_pad_y() - padding_height >= 350) {
                        padd_.set_pad_y(padd_.get_pad_y() - 10);
                    } else {
                        padd_.set_pad_y(350);
                    }
                }

                if (i == 1 && letter[0] == 's') {
                    if (padd_.get_pad_y() + padding_height <= 740) {
                        padd_.set_pad_y(padd_.get_pad_y() + 10);
                    } else {
                        padd_.set_pad_y(740);
                    }
                }

                if (i == 1 && letter[0] == 'e') {
                    init_texts();
                    start_game_ = true;
                    restart_flag = true;
                    lives_num = 3;
                    score_ = 0;
                }

                if (i == 1 && letter[0] == 'p' && shoot_the_ball_ == False) {
                    shoot_the_ball_ = True;
                    int v1 = rand() % 3;
                    if (v1 == 1) {
                        ball_.set_ball_move_x(ball_.get_ball_speed());
                    } else {
                        ball_.set_ball_move_x(ball_.get_ball_speed());
                    }
                    ball_.set_ball_move_y(ball_.get_ball_speed());
                }

                // quit game
                if (i == 1 && letter[0] == 'q' ) { //&& (start_game_ == True || (start_game_ == False && stop_game_ == True))
                    quit_flag = true;
                    break;
                }

                if ( (i == 1 && letter[0] == 'r') && (start_game_ == True ||
                                                      (start_game_ == False && stop_game_ == True))) {
                    XClearWindow(xinfo_.display, xinfo_.window);
                    if (lives_num < 1) {
                        restart_flag = false;
                        start_game_ = false;
                        stop_game_ = false;
                        shoot_the_ball_ = false;
                        return;
                    }

                    score_ = 0;
                    blocks_.clear();
                    padd_.set_pad_x(win_width / 2 - padding_width / 2);
                    padd_.set_pad_y(win_height - 50);

                    start_game_ = true;
                    stop_game_ = false;
                    shoot_the_ball_ = false;
                    ball_.set_ball_move_x(0); // 0
                    ball_.set_ball_move_y(win_height); // 0
                }
                break;
        }
    }
}