#include "../headers/test_helper.h"

void TestHelper::ClickKey(XInfo& tester_xinfo_, std::string letter, bool quit) {
    const char* c_letter[1];

    for ( int i  = 0; i < letter.length(); ++i) {
        c_letter[0] = letter.c_str();

        KeySym keysym = XStringToKeysym(c_letter[0]);
        KeyCode keycode = NoSymbol;
        keycode = XKeysymToKeycode( tester_xinfo_.display, keysym);

        XTestFakeKeyEvent(tester_xinfo_.display, keycode, true, 0);
        XTestFakeKeyEvent(tester_xinfo_.display, keycode, false, 0);

        XFlush(tester_xinfo_.display);
        std::cerr << "Click: " << c_letter[0] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    //=================quit from gui====================
    if (quit) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        KeySym keysym = XK_q;
        KeyCode keycode = NoSymbol;
        keycode = XKeysymToKeycode( tester_xinfo_.display, keysym);

        XTestFakeKeyEvent(tester_xinfo_.display, keycode, true, 0);
        XTestFakeKeyEvent(tester_xinfo_.display, keycode, false, 0);
        XFlush(tester_xinfo_.display);
        std::cerr << "Click quit" << std::endl;
    }
}