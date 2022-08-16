/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
*/
#include "UnoPlayer.h"
#include "UnoCards.h"
#include "Uno.h"
#include "gtest/gtest.h"

TEST(TestUnoPlayer, testCheckHandFull) {
  UnoHand hand;
  UnoCards deck;
  UnoPlayer player;
  deck.populateDeck();
  hand.populateHand(deck.arrCard, hand.handArr);
  player.checkHand(hand.handArr);
  EXPECT_EQ(hand.handArr.size(), 7);
}

TEST(TestUnoPlayer, testGameRules) {
  UnoPlayer p;
  std::ifstream helpFile;
  p.gameRules();
  EXPECT_FALSE(helpFile.is_open());
}
