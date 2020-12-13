/*********************************************************************
** Program Filename: Game.cpp
** Author: Andrea Tongsak
** Date: 10/17/2020
** Description: Game class has the functions and constructors for gameplay of Crazy 8s
** Input: -
** Output:
*********************************************************************/

#include <iostream>
#include <string>

#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"

using namespace std;

const int NUM_CARDS = 52;
const int NUM_RANK = 13;
const int NUM_SUIT = 4;
const int HAND = 7;

/**
 * Function: Game Constructor
 * Description: Default constructor for the Game
 * Parameters: -
 * Pre-Conditions: The Game object is not yet created
 * Post-Conditions: Create two players (one with input name, other computer), and shuffle the deck
 */
Game::Game() {
    string playerName;

    cout << "Enter your name: ";
    
    getline(cin, playerName);

    players[0].set_name(playerName);
    players[1].set_name("Computer");

    welcome_user(playerName);

    cards.create_deck();
}

/**
 * Function: Game Destructor
 * Description: Default destructor for Menu
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
Game::~Game() {
    // delete the memory
}

/**
 * Function: get_cards
 * Description: accessor for cards
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
Deck& Game::get_cards() {
    // this is the deck that results in cards
    return this->cards;
}

/**
 * Function: get_players
 * Description: accessor for players
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
Player Game::get_players(int i) {
    return players[i];
}

/**
 * Function: set_player_turn
 * Description: the player is set
 * Parameters: -
 * Pre-Conditions: Cards aren't dealt to either user yet
 * Post-Conditions: Cards are dealt to both users
 */
void Game::set_player_turn(int turn) {
    this->player_turn = turn;
}

/**
 * Function: get_player_turn
 * Description: each player gets seven cards at the beginning, and the top card is flipped
 * Parameters: -
 * Pre-Conditions: Cards aren't dealt to either user yet
 * Post-Conditions: Cards are dealt to both users
 */
int Game::get_player_turn() {
    return this->player_turn;
}

/**
 * Function: deal_cards
 * Description: shuffles deck, deals seven cards to each player, flips top card
 * Parameters: -
 * Pre-Conditions: Cards aren't dealt to either user yet
 * Post-Conditions: Cards are dealt to both users
 */
void Game::deal_cards() {
    // shuffle the cards
    cards.shuffle_deck();

    cout << "Dealing cards to you and computer..." << endl;
    // deal seven cards to the user and the computer
    for (int i = 0; i < HAND; ++i) {
        for (int j = 0; j < 2; ++j) {
            players[j].draw_card(cards.deal_card());
        }
    }

    cout << "Player 1:" << endl;
    players[0].show_hand();

    cout << "Player 2:" << endl;
    players[1].show_hand();

    // draw the top card for the pile: face up
    set_top(cards.deal_card());
}

/**
 * Function: print_game
 * Description: print out what is happening in the game 
 * Parameters: -
 * Pre-Conditions: What is happening in the game is unknown currently
 * Post-Conditions: Cards are printed
 */
void Game::print_game() {
    // the game is printed
    cout << "TOP CARD IS:" << endl;
    get_top().toString();

}

/**
 * Function: get_top
 * Description: The top card that the user must match to
 * Parameters: -
 * Pre-Conditions: 
 * Post-Conditions: Cards are dealt to both users
 */
Card Game::get_top() {
    return this->top;
}

/**
 * Function: set_top
 * Description: each card has a pile 
 * Parameters: -
 * Pre-Conditions: Cards aren't dealt to either user yet
 * Post-Conditions: Cards are dealt to both users
 */
void Game::set_top(Card flip) {
    this->top = flip;
}

/**
 * Function: turn
 * Description: each player has a turn 
 * Parameters: -
 * Pre-Conditions: the player 
 * Post-Conditions: Cards are dealt to both users
 */
void Game::turn(Player user) {
    bool doneDeck = false;

    // check if the deck is empty
    if (cards.get_n_cards() == 0) {
        cout << "The deck is empty." << endl;
    }

    

    // check are the cards playable?
    if (doneDeck == false) {
        cout << "Game over, checking for who won." << endl;
    }
}

/**
 * Function: welcome_user
 * Description: welcome
 * Parameters: -
 * Pre-Conditions: The user is not welcomed
 * Post-Conditions: Print statement introduces user to the rules
 */
void Game::welcome_user(string name) {
    // reference: https://bicyclecards.com/how-to-play/crazy-eights/
    cout << "Welcome to Crazy 8s, " << name << "!" << endl;
    cout << "There are 52 cards in a deck." << endl;
    cout << "Object of the game: Be the first player to get rid of all the cards in your hand." << endl;
    cout << "You will be playing against the computer." << endl;
    cout << endl;
}

/**
 * Function: prompt_computer
 * Description: background processes for calculating the computer's move
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
void Game::play_game() {
    bool foundWinner = false;

    // while (foundWinner == false) {

    // }
}

/**
 * Function: check_hand
 * Description: checking for the hand by comparing the card selection 
 * Parameters: -
 * Pre-Conditions: We don't know if the player can move. We're assuming their hand isn't empty
 * Post-Conditions: The player has checked the hand to see if the cards are playable
 */
bool Game::check_hand(Player play) {
    Card cardOut;
    Card drawn;
    bool isPlayable = false;
    bool drawOver = false;
    bool inHand = false;

    // check through the entire hand, and see if ANY card is playable
    for (int i = 0; i < play.get_hand().get_n_cards(); i++) {
        cardOut = play.get_hand().card_at(i);
        isPlayable = get_top().playable(cardOut);
        if (isPlayable) {
            inHand = true;
            break;
        }
    }

    // if there is no card in the hand that is playable
    // keep drawing until the drawn card matches the top and put the card down.
    if (!isPlayable) {
        inHand = false;
        do {
            cout << "There is no card in your hand that is playable." << endl;
            cout << "Drawing cards..." << endl;
            // make sure the deck isn't empty
            if (cards.get_n_cards() == 0) {
                // if the deck is empty, then check for win by hands
                drawOver = true;
            }
            drawn = cards.deal_card();
            drawn.toString();
            drawOver = get_top().playable(drawn);
            play.draw_card(drawn);
            cout << "Num cards" << play.get_hand().get_n_cards() << endl;
        } while (!drawOver);
    }

    return inHand;
}

/**
 * Function: play_card
 * Description: Allowing the user to select the card they wish to play
 * Parameters: player
 * Pre-Conditions: Shuffled, we know there is a playable card
 * Post-Conditions: The card selected
 */
void Game::play_card(int player_num) {
    Card choice;
    int last;
    Player user = get_players(player_num);
    
    Card c1 = cards.deal_card();

    get_players(0).get_hand().add_cards(c1);

    cout << "Number of cards in hand: " << this->get_players(player_num).get_hand().get_n_cards() << endl;

    // show the player's hand
    user.show_hand();

    // If the HAND had a match
    if (check_hand(user)) {
        // allow user to select the correct card
        choice = user.choose_card(get_top());

        // CRAZY 8: let the human player select suit
        if (player_num == 0 && choice.get_rank() == 7){
            choice.set_suit(choose_suit());
        }

        // then set to top card
        set_top(choice);
        
    } else { // we needed to draw
        // need to set the index to the last card in our hand array
        last = user.get_hand().get_n_cards() - 1;
        set_top(user.get_hand().remove_cards(last));
    }
    
}

/**
 * Function: play_comp
 * Description: The computer makes a move
 * Parameters: -
 * Pre-Conditions: The cards are shuffled, the computer makes a move
 * Post-Conditions: The card selected
 */
void Game::play_comp(int player_num) {
    Card choice;
    int last;
    Player user = get_players(player_num);

    cout << "Computer turn." << endl;

    // check the hand to make sure that the cards match
    if (check_hand(user)) {
        // let the computer play the first card that is playable in their hand.
        for (int i = 0; i < players[player_num].get_hand().get_n_cards(); i++) {
            choice = players[player_num].get_hand().card_at(i);

            // compare the cards to see if playable
            if (get_top().playable(choice)) {
                cout << "" << endl;
            }

            // CRAZY 8: computer randomly chooses suit
            if (player_num == 0 && choice.get_rank() == 7){
                choice.set_suit(compRand8());
            }
        }

    } else { // else draw
        // need to set the index to the last card in our hand array
        last = user.get_hand().get_n_cards() - 1;
        set_top(user.get_hand().remove_cards(last));
    }

}

/**
 * Function: choose_suit
 * Description: Allowing the user to select the card they wish to play
 * Parameters: -
 * Pre-Conditions: The cards is shuffled, we know there is a playable card
 * Post-Conditions: The card selected
 */
int Game::choose_suit() {
    bool valid;
    string s;
    int suit;

    cout << "Choose a suit. Select (1) Diamonds, (2) Hearts, (3) Spades, (4) Clubs: " << endl;
    do {
        getline(cin, s);
        suit = atoi(s.c_str());
        if (suit < 1 || suit > 4) {
            cout << "Try again." << endl;
            valid = false;
        } else {
            valid = true;
        }
    } while (valid == false);
    suit - 1;
    
    return suit;
}


/**
 * Function: compRand8
 * Description: the computer randomly selects a suit 
 * Parameters: -
 * Pre-Conditions: the suit when an 8 occurs does not appear
 * Post-Conditions: the suit is given
 */
int Game::compRand8() {
    int suit;
    srand(time(NULL));
    suit = rand() % NUM_SUIT;

    switch (suit) {
        case 0:
            cout << "New Suit: Diamonds" << endl;
        case 1:
            cout << "New Suit: Hearts" << endl;
        case 2:
            cout << "New Suit: Spades" << endl;
        case 3:
            cout << "New Suit: Clubs" << endl;
    }

    return suit;
}

/**
 * Function: check_win
 * Description: checking for the win by comparing two players
 * Parameters: -
 * Pre-Conditions: The game is still ongoing
 * Post-Conditions: -
 */
void Game::check_win() {
    Player p1 = players[0];
    Player p2 = players[1];

    // case one: human wins
    if (p1.get_hand().get_n_cards() < p2.get_hand().get_n_cards()) {
        cout << p1.get_name() << " wins!" << endl;
    }
    // case two: computer wins
    if (p1.get_hand().get_n_cards() > p2.get_hand().get_n_cards()) {
        cout << p2.get_name() << " wins!" << endl;
    }
    // case three: the cards are equal
    if (p1.get_hand().get_n_cards() == p2.get_hand().get_n_cards()) {
        cout << "Tie." << endl;
    }
}