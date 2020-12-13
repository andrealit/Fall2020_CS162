/*********************************************************************
** Program Filename: Card.h
** Author: Andrea Tongsak
** Date: 10/16/2020
** Description: The header file for the Card class
** Input: -
** Output: -
*********************************************************************/

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

/**
 * Card header
 */
class Card {
    private:
        int rank;   // Should be in the range 0-12
        int suit;   // Should be in the range 0-3

        // 1 = the "stock"
        // 2 = the "pile"
        // 3 = the computer hand
        // 4 = the player hand

    public:
        // constructors
        Card();
        Card(int, int);
        ~Card();

        // accessors and mutators
        int get_rank();
        void set_rank(int);

        int get_suit();
        void set_suit(int);
        // show the card
        void show_card();

        // is the card playable, matches the suit or the rank of the top card
        bool playable(Card *faceup);

        // is the card playable, matches the suit or the rank of the top card
        bool playable(Card faceup);

        // replace the card
        void replace_card(Card *topcard);

        // return a string format of the card
        void toString();

        // display the art form of card
        void artCard();

};

#endif

