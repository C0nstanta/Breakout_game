#pragma once
#ifndef BREAKOUT_TEXTS_H
#define BREAKOUT_TEXTS_H

#include "displayable.h"

class Text : public Displayable {
public:
    Text() = delete;
    Text(int, int, std::string );

    void paint(XInfo&) override ;

private:
    int x_;
    int y_;
    std::string str_;
};

#endif //BREAKOUT_TEXTS_H
