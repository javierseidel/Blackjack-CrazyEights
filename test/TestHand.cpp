/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
*/
#include "Player.h"
#include "ClassicCards.h"
#include "Hand.h"
#include "gtest/gtest.h"

TEST(TestHand, testPopulateHand) {
  Hand hand;
  ClassicCards deck;
  Player player;
  deck.populateDeck();
  hand.populateHand(deck.arrCard, hand.handArr);
  EXPECT_EQ(hand.handArr.size(), 7);
}

TEST(TestHand, testDrawCard) {
  Hand hand;
  ClassicCards deck;
  Player player;
  deck.populateDeck();
  hand.populateHand(deck.arrCard, hand.handArr);
  hand.drawCard(deck.arrCard, hand.handArr);
  EXPECT_EQ(hand.handArr.size(), 8);
}
