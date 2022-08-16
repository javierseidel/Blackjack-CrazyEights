/*
* @author Zachary Kawa <zac.kawa@uleth.ca>
* @date Spring 2022
* Crazy Eights Group Project
*/
#ifndef HAND_H
#define HAND_H

#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "../include/ClassicCards.h"

class Hand : public ClassicCards {
 public:
  /*
  * Draws 7 cards from the deck and adds it to a vector of cards (a hand)
  * @param a vector of cards which makes up the shuffled deck
  * @param a vector of cards which makes up the hand
  */
  void populateHand(std::vector<ClassicCards> &, std::vector<ClassicCards> &);

  /*
  * Draws a single card and adds it to a vector of cards (a hand)
  * @param a vector of cards which makes up the shuffled deck
  * @param a vector of cards which makes up the hand
  */
  void drawCard(std::vector<ClassicCards> &, std::vector<ClassicCards> &);

  std::vector<ClassicCards> handArr;
};
#endif
