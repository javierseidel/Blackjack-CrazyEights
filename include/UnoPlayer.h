/*
Class: CPSC 2720
Coded by: Nicolas Crespo (n.crespo@uleth.ca), Javier S, Wyatt B.
Date: April 20, 2022
*/

#ifndef UNOPLAYER_H
#define UNOPLAYER_H

#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "../include/UnoHand.h"
#include "../include/UnoCards.h"


class UnoPlayer : public UnoHand {
 public:
  /**
  * Displays what cards the player currently has
  * @param h output hand to ostream for user to observe
  */
  void checkHand(std::vector<UnoCards> &);

  /**
  * Takes integer of what card in hand the player would like to play and returns a card
  * @param int value of position of the card in the hand of the player
  * @return Cards from the position the player chose
  */
  UnoCards playCard(std::vector<UnoCards> &);

  /**
  * Displays the rules to the terminal
  */
  void gameRules();
};
#endif
