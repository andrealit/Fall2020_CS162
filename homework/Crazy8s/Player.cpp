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
    return hand;
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
 * Post-Conditions: The card is drawn into the player
 */
void Player::draw_card(Card card) {
    // add the card to the deck
    (this->hand).add_cards(card);
}

/**
* Function: remove_card
* Description: remove the cards from the deck
* Parameters: -
* Pre-Conditions: The cards from the deck aren't removed
* Post-Conditions:
*/
Card Player::remove_card(int card) {
    // remove the card from the deck
    return (this->hand).remove_cards(card);
}

