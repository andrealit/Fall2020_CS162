#include <iostream>
using namespace std;

#include "hand.h"

// constructor
Hand::Hand() {
    // do nothing
    this->cards = NULL;
    this->n_cards = 0;
}

// destructor
Hand::~Hand() {
    // only delete if we have stuff on the heap
    if (this->cards != NULL) {
        delete[] this->cards;
    }
    cards = NULL;
}

// copy constructor
Hand::Hand(const Hand& old_hand) {
    // set the number of cards to the old hand
    this->n_cards = old_hand.n_cards;

    // create a new Card object
    cards = new Card[n_cards];

    // a loop to assign the old hards to the new hand
    for (int i = 0; i < n_cards; i++) {
        cards[i] = old_hand.cards[i];
    }
}

// assignment operator overload
Hand& Hand::operator= (const Hand& old_hand) {

    // add: a null pointer check
    if (cards != nullptr) {
        cout << "Dynamic array is present." << endl;
        delete[] cards;
    }

    // set the number of cards to the old hand
    this->n_cards = old_hand.n_cards;

    // create a new Card object
    cards = new Card[n_cards];

    // a loop to assign the old hards to the new hand
    for (int i = 0; i < n_cards; i++) {
        cards[i] = old_hand.cards[i];
    }
    return *this;
}

/*
* Function: get_n_cards
* Description: Get n cards
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
int Hand::get_n_cards() {
    return this->n_cards;
}

/*
* Function: set_n_cards
* Description: Set n cards
* Parameters: int
* Pre-Conditions: -
* Post-Conditions: -
 */
void Hand::set_n_cards(int input) {
    this->n_cards = input;
}

/*
* Function: get_cards
* Description: Get n cards
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Card* Hand::get_cards() {
    return this->cards;
}
