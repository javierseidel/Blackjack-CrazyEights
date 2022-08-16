/*
Class: CPSC 2720
Coded by: Wyatt Bristow (Wyatt.Bristow@uleth.ca),
Date: April 16, 2022
*/
#include <iostream>
#include <vector>
#include "../include/Opponent.h"

bool Opponent::playCard(std::vector<ClassicCards> &h,
std::vector<ClassicCards> &p, ClassicCards &c) {
  //std::cout << findName(p.back().suit) << std::endl;
  int i = 0;
  for (auto x : h) {
    if (x.suit == p.back().suit || x.name == p.back().name) {
      std::cout << "---------------CARD PLAYED-----------" << std::endl;
      c = h.at(i);
      std::cout << findName(c.name) << " of " << findSuit(c.suit) << std::endl;
      h.erase(h.begin()+i);
      return true;
    }
    i++;
  }
  return false;
}
