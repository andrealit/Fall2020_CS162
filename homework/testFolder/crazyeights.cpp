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

    // Hand* testHand = new Hand();

    // testHand->add_cards(testDeck->deal_card());
    // testHand->add_cards(testDeck->deal_card());
    // testHand->add_cards(testDeck->deal_card());
    // Card c1 = testDeck->deal_card();
    // testHand->add_cards(c1);

    // testHand->print_hand();

    // cout << "Removed card..." << endl;
    // Card removed = testHand->remove_cards(0);

    // removed.toString();

    // Deck* testDeck = new Deck();


    // Player* testPlay = new Player();

    // testPlay->draw_card(testDeck->deal_card());
    // testPlay->draw_card(testDeck->deal_card());
    // testPlay->draw_card(testDeck->deal_card());
    // testPlay->draw_card(testDeck->deal_card());

    // testPlay->show_hand();

    // cout << "Removed card..." << endl;
    // Card r1 = testPlay->choose_card();
    // testPlay->check_win();
    // Card r2 = testPlay->choose_card();
    // testPlay->check_win();
    // Card r3 = testPlay->choose_card();
    // testPlay->check_win();
    // Card r4 = testPlay->choose_card();
    // testPlay->check_win();
    // Card temp = testPlay->choose_card();

    // // temp.toString();

    // testPlay->show_hand();

    // initialize the game with 52 cards and 2 players
    Game* testGame = new Game();

    Deck* testDeck = new Deck();

    // shuffles and deals the cards
    testGame->deal_cards();

    testGame->print_game();

    if (testGame->check_hand(testGame->get_players(0))) {
        cout << "Yay!" << endl;
    }

    // Card c1 = testDeck->deal_card();
    // cout << "Drew a card" << endl;
    // // IMPORTANT, must use "DRAW_CARD" instead of add cards
    // testGame->get_players(0).get_hand().add_cards(c1);
    // testGame->get_players(0).draw_card(c1);
    // testGame->get_players(0).get_hand().get_n_cards();

    Card pile = testGame->get_top();
    
    testGame->play_card(0);

    testGame->print_game();

    
    return 0;
}