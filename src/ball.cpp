//
// Created by parallels on 9/15/22.
//
#include "../headers/ball.h"


uint16_t Ball::get_ball_speed() const {
    return ball_speed_;
}

uint16_t Ball::get_ball_pos_x() const {
    return ball_position_.x;
}

uint16_t Ball::get_ball_pos_y() const {
    return ball_position_.y;
}

void Ball::set_ball_pos_x(const uint16_t x) {
    ball_position_.x = x;
}

void Ball::set_ball_pos_y(const uint16_t y) {
    ball_position_.y = y;
}

uint16_t Ball::get_ball_move_x() const {
    return ball_move_coord_.x;
}

uint16_t Ball::get_ball_move_y() const {
    return ball_move_coord_.y;
}

void Ball::set_ball_move_x(const uint16_t x) {
    ball_move_coord_.x = x;
}

void Ball::set_ball_move_y(const uint16_t y) {
    ball_move_coord_.y = y;
}
