#pragma once
#ifndef BREAKOUT_GAME_SETTINGS_H
#define BREAKOUT_GAME_SETTINGS_H

#include <iostream>

namespace GameConstants {

    const uint16_t upper_left_x = 10;
    const uint16_t upper_left_y = 10;
    const uint16_t win_border_width = 3;
    const uint16_t win_width = 1280;
    const uint16_t win_height = 800;
    const uint16_t padding_width = 100;
    const uint16_t padding_height = 10;
    constexpr uint16_t padding_pos_x = win_width/2 - padding_width/2;
    constexpr uint16_t padding_pos_y = win_height - 70;
    const uint16_t ball_size = 10;
    const uint16_t ball_speed = 4;
    constexpr uint16_t ball_pos_x = padding_pos_x + padding_width/2;
    constexpr uint16_t ball_pos_y = win_width - (win_width / 3);
}

#endif //BREAKOUT_GAME_SETTINGS_H
