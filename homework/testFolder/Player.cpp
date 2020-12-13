/*********************************************************************
** Program Filename: Player.cpp
** Author: Andrea Tongsak
** Date: 10/16/2020
** Description: The file with the Player instantiation
** Input: -
** Output: - 
*********************************************************************/

#include "Player.h"

#include <iostream>
#include <string>

using namespace std;

const int NUM_RANK = 13;
const int NUM_SUIT = 4;

/**
 * Function: Player Constructor
 * Description: Default constructor for Player
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
Player::Player() {
    // using the default
}

/**
 * Function: Player Destructor
 * Description: Default destructor for Player
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
Player::~Player() {
    // The player object is destroyed
}

/**
 * Function: get_hand()
 * Description: the accessor for the hand
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
Hand Player::get_hand() {
    // the player object is returned
    return this->hand;
}

/**
 * Function: set_hand()
 * Description: the mutator for the hand
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
void Player::set_hand(Hand input) {
    // the player object is returned
    this->hand = input;
}

/**
 * Function: get_name()
 * Description: the accessor for the hand
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
string Player::get_name() {
    // the player object is returned
    return this->name;
}

/**
 * Function: set_name()
 * Description: the mutator for the hand
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
void Player::set_name(string nm) {
    // the player object is returned
    this->name = nm;
}

/**
 * Function: show_cards
 * Description: releasing the cards in the hand
 * Parameters: -
 * Pre-Conditions: The hand is not shown
 * Post-Conditions: The hand is shown
 */
void Player::show_hand() {
    (this->hand).print_hand();
}

/**
 * Function: draw_card
 * Description: draw the cards from the deck
 * Parameters: -
 * Pre-Conditions: The cards from the deck aren't drawn
 * Post-Conditions: 
 */
void Player::draw_card(Card card) {
    // add the card to the deck
    (this->hand).add_cards(card);
}

/**
 * Function: choose_card
 * Description: choose a card from the hand, ensures it's playable
 * Parameters: -
 * Pre-Conditions: The cards is not shown
 * Post-Conditions: The correct card is selected
 */
Card Player::choose_card(Card oldtop) {
    Card temp;
    int selection;

    // let the user select which card they want to play
    // continue asking until the selection is playable

    cout << "Choose a playable card." << endl;
    // check if playable
    do {
        selection = select_card();
        temp = hand.card_at(selection);
        
    } while (!(temp.playable(oldtop)));

    // remove the card
    temp = hand.remove_cards(selection);
    temp.toString();

    return temp;
}

/**
 * Function: select_card
 * Description: select a card from the hand
 * Parameters: -
 * Pre-Conditions: The cards is not shown
 * Post-Conditions: The card is selected
 */
int Player::select_card() {
    int userSelect;
    bool valid;
    string s;
    
    cout << "Select a card: 1 to " << hand.get_n_cards() << endl;

    do {
        getline(cin, s);
        userSelect = atoi(s.c_str());
        
        // check if the selection is within the correct range
        if (userSelect < 1 || userSelect > hand.get_n_cards()) {
            cout << "Incorrect input." << endl;
            valid = false;
        } else {
            valid = true;
        }
    } while (valid == false);
    
    // the index for the cards will be returned
    return (userSelect-1);
}
