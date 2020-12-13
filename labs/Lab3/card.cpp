#include <iostream>
#include "card.h"

using namespace std;

/**
 * Card Constructor 
 * Parameter: 0
 * 
**/
Card::Card() {
    this->suit = 0;
    this->rank = 0;
}

/**
 * Card Constructor 
 * Parameter: suit, rank
 * 
**/
Card::Card(int suit, int rank) {
    this->suit = suit;
    this->rank = rank;
}

/**
 * Destructor for Card
**/
Card::~Card() {
    // delete the information
}

/**
 * Suit must be diamonds, clubs, hearts, or spades. (1-4)
 */ 
void Card::set_suit(int name) {
    this->suit = name;
}

/**
 * Rank must be 1 to 13
 */ 
void Card::set_rank(int name) {
    this->rank = name;
}

/**
 * Accessor for the suit
 */ 
int Card::get_suit() {
    return this->suit;
}

/**
 * Accessor for the rank
 */ 
int Card::get_rank() {
    return this->rank;
}






