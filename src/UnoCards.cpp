/*
Class: CPSC 2720
Coded by: Nicolas Crespo (n.crespo@uleth.ca), Javier S, Wyatt B.
Date: April 20, 2022
*/

#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "../include/UnoCards.h"


  //  Constructor
  UnoCards::UnoCards() {
      // colour;
      // name;
  }

  void UnoCards::populateDeck() {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 15; j++) {
        UnoCards card;
        card.colour = (Colours)i;
        card.name = (Names)j;
        //std::cout << card.name << " " << card.colour << std::endl;
        arrCard.push_back(card);
      }
    }
    random_shuffle(arrCard.begin(), arrCard.end());
  }

  std::string UnoCards::findColour(int x) {
    if (x == 0) {
      return "Red";
    } else if (x == 1) {
      return "Green";
    } else if (x == 2) {
      return "Blue";
    } else if (x == 3) {
      return "Yellow";
    } else {
      return 0;
    }
  }

  std::string UnoCards::findName(int x) {
    if (x == 0) {
      return "Zero";
    } else if (x == 1) {
      return "One";
    } else if (x == 2) {
      return "Two";
    } else if (x == 3) {
      return "Three";
    } else if (x == 4) {
      return "Four";
    } else if (x == 5) {
      return "Five";
    } else if (x == 6) {
      return "Six";
    } else if (x == 7) {
      return "Seven";
    } else if (x == 8) {
      return "Eight";
    } else if (x == 9) {
      return "Nine";
    } else if (x == 10) {
      return "+ 2";
    } else if (x == 11) {
      return "Skip";
    } else if (x == 12) {
      return "Reverse";
    } else if (x == 13) {
      return "Wild";
    } else if (x == 14) {
      return "+4 Wild";
    } else {
      return 0;
    }
  }

  void UnoCards::printCard(std::vector<UnoCards> c) {
    for (auto x : c) {
      std::cout << findName(x.name) << " " << findColour(x.colour) << std::endl;
    }
  }

  void UnoCards::addToPile(UnoCards c,
  std::vector<UnoCards> &pile) {
    pile.push_back(c);
  }

  void UnoCards::drawCardTop(std::vector<UnoCards> &deck,
  std::vector<UnoCards> &pile) {
    UnoCards x = deck.back();
    deck.pop_back();
    pile.push_back(x);
  }
