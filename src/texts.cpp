//
// Created by parallels on 9/12/22.
//

#include <utility>

#include "../headers/texts.h"


Text::Text(int x, int y, std::string  str): x_(x), y_(y), str_(std::move(str))  {

 }

 void Text::paint(XInfo& xinfo)  {
//        XDrawImageString( xinfo.display, xinfo.pixmap, xinfo.gc,
//                          x_, y_, str_.c_str(), str_.length() );
//     XDrawString(xinfo.display, xinfo.pixmap, xinfo.gc,
//                          x_, y_, str_.c_str(), str_.length());

//     XFontStruct *font;
//     font = XLoadQueryFont (xinfo.display, "8x16");

    XTextItem xtext;
    xtext.chars =  &str_[0];
    xtext.nchars = str_.length();
    xtext.delta = 0;
    xtext.font =  None;

     XDrawText(xinfo.display, xinfo.pixmap, xinfo.gc, x_, y_, &xtext, 1);
    }
