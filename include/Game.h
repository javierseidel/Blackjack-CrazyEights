/*
Class: CPSC 2720
Coded by: Wyatt Bristow (Wyatt.Bristow@uleth.ca),
Date: April 16, 2022
*/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include "ClassicCards.h"
#include "Opponent.h"
#include "Player.h"
#include "UnoCards.h"
#include "UnoOpponent.h"
#include "UnoPlayer.h"

class Game {
 public:
    /**
     * Game constructor
     */
    Game();

    /**
     * Outputs choice of games to terminal for user to choose from
     * User determines what game to play with inputting corresponding integer value assigned to game
     * @return string of what game the user chose to play
     */
    void chooseGame();

    std::string gameType;
    // True during gameplay, false when winner is determined
    bool gameState = false;
};
#endif
