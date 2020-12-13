/******************************************************
** Program: crazyeights.cpp
** Author: Andrea Tongsak
** Date: 10/18/2020
** Description: The file with eights
** Input: -
** Output: -
******************************************************/

#include <iostream>
#include <string>

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Game.h"

using namespace std;

/*
* Function: main
* Description: processes files and starts sort
* Parameters: command line arguments
* Pre-Conditions: the command line is passed
* Post-Conditions: this will return the program abilities
*/
int main (int argc, char* argv[]) {
    
    // welcome the user
    cout << "Welcome! The card game is starting." << endl;

    // initialize the game with 52 cards and 2 players
    Game* testGame = new Game();

    // shuffles and deals the cards
    testGame->deal_cards();

    // prints out the pile
    testGame->print_top();

    // set the player's turns
    testGame->set_player_turn(0);

    // the turn
    testGame->turn();
    
    return 0;
}
