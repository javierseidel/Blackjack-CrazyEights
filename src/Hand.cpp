/*
* @author Javier Seidel
* @date Spring 2022
* Crazy Eights Group Project
*/
#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "../include/ClassicCards.h"
#include "../include/Hand.h"


  void Hand::populateHand(std::vector<ClassicCards> &c,
  std::vector<ClassicCards> &h) {
    for (int i = 0; i < 7; i++) {
      ClassicCards x = c.back();
      c.pop_back();
      h.push_back(x);
    }
  }

  void Hand::drawCard(std::vector<ClassicCards> &c,
  std::vector<ClassicCards> &h) {
    ClassicCards x = c.back();
    c.pop_back();
    h.push_back(x);
  }
