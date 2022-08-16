/*
Class: CPSC 2720
Coded by: Nicolas Crespo (n.crespo@uleth.ca), Javier S, Wyatt B.
Date: April 20, 2022
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../include/Uno.h"
#include "../include/Game.h"

Uno::Uno() {
  UnoPlayer p;
  UnoOpponent o;
  UnoCards t, b, c;
}

void Uno::gameStart() {
  readyGame(p, o);
  std::cout << "Welcome to UNO!" << std::endl;

  while (winner(p , o)) {
    std::cout << "This is the card on top of the pile" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << p.findName(p.pile.back().name) << " " <<
    p.findColour(p.pile.back().colour) << std::endl;
    std::cout << "-----------" << std::endl;
    p.checkHand(p.handArr);
    t = p.playCard(p.handArr);

      // PLAYER'S TURN

    if (compareCards(p.pile.back(), t) == false) {
      std::cout << " Invalid input, draw a card" << std::endl;
      p.drawCard(p.arrCard, p.handArr);
      p.handArr.push_back(t);
    } else {
      p.addToPile(t, p.pile);
      if (p.findName(p.pile.back().name) == "+ 2") {
        o.drawCard(p.arrCard, o.handArr);
        o.drawCard(p.arrCard, o.handArr);
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "     + 2 Cards Added to Oppponet     " << std::endl;
        std::cout << "-------------------------------------" << std::endl;
      }
      if (p.findName(p.pile.back().name) == "+4 Wild") {
        o.drawCard(p.arrCard, o.handArr);
        o.drawCard(p.arrCard, o.handArr);
        o.drawCard(p.arrCard, o.handArr);
        o.drawCard(p.arrCard, o.handArr);
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "     + 4 Cards Added to Oppponet     " << std::endl;
        std::cout << "-------------------------------------" << std::endl;
      }
      if (p.findName(p.pile.back().name) == "Reverse") {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "         Player Reversed Turns       " << std::endl;
        std::cout << "-------------------------------------" << std::endl;
      }
      if (p.findName(p.pile.back().name) == "Skip") {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "     Player Skipped Opponent Turn    " << std::endl;
        std::cout << "-------------------------------------" << std::endl;
          // SKIPPED TURN
          std::cout << "You Skipped your Opponent's Turn" << std::endl;
          std::cout << "You get to play again" << std::endl;
          std::cout << "This is the card on top of the pile" << std::endl;
          std::cout << "-----------" << std::endl;
          std::cout << p.findName(p.pile.back().name) << " " <<
          p.findColour(p.pile.back().colour) << std::endl;
          std::cout << "-----------" << std::endl;
          p.checkHand(p.handArr);
          t = p.playCard(p.handArr);

          if (compareCards(p.pile.back(), t) == false) {
            std::cout << " Invalid input, draw a card" << std::endl;
            p.drawCard(p.arrCard, p.handArr);
            p.handArr.push_back(t);
          } else {
            p.addToPile(t, p.pile);
            if (p.findName(p.pile.back().name) == "+ 2") {
              o.drawCard(p.arrCard, o.handArr);
              o.drawCard(p.arrCard, o.handArr);
              std::cout << "-------------------------------------" << std::endl;
              std::cout << "     + 2 Cards Added to Oppponet     " << std::endl;
              std::cout << "-------------------------------------" << std::endl;
            }
            if (p.findName(p.pile.back().name) == "+4 Wild") {
              o.drawCard(p.arrCard, o.handArr);
              o.drawCard(p.arrCard, o.handArr);
              o.drawCard(p.arrCard, o.handArr);
              o.drawCard(p.arrCard, o.handArr);
              std::cout << "-------------------------------------" << std::endl;
              std::cout << "     + 4 Cards Added to Oppponet     " << std::endl;
              std::cout << "-------------------------------------" << std::endl;
            }
            if (p.findName(p.pile.back().name) == "Reverse") {
              std::cout << "-------------------------------------" << std::endl;
              std::cout << "         Player Reversed Turns       " << std::endl;
              std::cout << "-------------------------------------" << std::endl;
            }
            if (p.findName(p.pile.back().name) == "Skip") {
              std::cout << "-------------------------------------" << std::endl;
              std::cout << "     Player Skipped Opponent Turn    " << std::endl;
              std::cout << "-------------------------------------" << std::endl;
            }
            // SKIPPED TURN ENDED
        }
      }
    }

    // OPPONENT'S TURN

    if (!(o.playCard(o.handArr, p.pile, c))) {
      std::cout << std::endl << "Opponent could not play card" <<
      std::endl << std::endl;
      o.drawCard(p.arrCard, o.handArr);
    } else {
      std::cout << std::endl << "Opponent card played" <<
      std::endl << std::endl;
      p.addToPile(c, p.pile);
      if (p.findName(p.pile.back().name) == "+ 2") {
        p.drawCard(p.arrCard, p.handArr);
        p.drawCard(p.arrCard, p.handArr);
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "     + 2 Cards Added to Player       " << std::endl;
        std::cout << "-------------------------------------" << std::endl;
      }
      if (p.findName(p.pile.back().name) == "+4 Wild") {
        p.drawCard(p.arrCard, p.handArr);
        p.drawCard(p.arrCard, p.handArr);
        p.drawCard(p.arrCard, p.handArr);
        p.drawCard(p.arrCard, p.handArr);
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "     + 4 Cards Added to Player       " << std::endl;
        std::cout << "-------------------------------------" << std::endl;
      }
      if (p.findName(p.pile.back().name) == "Reverse") {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "        Opponent Reversed Turns      " << std::endl;
        std::cout << "-------------------------------------" << std::endl;
      }
      if (p.findName(p.pile.back().name) == "Skip") {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "   Opponent Skipped Player's Turn    " << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "Your Opponent Skipped your Turn" << std::endl;
        std::cout << "They played again" << std::endl;
        // SKIPPED TURN
          if (!(o.playCard(o.handArr, p.pile, c))) {
            std::cout << std::endl << "Opponent could not play card" <<
            std::endl << std::endl;
            o.drawCard(p.arrCard, o.handArr);
          } else {
            std::cout << std::endl << "Opponent card played" <<
            std::endl << std::endl;
            p.addToPile(c, p.pile);
            if (p.findName(p.pile.back().name) == "+ 2") {
              p.drawCard(p.arrCard, p.handArr);
              p.drawCard(p.arrCard, p.handArr);
              std::cout << "-------------------------------------" << std::endl;
              std::cout << "     + 2 Cards Added to Player       " << std::endl;
              std::cout << "-------------------------------------" << std::endl;
            }
            if (p.findName(p.pile.back().name) == "+4 Wild") {
              p.drawCard(p.arrCard, p.handArr);
              p.drawCard(p.arrCard, p.handArr);
              p.drawCard(p.arrCard, p.handArr);
              p.drawCard(p.arrCard, p.handArr);
              std::cout << "-------------------------------------" << std::endl;
              std::cout << "     + 4 Cards Added to Player       " << std::endl;
              std::cout << "-------------------------------------" << std::endl;
            }
            if (p.findName(p.pile.back().name) == "Reverse") {
              std::cout << "-------------------------------------" << std::endl;
              std::cout << "        Opponent Reversed Turns      " << std::endl;
              std::cout << "-------------------------------------" << std::endl;
            }
            if (p.findName(p.pile.back().name) == "Skip") {
              std::cout << "-------------------------------------" << std::endl;
              std::cout << "   Opponent Skipped Player's Turn    " << std::endl;
              std::cout << "-------------------------------------" << std::endl;
      }
    }
  }
            // SKIPPED TURN ENDED
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

bool Uno::winner(UnoPlayer p, UnoPlayer o) {
  if (p.handArr.size() == 0 || o.handArr.size() == 0) {
    return false;
  } else {
    return true;
  }
}

void Uno::showWin(UnoPlayer p) {
  if (p.handArr.size() < 1) {
    std::cout << "You win!" << std::endl;
  }
}

void Uno::showWin(UnoOpponent p) {
  if (p.handArr.size() < 1) {
    std::cout << "You lose!" << std::endl;
  }
}

bool Uno::compareCards(UnoCards hand1, UnoCards hand2) {
  //compares card colour and name to determine sameness
  if (hand1.colour == hand2.colour || hand1.name == hand2.name) {
    return true;
  }
  return false;
}

bool Uno::deckEmpty(std::vector<UnoCards> &deck) {
  return deck.empty();
}

void Uno::refillDeck(std::vector<UnoCards> &deck,
std::vector<UnoCards> &pile) {
  std::cout << std::endl <<
  "Deck empty... moving cards from pile back into deck." << std::endl;
  UnoCards top;
  top = pile.back();
  pile.pop_back();
  deck = pile;
  pile.clear();
  pile.push_back(top);
}

void Uno::readyGame(UnoPlayer &user, UnoOpponent &bot) {
  user.populateDeck();
  user.populateHand(user.arrCard, user.handArr);
  bot.populateHand(user.arrCard, bot.handArr);
  user.drawCardTop(user.arrCard, user.pile);
}

bool Uno::noMoreCards(std::vector<UnoCards> unoplayer,
std::vector<UnoCards> bot, std::vector<UnoCards> deck) {
  int total = unoplayer.size() + bot.size();
  if (total == 50) {
    std::cout << "All cards are in players hands.";
    return true;
  }
  return false;
}
