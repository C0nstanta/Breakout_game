//
// Created by parallels on 9/18/22.
//

#include <gtest/gtest.h>
#include <thread>

#include "../headers/ball.h"
#include "../headers/config_loader.h"
#include "../headers/displayable.h"
#include "../headers/drawer.h"
#include "../headers/game.h"
#include "../headers/paddle.h"
#include "../headers/rectangle.h"
#include "../headers/texts.h"
#include "../config/game_settings.h"
#include "../headers/test_helper.h"


class KeyboardSimulation : public Game, public testing::Test{
public:

    virtual void SetUp() {

    }

    Game game;
    TestHelper t_help;

};


TEST_F(KeyboardSimulation, move_paddle) {
    //Arrange
    auto ball = game.get_ball();
    auto padd = game.get_paddle();

    //Act
    std::thread t2([&] () { return  game.start(); });
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::thread t1([&] () { return game.some_process(t_help, "a"); }); //, letter

    t2.join();
    t1.join();

    //Assert
    ASSERT_EQ(padd->get_pad_x(), padding_pos_x - 20);
}
