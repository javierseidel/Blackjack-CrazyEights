/*
Class: CPSC 2720
Coded by: Wyatt Bristow (Wyatt.Bristow@uleth.ca),
Date: April 16, 2022
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "../include/Hand.h"
#include "../include/ClassicCards.h"


class Player : public Hand {
 public:
  /**
  * Displays what cards the player currently has
  */
  void checkHand(std::vector<ClassicCards> &);

  /**
  * Takes integer of what card in hand the player would like to play and returns a card
  * @param int value of position of the card in the hand of the player
  * @return Cards from the position the player chose
  */
  ClassicCards playCard(std::vector<ClassicCards> &);

  /**
  * Displays the rules to the terminal
  */
  void gameRules();
};
#endif
