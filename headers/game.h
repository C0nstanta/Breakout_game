#pragma once
#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <utility>
#include <vector>
#include <string>
#include <memory>

//#include <thread>




//#include "ball.h"
#include "texts.h"
#include "rectangle.h"
#include "paddle.h"
#include "displayable.h"
#include "../config/game_settings.h"
#include "config_loader.h"
#include "test_helper.h"

#include <mutex>
#include <atomic>
#include <condition_variable>


class Paddle;

class Game {
    XInfo xinfo_{};
    XEvent event{};

    std::vector<std::shared_ptr<Displayable*>> greeting_vec_{};
    std::vector<std::shared_ptr<Displayable*>> help_vec_{};
    std::vector<std::shared_ptr<Displayable*>> restart_vec_{};
    std::vector<std::shared_ptr<Rectangle*>> blocks_;
    std::shared_ptr<Rectangle*> rectangle_{};
    uint16_t score_{};
    uint16_t total_score_{};

    bool start_game_{false};
    bool stop_game_{false};
    bool shoot_the_ball_{false};
    bool restart_flag{true};
    bool quit_flag{false};

public:
    Game() = default;

    void init_texts();
    static Drawer init_drawer(Drawer& );
    void start();

    static void block_wall_checker(Ball&, Paddle&);
    static void block_bounce_checker(XInfo&, Ball&, std::vector<std::shared_ptr<Rectangle*>>&,
                                     uint16_t&, std::vector<int16_t>&);
    static void repainter(XInfo&_, Drawer&, Ball&, Paddle&);
    void process_catcher (XInfo&, Paddle&, Ball&, uint16_t&);

    /*For Test helper additional methods*/
    XInfo* get_xInfo() {
        return &xinfo_;
    }

    Ball* get_ball() {
        return &ball_;
    }

    Paddle* get_paddle() {
        return  &padd_;
    }

    XEvent* get_event() {
        return &event;
    }


    void some_process(TestHelper& t_help, std::string letter) {

        std::unique_lock<std::mutex> lock(mtx_);
        in_out.wait(lock, [&] () {
            return !flag.load();
        });

        std::chrono::milliseconds(1500);
        t_help.ClickKey(xinfo_, std::move(letter));
        flag.store(false);
        in_out.notify_one();
    }

    void set_test_mode(bool tst=false) {
        is_test = tst;
    }

    /*This private block need to use test part*/
private:
    std::mutex mtx_;
    std::atomic<bool> flag{false};
    std::condition_variable in_out;

    Ball ball_{}; // need for tester
    Paddle padd_{};
    bool is_test{false};

};


#endif //BREAKOUT_GAME_H
