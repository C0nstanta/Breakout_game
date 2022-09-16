#pragma once
#ifndef BREAKOUT_PADDLE_H
#define BREAKOUT_PADDLE_H

#include "displayable.h"
#include "ball.h"
#include "../config/game_settings.h"

using namespace GameConstants;
//class Ball;

class Paddle { //  : public Displayable
    uint16_t padding_width_{padding_width};
    uint16_t padding_height_{padding_height};
    uint16_t padding_pos_x_{padding_pos_x};
    uint16_t padding_pos_y_{padding_pos_y};

public:
    Paddle();

    friend class Ball;

    [[nodiscard]] uint16_t get_pad_x() const;
    [[nodiscard]] uint16_t get_pad_y() const;
    [[nodiscard]] uint16_t get_pad_width() const;

    void set_pad_x(uint16_t);
    void set_pad_y(uint16_t);
};


#endif //BREAKOUT_PADDLE_H
