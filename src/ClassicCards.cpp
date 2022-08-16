/*
Class: CPSC 2720
Coded by: Wyatt Bristow (Wyatt.Bristow@uleth.ca), Javier S
Date: April 16, 2022
*/
#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "../include/ClassicCards.h"


  //  Constructor
  ClassicCards::ClassicCards() {
      // suit;
      // name;
  }

  void ClassicCards::populateDeck() {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        ClassicCards card;
        card.suit = (Suits)i;
        card.name = (Names)j;
        //std::cout << card.name << " of " << card.suit << std::endl;
        arrCard.push_back(card);
      }
    }
    random_shuffle(arrCard.begin(), arrCard.end());
  }

  std::string ClassicCards::findSuit(int x) {
    if (x == 0) {
      return "Clubs";
    } else if (x == 1) {
      return "Diamonds";
    } else if (x == 2) {
      return "Spades";
    } else if (x == 3) {
      return "Hearts";
    } else {
      return 0;
    }
  }

  std::string ClassicCards::findName(int x) {
    if (x == 0) {
      return "Ace";
    } else if (x == 1) {
      return "Two";
    } else if (x == 2) {
      return "Three";
    } else if (x == 3) {
      return "Four";
    } else if (x == 4) {
      return "Five";
    } else if (x == 5) {
      return "Six";
    } else if (x == 6) {
      return "Seven";
    } else if (x == 7) {
      return "Eight";
    } else if (x == 8) {
      return "Nine";
    } else if (x == 9) {
      return "Ten";
    } else if (x == 10) {
      return "Jack";
    } else if (x == 11) {
      return "Queen";
    } else if (x == 12) {
      return "King";
    } else {
      return 0;
    }
  }

  void ClassicCards::printCard(std::vector<ClassicCards> c) {
    for (auto x : c) {
      std::cout << findName(x.name) << " of " << findSuit(x.suit) << std::endl;
    }
  }

  void ClassicCards::addToPile(ClassicCards c,
  std::vector<ClassicCards> &pile) {
    pile.push_back(c);
  }

  void ClassicCards::drawCardTop(std::vector<ClassicCards> &deck,
  std::vector<ClassicCards> &pile) {
    ClassicCards x = deck.back();
    deck.pop_back();
    pile.push_back(x);
  }
