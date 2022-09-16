////
//// Created by parallels on 9/15/22.
////
#include "../headers/paddle.h"

Paddle::Paddle() = default;


//    virtual void paint(XInfo&) override;

uint16_t Paddle::get_pad_x() const {
    return padding_pos_x_;
}

uint16_t Paddle::get_pad_y() const {
    return padding_pos_y_;
}

uint16_t Paddle::get_pad_width() const {
    return padding_width_;
}

void Paddle::set_pad_x(uint16_t x) {
    padding_pos_x_ = x;
}

void Paddle::set_pad_y(uint16_t y) {
    padding_pos_y_ = y;
}