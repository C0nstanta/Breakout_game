//
// Created by parallels on 9/18/22.
//
#pragma once
#ifndef BREAKOUT_TEST_HELPER_H
#define BREAKOUT_TEST_HELPER_H

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

#include <cstring>
#include "game.h"
#include <thread>
#include <chrono>

class TestHelper {
public:
    TestHelper() = default;

    void ClickKey(XInfo&, std::string, bool=false);
};


#endif //BREAKOUT_TEST_HELPER_H
