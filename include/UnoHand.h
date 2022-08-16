/*
Class: CPSC 2720
Coded by: Nicolas Crespo (n.crespo@uleth.ca), Zachary Kawa <zac.kawa@uleth.ca>
Date: April 20, 2022
*/

#ifndef UNOHAND_H
#define UNOHAND_H

#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "../include/UnoCards.h"

class UnoHand : public UnoCards {
 public:
  /**
  * Draws 7 cards from the deck and adds it to a vector of cards (a hand)
  * @param a vector of cards which makes up the shuffled deck
  * @param a vector of cards which makes up the hand
  */
  void populateHand(std::vector<UnoCards> &, std::vector<UnoCards> &);

  /**
  * Draws a single card and adds it to a vector of cards (a hand)
  * @param a vector of cards which makes up the shuffled deck
  * @param a vector of cards which makes up the hand
  */
  void drawCard(std::vector<UnoCards> &, std::vector<UnoCards> &);

  std::vector<UnoCards> handArr;
};
#endif
