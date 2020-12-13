/*********************************************************************
** Program Filename: Deck.h
** Author: Andrea Tongsak
** Date: 10/16/2020
** Description: The file with deck header
** Input:
** Output:
*********************************************************************/

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
 
#include "Card.h"

using namespace std;

class Deck {
    private:
        Card deck[52];
        int n_cards;    // Number of cards remaining in the deck
    public:
    // must have constructors, destructor, accessor methods, and mutator methods
        Deck();
        ~Deck();

        // accessors and mutators
        Card get_deck();

        int get_n_cards();
        void set_n_cards(int num);

        // this builds the deck with 52 cards
        void create_deck();
        
        // this shuffles the deck
        void shuffle_deck();

        // helper function: bubble sort for shuffle
        void swap_cards(Card, int, int);

        // deal a card from the deck
        Card deal_card();

        // print out the deck
        void print_deck();
    
};

#endif
