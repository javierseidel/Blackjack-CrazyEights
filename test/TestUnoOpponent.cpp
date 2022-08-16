/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
*/
#include "UnoOpponent.h"
#include "UnoCards.h"
#include "UnoPlayer.h"
#include "UnoHand.h"
#include "gtest/gtest.h"

TEST(TestUnoOpponent, testCanPlayCardOpp) {
  UnoHand hand;
  UnoPlayer player;
  UnoOpponent opp;
  UnoCards deck, card;
  int initHandSize = 7;

  player.populateDeck();
  opp.populateHand(player.arrCard, opp.handArr);
  player.drawCardTop(player.arrCard, player.pile);
  opp.playCard(opp.handArr, player.pile, deck);
  EXPECT_EQ(opp.handArr.size(), initHandSize - 1);
}
