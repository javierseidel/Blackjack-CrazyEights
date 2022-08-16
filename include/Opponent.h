/*
Class: CPSC 2720
Coded by: Wyatt Bristow (Wyatt.Bristow@uleth.ca),
Date: April 16, 2022
*/

#ifndef OPPONENT_H
#define OPPONENT_H

#include <iostream>
#include <vector>
#include "Player.h"

class Opponent: public Player {
 public:
   /**
    * Compares two cards to check for equality
    * @param h is the players hand
    * @param p is the pile
    * @param c is the card played
    * @return true if the card can be played
    */
    bool playCard(std::vector<ClassicCards> &, std::vector<ClassicCards> &,
                 ClassicCards &);
};
#endif
