/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
*/
#include "Game.h"
#include "UnoCards.h"
#include "UnoPlayer.h"
#include "UnoOpponent.h"
#include "UnoHand.h"
#include "Uno.h"
#include "gtest/gtest.h"

TEST(TestUno, testPlayerWin) {
  Uno u;
  UnoPlayer player;
  UnoOpponent opp;
  UnoCards deck;

  deck.populateDeck();
  opp.populateHand(deck.arrCard, opp.handArr);
  EXPECT_FALSE(u.winner(player, opp));
}

TEST(TestUno, testOpponentWin) {
  Uno u;
  UnoPlayer player;
  UnoOpponent opp;
  UnoCards deck;

  deck.populateDeck();
  player.populateHand(deck.arrCard, player.handArr);
  EXPECT_FALSE(u.winner(player, opp));
}

TEST(TestUno, testNeitherWin) {
  Uno u;
  UnoPlayer player;
  UnoOpponent opp;
  UnoCards deck;

  deck.populateDeck();
  player.populateHand(deck.arrCard, player.handArr);
  opp.populateHand(deck.arrCard, opp.handArr);
  EXPECT_TRUE(u.winner(player, opp));
}

TEST(TestUno, testShowWinPlayer) {
  Uno u;
  UnoPlayer player;
  UnoOpponent opp;
  UnoCards deck;

  deck.populateDeck();
  opp.populateHand(deck.arrCard, opp.handArr);
  EXPECT_NO_THROW(u.showWin(player));
}

TEST(TestUno, testShowWinOpponent) {
  Uno u;
  UnoPlayer player;
  UnoOpponent opp;
  UnoCards deck;

  deck.populateDeck();
  player.populateHand(deck.arrCard, player.handArr);
  EXPECT_NO_THROW(u.showWin(opp));
}

TEST(TestUno, testCompareCardsSameColour) {
  Uno u;
  UnoCards deck;

  deck.populateDeck();
  EXPECT_TRUE(u.compareCards(deck.arrCard.at(0), deck.arrCard.at(2)));
}

TEST(TestUno, testCompareCardsSameName) {
  Uno u;
  UnoCards deck;

  deck.populateDeck();
  EXPECT_TRUE(u.compareCards(deck.arrCard.at(10), deck.arrCard.at(11)));
}

TEST(TestUno, testCompareCardsUnsimilar) {
  Uno u;
  UnoCards deck;

  deck.populateDeck();
  EXPECT_FALSE(u.compareCards(deck.arrCard.at(0), deck.arrCard.at(1)));
}

TEST(TestUno, testDeckEmpty) {
  Uno u;
  UnoCards deck;

  EXPECT_TRUE(u.deckEmpty(deck.arrCard));
}

TEST(TestUno, testRefillDeck) {
  Uno u;
  UnoCards deck;

  deck.populateDeck();
  for (int i = 0; i < 60; i++) {
    deck.drawCardTop(deck.arrCard, deck.pile);
  }
  u.refillDeck(deck.arrCard, deck.pile);
  EXPECT_EQ(deck.arrCard.size(), 59);
}

TEST(TestUno, testReadyGame) {
  Uno u;
  UnoCards deck;
  UnoPlayer player;
  UnoOpponent opp;

  u.readyGame(player, opp);
  EXPECT_EQ(player.arrCard.size(), 45);
  EXPECT_EQ(player.handArr.size(), 7);
  EXPECT_EQ(opp.handArr.size(), 7);
  EXPECT_EQ(player.pile.size(), 1);
}

TEST(TestUno, testNoMoreCardsFalse) {
  Uno u;
  UnoPlayer player;
  UnoOpponent opp;

  player.populateDeck();
  player.populateHand(player.arrCard, player.handArr);
  opp.populateHand(player.arrCard, opp.handArr);
  EXPECT_FALSE(u.noMoreCards(player.handArr, opp.handArr, player.arrCard));
}

TEST(TestUno, testNoMoreCardsTrue) {
  Uno u;
  UnoPlayer player;
  UnoOpponent opp;

  //Player bot deck
  player.populateDeck();
  player.populateHand(player.arrCard, player.handArr);
  for (int i = 0; i < 43; i++) {
    player.drawCard(player.arrCard, player.handArr);
  }
  EXPECT_TRUE(u.noMoreCards(player.handArr, opp.handArr, player.arrCard));
}
