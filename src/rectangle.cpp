//
// Created by parallels on 9/12/22.
//

#include "../headers/rectangle.h"

Rectangle::Rectangle(uint16_t  block_score) : block_score_(block_score) {};
Rectangle::Rectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
                     uint16_t block_score=1) : block_score_(block_score),
                                               x_(x), y_(y),
                                               width_(width),
                                               height_(height)
{}



std::vector<uint16_t> Rectangle::blocks_creator(XInfo& xinfo, Drawer& drawer, std::vector<Rectangle*>& blocks, uint16_t num_rows,
                                                uint16_t block_width, uint16_t block_height) {
    if ( !blocks.empty() ) { return {}; }

    if ( win_height / 3 < (num_rows * (30 + block_height)) ) {
        std:: cerr << "Num of rows or block height is to large" << std::endl;
        exit(1);
    }

    std::vector<uint16_t> random_color;
    auto tup_color =  std::make_tuple(drawer.red_, drawer.blue_, drawer.green_);
    for (size_t row=0; row < num_rows; ++row) {
        for(size_t row_width=150; row_width < (win_width - 150); row_width += block_width) {
            uint16_t row_height = ((row * (block_height + 10)) * 2 + 200);
            blocks.push_back(new Rectangle(row_width, row_height, block_width, block_height));


            int rand_idx = (rand() % std::tuple_size<decltype(tup_color)>::value);
            random_color.push_back(rand_idx);
        }
    }
    return random_color;
}

void Rectangle::paint_block(XInfo& xinfo, Drawer& drawer, std::vector<Rectangle*>& blocks,
                            std::vector<uint16_t>& rand_color) {
    size_t n = blocks.size();
    auto tup_color =  std::make_tuple(drawer.red_, drawer.blue_, drawer.green_);

    for (size_t i = 0; i < n; ++i) {
        int rand_idx = rand_color[i];
        switch (rand_idx) {
            case 0:
                blocks[i]->block_score_ = 1;
                XSetForeground(xinfo.display, xinfo.gc, std::get<0>(tup_color).pixel);
                break;
            case 1:
                blocks[i]->block_score_ = 2;
                XSetForeground(xinfo.display, xinfo.gc, std::get<1>(tup_color).pixel);
                break;
            default:
                blocks[i]->block_score_ = 3;
                XSetForeground(xinfo.display, xinfo.gc, std::get<2>(tup_color).pixel);
                break;
        }
        blocks[i]->fill(xinfo);
    }
}

void Rectangle::paint(XInfo& xinfo) {
    XDrawRectangle(xinfo.display, xinfo.pixmap, xinfo.gc, x_, y_, width_, height_);
}

void Rectangle::fill(XInfo& xinfo) {
    XFillRectangle(xinfo.display, xinfo.pixmap, xinfo.gc, x_, y_, width_, height_);
}

size_t Rectangle::get_width() const {
    return width_;
}

size_t Rectangle::get_height() const {
    return height_;
}

int Rectangle::get_x() const {
    return x_;
}

int Rectangle::get_y() const {
    return y_;
}
