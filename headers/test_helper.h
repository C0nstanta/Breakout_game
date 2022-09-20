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

    void ClickKey(XInfo& tester_xinfo_, std::string letter) {
        const char* c_letter[1];
        c_letter[0] = letter.c_str();

        KeySym keysym = XStringToKeysym(c_letter[0]);
        KeyCode keycode = NoSymbol;
        keycode = XKeysymToKeycode( tester_xinfo_.display, keysym);

        XTestFakeKeyEvent(tester_xinfo_.display, keycode, true, 0);
        XTestFakeKeyEvent(tester_xinfo_.display, keycode, false, 0);

        XFlush(tester_xinfo_.display);
        std::cerr << "Click one" << std::endl;
///=====================================
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        keysym = XK_q;
        keycode = NoSymbol;
        keycode = XKeysymToKeycode( tester_xinfo_.display, keysym);

        XTestFakeKeyEvent(tester_xinfo_.display, keycode, true, 0);
        XTestFakeKeyEvent(tester_xinfo_.display, keycode, false, 0);
        XFlush(tester_xinfo_.display);
        std::cerr << "Click one" << std::endl;
    }
};


#endif //BREAKOUT_TEST_HELPER_H
