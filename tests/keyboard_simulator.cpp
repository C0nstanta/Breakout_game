/*
 * Greeting menu keyboard
 *
 * A - move left
 * D - move right
 * W - move up
 * W - move down
 * E - start game
 * Q - quit
 *
 * */
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


// First test - simple paddle move to the right side
TEST_F(KeyboardSimulation, move_paddle_left) {
    //Arrange
    auto ball = game.get_ball();
    auto padd = game.get_paddle();
    game.set_test_mode(true);

    //Act
    std::thread t2([&] () { return  game.start(); });
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::thread t1([&] () { return game.some_process(t_help, "a", true); }); //, letter

    t2.join();
    t1.join();

    //Assert
    ASSERT_EQ(padd->get_pad_x(), padding_pos_x - 20);
}

// First test - simple paddle move to the right side
TEST_F(KeyboardSimulation, move_paddle_right) {
    //Arrange
    auto ball = game.get_ball();
    auto padd = game.get_paddle();
    game.set_test_mode(true);

    //Act
    std::thread t2([&] () { return  game.start(); });
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::thread t1([&] () { return game.some_process(t_help, "d", true); }); //, letter

    t2.join();
    t1.join();

    //Assert
    ASSERT_EQ(padd->get_pad_x(), padding_pos_x + 20);
}


TEST_F(KeyboardSimulation, move_paddle_right_left) {
    //Arrange
    auto ball = game.get_ball();
    auto padd = game.get_paddle();
    game.set_test_mode(true);

    //Act
    std::thread t2([&] () { return  game.start(); });
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::thread t1([&] () { return game.some_process(t_help, "d", true); }); //, letter


    t1.join();
    t2.join();

    //Assert
    ASSERT_EQ(padd->get_pad_x(), padding_pos_x + 20);

}

TEST_F(KeyboardSimulation, move_paddle_right_left_up_down) {
    //Arrange
    auto padd = game.get_paddle();
    game.set_test_mode(true);
    int x = padd->get_pad_x();
    int y = padd->get_pad_y();

    //Act
    std::thread t2([&] () { return  game.start(); });
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    //left - 20
    game.some_process(t_help, "a");
    //Assert
    ASSERT_EQ(padd->get_pad_x(), x -= 20);

    //left - 20
    game.some_process(t_help, "a");
    //Assert
    ASSERT_EQ(padd->get_pad_x(), x -= 20);

    //right + 20

    game.some_process(t_help, "d");
    //Assert
    ASSERT_EQ(padd->get_pad_x(), x += 20);

    //right + 20
    game.some_process(t_help, "d");
    //Assert
    ASSERT_EQ(padd->get_pad_x(), x += 20);

    //UP - 10
    game.some_process(t_help, "w");
    //Assert
    ASSERT_EQ(padd->get_pad_y(), y -= 10);

    //UP - 10
    game.some_process(t_help, "s");
    //Assert
    ASSERT_EQ(padd->get_pad_y(), y += 10);


    //quit the game
    std::thread t1([&] () { return  game.some_process(t_help, "q"); });
    t1.join();
    t2.join();
}
