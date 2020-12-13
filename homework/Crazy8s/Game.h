/*********************************************************************
** Program Filename: Game.h
** Author: Andrea Tongsak
** Date: 10/18/2020
** Description: The Game header file
** Input: -
** Output: -
*********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include "Deck.h"
#include "Player.h"
#include "Card.h"

using namespace std;

/**
 * Game header
 */
class Game {
    private:
        Deck cards;
        Player players[2];
        int player_turn;

        // the top discard pile of cards
        Card top;

    public:
        // constructors
        Game();
        // destructor
        ~Game();

        // getters and setters
        Deck& get_cards();
        Player get_players(int);
        void set_players(Player, int);

        void set_player_turn(int);
        int get_player_turn();
        
        // 52 cards are dealt out, seven to each player, and the top card is set
        void deal_cards();

        // print the status of the game
        void print_top();

        // get the pile
        Card get_top();

        // set the card
        void set_top(Card);

        // card that is the next one in the stock then set it to the pile
        Card getCard(int);

        // turn in the game
        void turn();

        // welcome message to the user
        void welcome_user(string);

        // returns if the correct card is in the hand
        bool check_hand(int);
    
        // draw the card when there's none in hand
        void draw_hand(int);
    
        // calls in order to leave the hand
        void exit_hand(int, int);

        // allow the user to play the card for a user's turn
        void play_card(int);

        // the computer makes a move
        void play_comp(int player_num);

        // check the win
        void check_win();

        // let the user choose the suit
        int choose_suit();

        // let the computer randomly choose
        int compRand8();

        // play again message?
        void play_again_option();
    
        // the game is over, so returns a bool
        bool game_over(int);
    
        // choose the card (and compare against top)
        Card choose_card(Card card, int player_num);

        // select card
        int select_card(int player_num);
};

#endif