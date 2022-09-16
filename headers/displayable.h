#pragma once
#ifndef BREAKOUT_DISPLAYABLE_H
#define BREAKOUT_DISPLAYABLE_H

#include <iostream>
#include <string>

// Include Graph libs
#include <X11/Xlib.h>
#include <X11/Xutil.h>


struct XInfo {
    Display*  display;
    Window   window;
    GC       gc;
    Pixmap pixmap;
};

class Displayable {
public:
    virtual void paint(XInfo&) = 0;
};


#endif //BREAKOUT_DISPLAYABLE_H
