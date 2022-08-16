/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
*/
#include <string>
#include <vector>
#include "ClassicCards.h"
#include "gtest/gtest.h"

TEST(TestClassicCards, testPopulateDeck) {
  ClassicCards deck;
  deck.populateDeck();

  EXPECT_EQ(deck.arrCard.size(), 52);
}

TEST(TestClassicCards, testFindSuit) {
  ClassicCards card;
  std::string C = "Clubs";
  std::string D = "Diamonds";
  std::string S = "Spades";
  std::string H = "Hearts";

  EXPECT_FALSE(card.findSuit(0).compare(C));
  EXPECT_FALSE(card.findSuit(1).compare(D));
  EXPECT_FALSE(card.findSuit(2).compare(S));
  EXPECT_FALSE(card.findSuit(3).compare(H));
}

TEST(TestClassicCards, testFindName) {
  ClassicCards card;
  std::vector<std::string> names{"Ace", "Two", "Three", "Four", "Five", "Six",
  "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  for (int i = 0; i < 13; i++) {
    EXPECT_FALSE(card.findName(i).compare(names.at(i)));
  }
}

TEST(TestClassicCards, testAddToPile) {
  ClassicCards card;
  int pSize = card.pile.size();

  card.addToPile(card, card.pile);
  EXPECT_EQ(card.pile.size(), pSize + 1);
}

TEST(TestClassicCards, testDrawTop) {
  ClassicCards card;
  card.populateDeck();

  EXPECT_EQ(card.pile.size(), 0);
  EXPECT_EQ(card.arrCard.size(), 52);
  card.drawCardTop(card.arrCard, card.pile);
  EXPECT_EQ(card.pile.size(), 1);
  EXPECT_EQ(card.arrCard.size(), 51);
}
