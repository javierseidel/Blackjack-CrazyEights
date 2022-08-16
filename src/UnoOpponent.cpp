/*
Class: CPSC 2720
Coded by: Nicolas Crespo (n.crespo@uleth.ca), Javier S, Wyatt B.
Date: April 20, 2022
*/

#include <iostream>
#include <vector>
#include "../include/UnoOpponent.h"

bool UnoOpponent::playCard(std::vector<UnoCards> &h,
std::vector<UnoCards> &p, UnoCards &c) {
  //std::cout << findName(p.back().colour) << std::endl;
  int i = 0;
  for (auto x : h) {
    if (x.colour == p.back().colour || x.name == p.back().name) {
      std::cout << "---------------CARD PLAYED-----------" << std::endl;
      c = h.at(i);
      std::cout << findName(c.name) << " " << findColour(c.colour)
      << std::endl;
      h.erase(h.begin()+i);
      return true;
    }
    i++;
  }
  return false;
}
