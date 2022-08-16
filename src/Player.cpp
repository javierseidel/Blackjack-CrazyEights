/*
Class: CPSC 2720
Coded by: Wyatt Bristow (Wyatt.Bristow@uleth.ca),
Date: April 16, 2022
*/
#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "../include/ClassicCards.h"
#include "../include/Hand.h"
#include "../include/Player.h"


  void Player::checkHand(std::vector<ClassicCards> &h) {
    int i = 1;
    for (auto x : h) {
      std::cout << i << ". " << findName(x.name) << " of " <<
      findSuit(x.suit) << std::endl;
      i++;
    }
  }

  ClassicCards Player::playCard(std::vector<ClassicCards> &h) {
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
    std::cout << "You want to play " << findName(h.at(x).name) << " of " <<
    findSuit(h.at(x).suit) << std::endl;
    ClassicCards temp;
    temp = h.at(x);
    h.erase(h.begin() + x);
    return temp;
  }

  void Player::gameRules() {
  std::ifstream helpFile;
  std::string output;
  helpFile.open("src/CrazyEightsRules.txt");

  while (!helpFile.eof()) {
    getline(helpFile, output);
    std::cout << output;
    }
  helpFile.close();
  }
