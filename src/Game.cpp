/*
Class: CPSC 2720
Coded by: Wyatt Bristow (Wyatt.Bristow@uleth.ca),
Date: April 16, 2022
*/
#include <iostream>
#include <vector>
#include <string>
#include "../include/Game.h"
#include "../include/CrazyEights.h"
#include "../include/Uno.h"
//  Constructor
Game::Game() {
}

//Choose which game to load
void Game::chooseGame() {
    std::string game1 = "Crazy Eights";
    std::string game2 = "Uno";
    int input = 0;
    std::cout << "What game would you like to play?" << std::endl;
    std::cout << "Input the number value of the game you would like to play." <<
    std::endl;
    std::cout << "1. " << game1 << std::endl;
    std::cout << "2. " << game2 << std::endl;
    std::cin >> input;
    if (input == 1) {
        CrazyEights c;
        c.gameStart();
    } else if (input == 2) {
        Uno u;
        u.gameStart();
    }
}
