/*
Class: CPSC 2720
Coded by: Nicolas Crespo (n.crespo@uleth.ca), Javier S, Wyatt B.
Date: April 20, 2022
*/

#ifndef UNOOPPONENT_H
#define UNOOPPONENT_H

#include <iostream>
#include <vector>
#include "UnoPlayer.h"

class UnoOpponent: public UnoPlayer {
 public:
   /**
    * scans opponent hand for matching card to play
    * @param h opponent hand to be scanned
    * @param p pile to read top card
    * @param c card to be played if matching card exists
    * @return true if matching card exists in hand
    */
    bool playCard(std::vector<UnoCards> &, std::vector<UnoCards> &,
                 UnoCards &);
};
#endif
