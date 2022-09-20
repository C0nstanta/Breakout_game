//
// Created by parallels on 9/15/22.
//
#include "../headers/drawer.h"


Drawer::Drawer(XInfo& xinf) : p_xinfo_{std::make_shared<XInfo*>(&xinf)} {}

void Drawer::initX() {

    (*p_xinfo_)->display = XOpenDisplay("");
    if ((*p_xinfo_)->display == nullptr) { exit (-1); }

    int screen = DefaultScreen((*p_xinfo_)->display);
    uint32_t white = XWhitePixel((*p_xinfo_)->display, screen);
    uint32_t black = XBlackPixel((*p_xinfo_)->display, screen);

    (*p_xinfo_)->window = XCreateSimpleWindow((*p_xinfo_)->display,
                                           DefaultRootWindow((*p_xinfo_)->display),
                                           upper_left_x, upper_left_y,
                                           win_width, win_height,
                                           win_border_width,
                                           black,
                                           white );

    /*
      * Put the window on the screen.
      */
    XMapRaised( (*p_xinfo_)->display, (*p_xinfo_)->window );

    XFlush((*p_xinfo_)->display);
}

void Drawer::display_window() {
    /* set events & display window*/
    XSelectInput((*p_xinfo_)->display, (*p_xinfo_)->window, ButtonPressMask | KeyPressMask);
    XMapRaised((*p_xinfo_)->display, (*p_xinfo_)->window);
    XFlush((*p_xinfo_)->display);
}

void Drawer::x_draw(std::vector<std::shared_ptr<Displayable*>>& vec) {
    auto itr_begin = vec.begin();

    XClearWindow((*p_xinfo_)->display, (*p_xinfo_)->window);
    while ( itr_begin != vec.end() ) {
        Displayable* d = *(*itr_begin);
        d->paint((*(*p_xinfo_)));
        itr_begin++;
    }
    XFlush((*p_xinfo_)->display);
}

void Drawer::create_gc() {
    // create gc for drawing
    GC gc = XCreateGC((*p_xinfo_)->display, (*p_xinfo_)->window, 0, nullptr);

    XGetWindowAttributes((*p_xinfo_)->display, (*p_xinfo_)->window, &w_attr_);


    int screen_tmp = DefaultScreen( (*p_xinfo_)->display );

    XSetForeground((*p_xinfo_)->display, gc, BlackPixel((*p_xinfo_)->display, screen_tmp));

    XSetBackground((*p_xinfo_)->display, gc, WhitePixel((*p_xinfo_)->display, screen_tmp));

    // load a larger font
    XFontStruct * font;
    font = XLoadQueryFont ((*p_xinfo_)->display, "8x16");
    XSetFont ((*p_xinfo_)->display, gc, font->fid);

    int depth = DefaultDepth((*p_xinfo_)->display,
                             DefaultScreen((*p_xinfo_)->display));

    (*p_xinfo_)->pixmap = XCreatePixmap((*p_xinfo_)->display,
                                        (*p_xinfo_)->window,
                                        win_width, win_height,
                                        depth);
    (*p_xinfo_)->gc = gc;
}

void Drawer::color_map() {
    cmap_ = DefaultColormap((*p_xinfo_)->display,
                            DefaultScreen((*p_xinfo_)->display));
    XAllocNamedColor((*p_xinfo_)->display, cmap_, "red", &red_, &red_);
    XAllocNamedColor((*p_xinfo_)->display, cmap_, "blue", &blue_ , &blue_);
    XAllocNamedColor((*p_xinfo_)->display, cmap_, "green", &green_, &green_);
}

uint16_t Drawer::get_screen() const {
    return screen_;
}

XWindowAttributes& Drawer::get_win_attr() {
    return w_attr_;
}
