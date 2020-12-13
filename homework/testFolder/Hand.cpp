/*********************************************************************
** Program Filename: Hand.cpp
** Author: Andrea Tongsak
** Date: 10/16/2020
** Description: The file with Hand header file initialization
** Input: -
** Output: - 
*********************************************************************/

#include "Hand.h"

#include <iostream>
#include <string>

using namespace std;

/*
* Function: Constructor
* Description: Creates the hand
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Hand::Hand() {
    // do nothing
    this->cards = NULL;
    this->n_cards = 0;
}

/*
* Function: Destructor
* Description: The destructor deletes the hand object
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Hand::~Hand() {
    // only delete if we have stuff on the heap
    if (this->cards != NULL) {
        delete[] this->cards;
    }
    cards = NULL;
}

/*
* Function: Copy constructor
* Description: the constructor copies over information
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
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

/*
* Function: assignment operator overload
* Description: overloads the memory to be dynamic
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Hand& Hand::operator= (const Hand& old_hand) {

    // add: a null pointer check
    if (cards != NULL) {
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
* Function: cards
* Description: Get n cards
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Card* Hand::get_cards() {
    return this->cards;
}

/*
* Function: add_cards
* Description: creates a new array one size larger, then copies over the current hand to the next
* Parameters: Card
* Pre-Conditions: The necessary card is not added to the hand
* Post-Conditions: The card is added to the hand
 */
void Hand::add_cards(Card card) {
    // increase size of hand
    n_cards++;

    if (get_n_cards() == 1) {
        cards = new Card[1]; 

        cards[0].set_rank(card.get_rank());
        cards[0].set_suit(card.get_suit());
    } else {
        // create a new array
        Card *temp = new Card[get_n_cards()];

        // assign the cards to rank and suit
        for (int i = 0; i < get_n_cards(); i++) {
            // if the element is at the last place
            if (i == (get_n_cards()-1)) {
                // make a new card
                temp[i].set_rank(card.get_rank());
                temp[i].set_suit(card.get_suit());
            } else {
                temp[i] = cards[i];
            }
        }

        // delete the old array 
        delete[] cards;
        cards = temp;
        temp = NULL;
    }

    cout << "The number of cards:" << get_n_cards() << endl;
} 

/*
* Function: remove_cards
* Description: remove cards by location index
* Parameters: Card
* Pre-Conditions: The card is not removed from the hand
* Post-Conditions: The card is removed from the hand
 */
Card Hand::remove_cards(int location) {
    bool cardFound = false;
    Card cardRemoved;

    cout << "Remove ";
    cards[location].toString();
    cout << endl;

    // checking if the array is empty
    if (get_n_cards() == 0) {
        cout << "The hand is empty! Can't remove card." << endl;
    } else {
        // create a new array of the size
        Card *temp = new Card[get_n_cards()-1];

        cout << "Hand size: " << get_n_cards() << endl;

        for (int i = 0; i < get_n_cards()-1; i++) {

            // look for the card
            if (i == location) {
                cout << "We found the card!" << endl;
                cardFound = true;
                // remove the card
                cardRemoved = cards[location];
            }
            
            if (cardFound) {
                temp[i] = cards[i+1]; // need to iterate over the bad card
            } else {
                temp[i] = cards[i]; // set as normal
            }
        }

        delete[] cards;
        cards = temp;
        temp = NULL;
    }

    // remove one card to the number of cards in the hand
    set_n_cards(get_n_cards() - 1);

    return cardRemoved;
}


/*
* Function: card_at
* Description: return the cards at the index
* Parameters: Card
* Pre-Conditions: The card is not returned from the hand
* Post-Conditions: The card is returned from the hand
 */
Card Hand::card_at(int location) {
    bool cardFound = false;
    Card cardAt;

    // checking if the array is empty
    if (get_n_cards() == 0) {
        cout << "The hand is empty! Can't remove card." << endl;
    } else {
        // create a new array of the size
        Card *temp = new Card[get_n_cards()-1];

        for (int i = 0; i < get_n_cards()-1; i++) {
            // look for the card
            if (i == location) {
                cardFound = true;
                cardAt = cards[location];
            }
        }

    }

    return cardAt;
}


/*
* Function: print_hand
* Description: print
* Parameters: -
* Pre-Conditions: The card is not removed from the hand
* Post-Conditions: The card is added to the hand
 */
void Hand::print_hand() {
    cout << "Printing out a hand of " << get_n_cards() << " cards." << endl;
    for (int i = 0; i < get_n_cards(); i++) {
        cout << "Card: " << i + 1 << " ";
        cards[i].toString();
    }
}

/*
* Function: empty_hand
* Description: is the hand empty
* Parameters: -
* Pre-Conditions: We don't know if the hand is empty or not
* Post-Conditions: We know if the hand is empty
 */
bool Hand::empty_hand() {
    bool hand = false;

    if (get_n_cards() == 0) {
        hand = true;
    }
    
    return hand;
}






