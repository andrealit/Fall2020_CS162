/*********************************************************************
** Program Filename: Player.h
** Author: Andrea Tongsak
** Date: 10/16/2020
** Description: The header file for the Player class
** Input: -
** Output: -
*********************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "Hand.h"

using namespace std;

/**
 * Player header
 */ 
class Player {
    private:
        Hand hand;
        string name;
    public:
        // must have constructor, destructor, accessor methods, and mutator methods
        Player();
        ~Player();

        Hand get_hand();
        void set_hand(Hand input);

        string get_name();        
        void set_name(string input);

        // show the cards to the player
        void show_hand();

        // draw card
        void draw_card(Card card);

        // choose the card (and compare against top)
        Card choose_card(Card card);

        // select card
        int select_card();

};

#endif
