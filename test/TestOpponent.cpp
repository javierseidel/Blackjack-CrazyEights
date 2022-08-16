/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
*/
#include "Opponent.h"
#include "ClassicCards.h"
#include "Player.h"
#include "Hand.h"
#include "gtest/gtest.h"

TEST(TestOpponent, testCanPlayCardOpp) {
  Hand hand;
  Player player;
  Opponent opp;
  ClassicCards deck, card;
  int initHandSize = 7;

  player.populateDeck();
  opp.populateHand(player.arrCard, opp.handArr);
  player.drawCardTop(player.arrCard, player.pile);
  opp.playCard(opp.handArr, player.pile, deck);
  EXPECT_EQ(opp.handArr.size(), initHandSize - 1);
}
