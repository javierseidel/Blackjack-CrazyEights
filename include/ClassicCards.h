/*
Class: CPSC 2720
Coded by: Wyatt Bristow (Wyatt.Bristow@uleth.ca),
Date: April 16, 2022
*/

#ifndef CLASSICCARDS_H
#define CLASSICCARDS_H

#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

class ClassicCards {
 public:
  enum Suits {
    CLUBS, DIAMONDS, SPADES, HEARTS
  };

  enum Names {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
  };

  Suits suit;
  Names name;

   /**
   * Constructor
   */
  ClassicCards();

   /**
   * Creates 52 unique cards and shuffles them so they appear in a random order
   */
  void populateDeck();

   /**
   * Finds suit based on int input | 0=clubs, 1=diamond, 2=spades, 3=hearts
   * @param int x determines which suit is returned
   * @return string of which suit was chosen
   */
  std::string findSuit(int);

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
  void printCard(std::vector<ClassicCards>);


   /**
   * Removes the top (back, implementation-wise) card of the deck
   * @param c Card being placed onto pile
   * @param pile pile of cards for c to be placed on
   */
  void addToPile(ClassicCards, std::vector<ClassicCards>&);

  /**
   * Draws a card from the top of the deck to be placed in players hand
   * @param deck The vector of cards being drawn from
   * @param pile the vector of cards the card is being placed in
   */
  void drawCardTop(std::vector<ClassicCards>& , std::vector<ClassicCards> &);

  std::vector<ClassicCards> arrCard;
  std::vector<ClassicCards> pile;

 private:
  int deckSize;
};
#endif
