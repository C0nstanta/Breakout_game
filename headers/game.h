#pragma once
#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <vector>
#include <string>

#include "ball.h"
#include "texts.h"
#include "rectangle.h"
#include "paddle.h"
#include "displayable.h"
#include "../config/game_settings.h"
#include "config_loader.h"

class Ball;
class Paddle;

class Game {
    XInfo xinfo_{};
    XEvent event{};

    std::vector<Displayable*> greeting_vec_{};
    std::vector<Displayable*> help_vec_{};
    std::vector<Displayable*> restart_vec_{};
    std::vector<Rectangle*> blocks_;
    Rectangle* rectangle_{};
    uint16_t score_{};
    Loader loader{};

    bool start_game_{false};
    bool stop_game_{false};
    bool shoot_the_ball_{false};
    bool restart_flag{true};
    bool quit_flag{false};

public:
    Game() = default;

    void init_texts();
    static Drawer init_drawer(Drawer& );
    void start();

    static void block_wall_checker(Ball&, Paddle&);
    static void block_bounce_checker(XInfo&, Ball&, std::vector<Rectangle*>, uint16_t&,
                              std::vector<uint16_t>&);
    static void repainter(XInfo&_, Drawer&, Ball&, Paddle&);
    void process_catcher (XInfo&, Paddle&, Ball&, uint16_t&);
};


#endif //BREAKOUT_GAME_H
