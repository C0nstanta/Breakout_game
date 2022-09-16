#pragma once
#ifndef BREAKOUT_RECTANGLE_H
#define BREAKOUT_RECTANGLE_H

#include <vector>
#include <tuple>
#include <functional>
#include "displayable.h"
#include "drawer.h"
#include "../config/game_settings.h"

using namespace GameConstants;


class Rectangle : public Displayable {
    int block_score_;

public:
    Rectangle(uint16_t);
    Rectangle(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);

    virtual void paint(XInfo&) override;
    virtual void fill(XInfo& );

    static std::vector<uint16_t> blocks_creator(XInfo&, Drawer&, std::vector<Rectangle*>&,
                                         uint16_t, uint16_t, uint16_t);

    static void paint_block(XInfo&, Drawer&, std::vector<Rectangle*>&, std::vector<uint16_t>&);

    uint16_t get_score() const {
        return block_score_;
    }

    void set_score(const uint16_t val) {
        block_score_ = val;
    }

    size_t get_width() const;
    size_t get_height() const;

    int get_x() const;
    int get_y() const;

    void set_x(int x) {
        x_ = x;
    }

    void set_y(int y) {
        y_ = y;
    }


private:
    int x_{0};
    int y_{0};
    size_t width_{0};
    size_t height_{0};
};

#endif //BREAKOUT_RECTANGLE_H
