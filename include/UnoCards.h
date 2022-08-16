/*
Class: CPSC 2720
Coded by: Nicolas Crespo (n.crespo@uleth.ca), Javier S, Wyatt B.
Date: April 20, 2022
*/

#ifndef UNOCARDS_H
#define UNOCARDS_H

#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

class UnoCards {
 public:
  enum Colours {
    RED, GREEN, BLUE, YELLOW
  };

  enum Names {
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, DRAW2, SKIP,
    REVERSE, WILD, DRAW4WILD
  };

  Colours colour;
  Names name;

   /**
   * Constructor
   */
  UnoCards();

   /**
   * Creates the Uno deck, with colour and wild cards and shuffles them so they
   * appear in a random order
   */
  void populateDeck();

   /**
   * Finds colour based on int input | 0=red, 1=green, 2=blue, 3=yellow
   * @param int x determines which colour is returned
   * @return string of which colour was chosen
   */
  std::string findColour(int);

   /**
   * Finds Name based on int input
   * @param int x determines which name is returned
   * @return string of which name was chosen
   */
  std::string findName(int);

   /**
   * Prints card characteristics
   * @param vector<cardIdentity> c vector of card identities to print
   */
  void printCard(std::vector<UnoCards>);


   /**
   * Removes the top (back, implementation-wise) card of the deck
   * @param c card to be added to top of pile
   * @param pile vector of cards for c to be added to top
   */
  void addToPile(UnoCards, std::vector<UnoCards>&);
  /**
   * Draws card from the top of deck 
   * @param deck vector of cards to pull top from
   * @param pile where card from deck is placed in
   */
  void drawCardTop(std::vector<UnoCards>& , std::vector<UnoCards> &);

  std::vector<UnoCards> arrCard;
  std::vector<UnoCards> pile;

 private:
  int deckSize;
};
#endif
