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
#include "../include/UnoPlayer.h"


  void UnoPlayer::checkHand(std::vector<UnoCards> &h) {
    int i = 1;
    for (auto x : h) {
      std::cout << i << ". " << findName(x.name) << " " <<
      findColour(x.colour) << std::endl;
      i++;
    }
  }

  UnoCards UnoPlayer::playCard(std::vector<UnoCards> &h) {
    std::cin.clear();
    std::cout << "Type the card position you would like to play" << std::endl;
    int x;
    std::cin >> x;
    if (x > h.size()) {
      std::cout << "Please input a position that exists in your hand" <<
      std::endl;
      std::cout << "Type the card position you would like to play" << std::endl;
      std::cin >> x;
    }
    if (x == 0) {
      gameRules();
      std::cout << "Type the card position you would like to play" << std::endl;
      std::cin >> x;
    }
    x = x - 1;
    std::cout << "You want to play " << findName(h.at(x).name) << " " <<
    findColour(h.at(x).colour) << std::endl;
    UnoCards temp;
    temp = h.at(x);
    h.erase(h.begin() + x);
    return temp;
  }

  void UnoPlayer::gameRules() {
  std::ifstream helpFile;
  std::string output;
  helpFile.open("src/UnoRules.txt");

  while (!helpFile.eof()) {
    getline(helpFile, output);
    std::cout << output;
    }
  helpFile.close();
  }
