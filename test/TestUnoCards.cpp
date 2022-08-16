/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
*/
#include <string>
#include <vector>
#include "UnoCards.h"
#include "gtest/gtest.h"

TEST(TestUnoCards, testPopulateDeck) {
  UnoCards deck;
  deck.populateDeck();

  EXPECT_EQ(deck.arrCard.size(), 60);
}

TEST(TestUnoCards, testFindColour) {
  UnoCards card;
  std::string R = "Red";
  std::string G = "Green";
  std::string B = "Blue";
  std::string Y = "Yellow";

  EXPECT_FALSE(card.findColour(0).compare(R));
  EXPECT_FALSE(card.findColour(1).compare(G));
  EXPECT_FALSE(card.findColour(2).compare(B));
  EXPECT_FALSE(card.findColour(3).compare(Y));
}

TEST(TestUnoCards, testFindName) {
  UnoCards card;
  std::vector<std::string> names{"Zero", "One", "Two", "Three", "Four", "Five",
  "Six", "Seven", "Eight", "Nine", "+ 2", "Skip", "Reverse", "Wild", "+4 Wild"};
  for (int i = 0; i < 15; i++) {
    EXPECT_FALSE(card.findName(i).compare(names.at(i)));
  }
}

TEST(TestUnoCards, testAddToPile) {
  UnoCards card;
  int pSize = card.pile.size();

  card.addToPile(card, card.pile);
  EXPECT_EQ(card.pile.size(), pSize + 1);
}

TEST(TestUnoCards, testDrawTop) {
  UnoCards card;
  card.populateDeck();

  EXPECT_EQ(card.pile.size(), 0);
  EXPECT_EQ(card.arrCard.size(), 60);
  card.drawCardTop(card.arrCard, card.pile);
  EXPECT_EQ(card.pile.size(), 1);
  EXPECT_EQ(card.arrCard.size(), 59);
}
