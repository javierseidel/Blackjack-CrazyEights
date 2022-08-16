/*
Class: CPSC 2720
Coded by: Wyatt Bristow (Wyatt.Bristow@uleth.ca),
Date: April 16, 2022
*/

#ifndef CRAZYEIGHTS_H
#define CRAZYEIGHTS_H

#include <iostream>
#include <vector>
#include "../include/Game.h"
#include "../include/ClassicCards.h"

class CrazyEights {
 public:
    /**
     * Constructor
     */
    CrazyEights();
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
    bool winner(Player, Player);

    /**
     * Compares two cards to check for equality
     * @param hand1 is the players hand
     * @param hand2 is the opponents hand
     * @return true if cards match false if they do not
     */
    bool compareCards(ClassicCards, ClassicCards);

    /**
     * shows player win statement
     * @param p player object
     */
    void showWin(Player);

    /**
     * shows opponent win statement
     * @param p opponent object
     */
    void showWin(Opponent);

    /**
     * test if deck size is 0
     * @param deck vector of cards to test for size
     * @return true if deck is empty, false if deck has card(s)
     */
    bool deckEmpty(std::vector<ClassicCards> &);

    /**
     * Moves cards from pile (excluding top card) back to the deck
     * @param deck vector of cards in deck
     * @param pile vector of cards in pile
     */
    void refillDeck(std::vector<ClassicCards> &, std::vector<ClassicCards> &);

    /**
     * Fills hands of the player, opponent, then populates the deck 
     * @param user The player object to fill hand
     * @param bot the opponent object to fill hand
     */
    void readyGame(Player &, Opponent &);

    /**
     * Tests if all cards are in play
     * @param player to read card count in players hand
     * @param bot to read card count in bots hand
     * @param deck to read card count in deck
     * @return true if all cards are in play 
     */
    bool noMoreCards(std::vector<ClassicCards>, std::vector<ClassicCards>,
    std::vector<ClassicCards>);

 private:
    Player p;
    Opponent o;
    ClassicCards t, b, c, m;
};
#endif
