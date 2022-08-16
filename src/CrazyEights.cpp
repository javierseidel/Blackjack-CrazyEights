/*
Class: CPSC 2720
Coded by: Wyatt Bristow (Wyatt.Bristow@uleth.ca),
Date: April 16, 2022
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../include/CrazyEights.h"
#include "../include/Game.h"



CrazyEights::CrazyEights() {
  Player p;
  Opponent o;
  ClassicCards t, b, c;
}

void CrazyEights::gameStart() {
  readyGame(p, o);
  std::cout << "Welcome to Crazy Eights!" << std::endl;

  while (winner(p , o)) {
    std::cout << "This is the card on top of the pile" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << p.findName(p.pile.back().name) << " of " <<
    p.findSuit(p.pile.back().suit) << std::endl;
    std::cout << "-----------" << std::endl;
    p.checkHand(p.handArr);
    t = p.playCard(p.handArr);

    if (compareCards(p.pile.back(), t) == false) {
      std::cout << " Invalid input, draw a card" << std::endl;
      p.drawCard(p.arrCard, p.handArr);
      p.handArr.push_back(t);
    } else {
      p.addToPile(t, p.pile);
    }

    if (!(o.playCard(o.handArr, p.pile, c))) {
      std::cout << std::endl << "Opponent could not play card" <<
      std::endl << std::endl;
      o.drawCard(p.arrCard, o.handArr);
    } else {
      std::cout << std::endl << "Opponent card played" <<
      std::endl << std::endl;
      p.addToPile(c, p.pile);
    }
    o.checkHand(o.handArr);
    std::cout << std::endl << p.arrCard.size() << std::endl;
    std::cout << "-----------End of turn -----------" << std::endl;
    showWin(p);
    showWin(o);
    if (deckEmpty(p.arrCard)) {
      refillDeck(p.arrCard, p.pile);
    }
    if (noMoreCards(p.handArr, o.handArr, p.arrCard)) {
      break;
    }
  }
}

bool CrazyEights::winner(Player p, Player o) {
  if (p.handArr.size() == 0 || o.handArr.size() == 0) {
    return false;
  } else {
    return true;
  }
}

void CrazyEights::showWin(Player p) {
  if (p.handArr.size() < 1) {
    std::cout << "You win!" << std::endl;
  }
}

void CrazyEights::showWin(Opponent p) {
  if (p.handArr.size() < 1) {
    std::cout << "You lose!" << std::endl;
  }
}

bool CrazyEights::compareCards(ClassicCards hand1, ClassicCards hand2) {
  //compares card suit and name to determine sameness
  if (hand1.suit == hand2.suit || hand1.name == hand2.name) {
    return true;
  }
  return false;
}

bool CrazyEights::deckEmpty(std::vector<ClassicCards> &deck) {
  return deck.empty();
}

void CrazyEights::refillDeck(std::vector<ClassicCards> &deck,
std::vector<ClassicCards> &pile) {
  std::cout << std::endl <<
  "Deck empty... moving cards from pile back into deck." << std::endl;
  ClassicCards top;
  top = pile.back();
  pile.pop_back();
  deck = pile;
  pile.clear();
  pile.push_back(top);
}

void CrazyEights::readyGame(Player &user, Opponent &bot) {
  user.populateDeck();
  user.populateHand(user.arrCard, user.handArr);
  bot.populateHand(user.arrCard, bot.handArr);
  user.drawCardTop(user.arrCard, user.pile);
}

bool CrazyEights::noMoreCards(std::vector<ClassicCards> player,
std::vector<ClassicCards> bot, std::vector<ClassicCards> deck) {
  int total = player.size() + bot.size();
  if (total == 50) {
    std::cout << "All cards are in players hands.";
    return true;
  }
  return false;
}
