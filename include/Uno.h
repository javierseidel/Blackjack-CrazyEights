/*
Class: CPSC 2720
Coded by: Wyatt Bristow (Wyatt.Bristow@uleth.ca),
Date: April 16, 2022
*/

#ifndef UNO_H
#define UNO_H

#include <iostream>
#include <vector>
#include "../include/Game.h"
#include "../include/UnoCards.h"

class Uno {
 public:
    /**
     * Constructor
     */
    Uno();

    /**
     * Creates the game for play
     */
    void gameStart();

    /**
     * Test for win conditions of the player and the and the ai
     * @param p player object passed in for test of win conditions
     * @param o opponent passed in for test of win conditions
     * @return true if a player has reached a win condition
     */
    bool winner(UnoPlayer, UnoPlayer);

    /**
     * Compares two cards to check for equality
     * @param hand1 is the players hand
     * @param hand2 is the opponents hand
     * @return true if cards match false if they do not
     */
    bool compareCards(UnoCards, UnoCards);

    /**
     * shows player win statement
     * @param p player object
     */
    void showWin(UnoPlayer);

    /**
     * shows opponent win statement
     * @param p opponent object
     */
    void showWin(UnoOpponent);

    /**
     * test if deck size is 0
     * @param deck vector of cards to test for size
     * @return true if deck is empty, false if deck has card(s)
     */
    bool deckEmpty(std::vector<UnoCards> &);

    /**
     * Moves cards from pile (excluding top card) back to the deck
     * @param deck vector of cards in deck
     * @param pile vector of cards in pile
     */
    void refillDeck(std::vector<UnoCards> &, std::vector<UnoCards> &);

    /**
     * Fills hands of the player, opponent, then populates the deck
     * @param user The player object to fill hand
     * @param bot the opponent object to fill hand
     */
    void readyGame(UnoPlayer &, UnoOpponent &);

    /**
     * Tests if all cards are in play
     * @param player to read card count in players hand
     * @param bot to read card count in bots hand
     * @param deck to read card count in deck
     * @return true if all cards are in play
     */
    bool noMoreCards(std::vector<UnoCards>, std::vector<UnoCards>,
    std::vector<UnoCards>);

 private:
    UnoPlayer p;
    UnoOpponent o;
    UnoCards t, b, c, m;
};
#endif
