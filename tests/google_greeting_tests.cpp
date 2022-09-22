//
// Created by parallels on 9/18/22.
//
#include <gtest/gtest.h>
#include "../headers/ball.h"
#include "../headers/config_loader.h"
#include "../headers/game.h"


class GameTest: public testing::Test {

protected:

    virtual void SetUp() {
        game.start();
    }

    Game game;
    Paddle padd;
    Ball ball;
};


TEST_F(GameTest, check_ball_init_va)  {
    //Arrange

    //Act
    /*simple init*/

    int n = ball.get_ball_speed();
    int x = padd.get_pad_y();
    //Assert
    //ball coord
    ASSERT_EQ(ball.get_ball_pos_x(), ball_pos_x);
    ASSERT_EQ(ball.get_ball_pos_y(), ball_pos_y);

    //ball move speed
    ASSERT_EQ(ball.get_ball_move_x(), 0);
    ASSERT_EQ(ball.get_ball_move_y(), 0);

    // ball speed
    ASSERT_EQ(ball.get_ball_speed(), ball_speed);
}

TEST_F(GameTest, check_ball_padd) {
    //Arrange


    //Act
    /*simple init*/

    //Assert
    ASSERT_EQ(padd.get_pad_x() , padding_pos_x);
    ASSERT_EQ(padd.get_pad_y() , padding_pos_y);
}


TEST_F(GameTest, check_game_start) {
    //Arrange

    KeySym key;
    XEvent event{1};
    char letter[10];
    uint16_t i = XLookupString((XKeyEvent *) &event, letter, 10, &key, nullptr);
    letter[0] = 'd';


    //Act
    game.start();

    //Assert
    ASSERT_EQ(padd.get_pad_x() , padding_pos_x + 20);
}


//int main(int argc, char** argv) {
//
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}