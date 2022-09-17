#pragma once
#ifndef BREAKOUT_DRAWER_H
#define BREAKOUT_DRAWER_H


#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "displayable.h"
#include "texts.h"
#include "../config/game_settings.h"

using namespace GameConstants;

class Drawer {
    std::shared_ptr<XInfo*> p_xinfo_;
    Colormap cmap_{};
    XWindowAttributes w_attr_{};
    uint16_t screen_{0};

public:
    explicit Drawer(XInfo&);

    friend class Rectangle;

    void initX();
    void display_window();
    void x_draw(std::vector<std::shared_ptr<Displayable*>>&);
    void create_gc();
    void color_map();
    [[nodiscard]] uint16_t get_screen() const;

    XWindowAttributes& get_win_attr();
    XColor red_{};
    XColor blue_{};
    XColor green_{};
};


#endif //BREAKOUT_DRAWER_H
