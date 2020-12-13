/*********************************************************************
** Program Filename: Hand.h
** Author: Andrea Tongsak
** Date: 10/16/2020
** Description: The file with employee struct and hour
** Input: -
** Output: -
*********************************************************************/
#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <string>

#include "Card.h"

using namespace std;

/**
 * Hand header
 */ 
class Hand {
    private:
        Card* cards;    // this is a pointer
        int n_cards;    
    public:
        // constructor
        Hand();
        // destructor
        ~Hand();
        // copy constructor
        Hand(const Hand&);
        // assignment operator overload
        Hand& operator= (const Hand&);

        // n cards accessors and mutators
        int get_n_cards();
        void set_n_cards(int);

        // cards accessors and mutators
        Card* get_cards();

        // add cards to the hand
        void add_cards(Card);

        // remove cards by index
        Card remove_cards(int);

        // return card at index
        Card card_at(int);

        // print the hand
        void print_hand();

        // check if hand is empty
        bool empty_hand();
};

#endif