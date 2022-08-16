/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
*/
#include "Game.h"
#include "gtest/gtest.h"

TEST(TestGame, testGameConstructor) {
  Game game;
  EXPECT_FALSE(game.gameState);
}
