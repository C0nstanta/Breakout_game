#pragma once
#ifndef BREAKOUT_BALL_H
#define BREAKOUT_BALL_H

#include "displayable.h"
#include "../config/game_settings.h"


using namespace GameConstants;

class Ball {
    XPoint ball_position_{ball_pos_x, ball_pos_y};
    XPoint ball_move_coord_{0, 0};
    uint16_t ball_speed_{ball_speed};

public:
    Ball() = default;

    [[nodiscard]] uint16_t get_ball_speed() const;
    [[nodiscard]] uint16_t get_ball_pos_x() const;
    [[nodiscard]] uint16_t get_ball_pos_y() const;
    [[nodiscard]] uint16_t get_ball_move_x() const;
    [[nodiscard]] uint16_t get_ball_move_y() const;

    void set_ball_pos_x(uint16_t);
    void set_ball_pos_y(uint16_t);
    void set_ball_move_x(uint16_t);
    void set_ball_move_y(uint16_t);
};


#endif //BREAKOUT_BALL_H
