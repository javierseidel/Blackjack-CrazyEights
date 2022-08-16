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
#include "../include/UnoHand.h"

void UnoHand::populateHand(std::vector<UnoCards> &c,
std::vector<UnoCards> &h) {
  for (int i = 0; i < 7; i++) {
    UnoCards x = c.back();
    c.pop_back();
    h.push_back(x);
  }
}

void UnoHand::drawCard(std::vector<UnoCards> &c,
std::vector<UnoCards> &h) {
  UnoCards x = c.back();
  c.pop_back();
  h.push_back(x);
}
