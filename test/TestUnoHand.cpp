/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
*/
#include "UnoPlayer.h"
#include "UnoCards.h"
#include "UnoHand.h"
#include "gtest/gtest.h"

TEST(TestUnoHand, testPopulateHand) {
  UnoHand hand;
  UnoCards deck;
  UnoPlayer player;
  deck.populateDeck();
  hand.populateHand(deck.arrCard, hand.handArr);
  EXPECT_EQ(hand.handArr.size(), 7);
}

TEST(TestUnoHand, testDrawCard) {
  UnoHand hand;
  UnoCards deck;
  UnoPlayer player;
  deck.populateDeck();
  hand.populateHand(deck.arrCard, hand.handArr);
  hand.drawCard(deck.arrCard, hand.handArr);
  EXPECT_EQ(hand.handArr.size(), 8);
}
