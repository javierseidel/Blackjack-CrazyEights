/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
*/
#include "Player.h"
#include "ClassicCards.h"
#include "Hand.h"
#include "gtest/gtest.h"

TEST(TestPlayer, testCheckHandFull) {
  Hand hand;
  ClassicCards deck;
  Player player;
  deck.populateDeck();
  hand.populateHand(deck.arrCard, hand.handArr);
  player.checkHand(hand.handArr);
  EXPECT_EQ(hand.handArr.size(), 7);
}

TEST(TestPlayer, testGameRules) {
  Player p;
  std::ifstream helpFile;
  p.gameRules();
  EXPECT_FALSE(helpFile.is_open());
}
