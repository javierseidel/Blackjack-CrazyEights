/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
*/
#include "Game.h"
#include "ClassicCards.h"
#include "Player.h"
#include "Opponent.h"
#include "Hand.h"
#include "CrazyEights.h"
#include "gtest/gtest.h"

TEST(TestCrazyEights, testPlayerWin) {
  CrazyEights ce;
  Player player;
  Opponent opp;
  ClassicCards deck;

  deck.populateDeck();
  opp.populateHand(deck.arrCard, opp.handArr);
  EXPECT_FALSE(ce.winner(player, opp));
}

TEST(TestCrazyEights, testOpponentWin) {
  CrazyEights ce;
  Player player;
  Opponent opp;
  ClassicCards deck;

  deck.populateDeck();
  player.populateHand(deck.arrCard, player.handArr);
  EXPECT_FALSE(ce.winner(player, opp));
}

TEST(TestCrazyEights, testNeitherWin) {
  CrazyEights ce;
  Player player;
  Opponent opp;
  ClassicCards deck;

  deck.populateDeck();
  player.populateHand(deck.arrCard, player.handArr);
  opp.populateHand(deck.arrCard, opp.handArr);
  EXPECT_TRUE(ce.winner(player, opp));
}

TEST(TestCrazyEights, testShowWinPlayer) {
  CrazyEights ce;
  Player player;
  Opponent opp;
  ClassicCards deck;

  deck.populateDeck();
  opp.populateHand(deck.arrCard, opp.handArr);
  EXPECT_NO_THROW(ce.showWin(player));
}

TEST(TestCrazyEights, testShowWinOpponent) {
  CrazyEights ce;
  Player player;
  Opponent opp;
  ClassicCards deck;

  deck.populateDeck();
  player.populateHand(deck.arrCard, player.handArr);
  EXPECT_NO_THROW(ce.showWin(opp));
}

TEST(TestCrazyEights, testCompareCardsSameSuit) {
  CrazyEights ce;
  ClassicCards deck;

  deck.populateDeck();
  EXPECT_TRUE(ce.compareCards(deck.arrCard.at(2), deck.arrCard.at(3)));
}

TEST(TestCrazyEights, testCompareCardsSameName) {
  CrazyEights ce;
  ClassicCards deck;

  deck.populateDeck();
  EXPECT_TRUE(ce.compareCards(deck.arrCard.at(0), deck.arrCard.at(3)));
}

TEST(TestCrazyEights, testCompareCardsUnsimilar) {
  CrazyEights ce;
  ClassicCards deck;

  deck.populateDeck();
  EXPECT_FALSE(ce.compareCards(deck.arrCard.at(1), deck.arrCard.at(28)));
}

TEST(TestCrazyEights, testDeckEmpty) {
  CrazyEights ce;
  ClassicCards deck;

  EXPECT_TRUE(ce.deckEmpty(deck.arrCard));
}

TEST(TestCrazyEights, testRefillDeck) {
  CrazyEights ce;
  ClassicCards deck;

  deck.populateDeck();
  for (int i = 0; i < 52; i++) {
    deck.drawCardTop(deck.arrCard, deck.pile);
  }
  ce.refillDeck(deck.arrCard, deck.pile);
  EXPECT_EQ(deck.arrCard.size(), 51);
}

TEST(TestCrazyEights, testReadyGame) {
  CrazyEights ce;
  ClassicCards deck;
  Player player;
  Opponent opp;

  ce.readyGame(player, opp);
  EXPECT_EQ(player.arrCard.size(), 37);
  EXPECT_EQ(player.handArr.size(), 7);
  EXPECT_EQ(opp.handArr.size(), 7);
  EXPECT_EQ(player.pile.size(), 1);
}

TEST(TestCrazyEights, testNoMoreCardsFalse) {
  CrazyEights ce;
  Player player;
  Opponent opp;

  player.populateDeck();
  player.populateHand(player.arrCard, player.handArr);
  opp.populateHand(player.arrCard, opp.handArr);
  EXPECT_FALSE(ce.noMoreCards(player.handArr, opp.handArr, player.arrCard));
}

TEST(TestCrazyEights, testNoMoreCardsTrue) {
  CrazyEights ce;
  Player player;
  Opponent opp;

  //Player bot deck
  player.populateDeck();
  player.populateHand(player.arrCard, player.handArr);
  for (int i = 0; i < 43; i++) {
    player.drawCard(player.arrCard, player.handArr);
  }
  EXPECT_TRUE(ce.noMoreCards(player.handArr, opp.handArr, player.arrCard));
}
