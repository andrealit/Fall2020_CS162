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

void Game::set_players(Player who, int i) {
    players[i] = who;
}

/**
 * Function: set_player_turn
 * Description: the player is sets
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
            set_players(players[j], j);
        }
    }

    cout << "Player 1 (YOU):" << endl;
    players[0].show_hand();

    cout << "Player 2 (COMP):" << endl;
    players[1].show_hand();

    // draw the top card for the pile: face up
    set_top(cards.deal_card());
}

/**
 * Function: print_top
 * Description: print out what is happening in the top card
 * Parameters: -
 * Pre-Conditions: What is happening in the game is unknown currently
 * Post-Conditions: top is printed
 */
void Game::print_top() {
    // the game is printed
    cout << "           TOP CARD IS: ";
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
 * Description: check that no one has won, and alternate turns
 * Parameters: -
 * Pre-Conditions: the player
 * Post-Conditions: Cards are dealt to both users
 */
void Game::turn() {
    bool gameOver = false;
    
    // 1. deck empty?
    if (cards.get_n_cards() == 0) {
        cout << "The deck is empty." << endl;
        check_win();
        gameOver = true;
    }
    
    do {
        // 3. switch player
        // player 0
        if (get_player_turn() % 2 == 0) {
            play_card(0);
            // 4. was the player's hand empty?
            gameOver = game_over(0);
            set_player_turn(1);
        } else { // player 1
            play_comp(1);
            gameOver = game_over(1);
            set_player_turn(0);
        }
    
    } while (gameOver == false);
    
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
 * Function: check_hand
 * Description: checking for the hand by comparing the card selection
 * Parameters: -
 * Pre-Conditions: We don't know if the player can move. We're assuming their hand isn't empty
 * Post-Conditions: The player has checked the hand to see if the cards are playable
 */
bool Game::check_hand(int user) {
    Card cardOut;
    bool inHand = false;
    
    // get the player object
    for (int i = 0; i < get_players(user).get_hand().get_n_cards(); i++) {
        cardOut = get_players(user).get_hand().card_at(i);
        inHand = cardOut.playable(get_top());
        if (inHand) {
            break;
        }
    }
    
    // does the hand have an object that is comparable?
    return inHand;
}

/**
* Function: draw_hand
* Description: drawing the hand by comparing the card selection
* Parameters: -
* Pre-Conditions:  There's no playable cards in the hand
* Post-Conditions: The hand has a playable card
*/
void Game::draw_hand(int user) {
    Card drawn;
    bool drawOver = false;
    int loc;
    
    // no playable cards in the hand

    do {
        if (cards.get_n_cards() == 0) {
            drawOver = true;
            check_win();
        }
        drawn = cards.deal_card();
        cout << "Drawn: ";
        drawn.toString();
        drawOver = drawn.playable(get_top());
        players[user].draw_card(drawn);
        set_players(players[user], user);
            
    } while (!drawOver);
    
    // when the draw is over, remove the last card
    loc = players[user].get_hand().get_n_cards();
    exit_hand(user, loc);
    // set the hand
    set_top(drawn);
}

/**
* Function: exit_hand
* Description: drawing the hand by comparing the card selection
* Parameters: -
* Pre-Conditions:  There's no playable cards in the hand
* Post-Conditions: The hand has a playable card
*/
void Game::exit_hand(int user, int location) {
    Card leave;
    
    // return the card that is leaving
    leave = players[user].remove_card(location);
    set_players(players[user], user);

}


/**
 * Function: play_card
 * Description: Allowing the user to select the card they wish to play
 * Parameters: player number
 * Pre-Conditions: Shuffled, the player number is passed
 * Post-Conditions: The card selected
 */
void Game::play_card(int player_num) {
    Player user = get_players(player_num);
    Card choice;
    
    cout << user.get_name() << "'s Turn: " << endl;
    
    // Does the user have a playable card in their hand?
    if (check_hand(player_num)) { // yes
        
        user.show_hand();

        // ask for selection
        choice = choose_card(get_top(), player_num);
        
        // CRAZY 8: computer randomly chooses suit
        if (choice.get_rank() == 7){
            choice.set_suit(choose_suit());
        }
        
        set_top(choice);
        
    } else { // no
        
        // Draw cards and increment hand
        // Check if card playable
        draw_hand(player_num);
    }
    
    print_top();
}

/**
 * Function: play_comp
 * Description: The computer makes a move
 * Parameters: the computer's index
 * Pre-Conditions: The cards are shuffled, the computer makes a move
 * Post-Conditions: The card selected
 */
void Game::play_comp(int player_num) {
    Player user = get_players(player_num);
    Card choice;

    cout << "Computer's turn." << endl;

    // Does the user have a playable card in their hand?
    if (check_hand(player_num)) { // yes
        
        user.show_hand();
        
        // let the computer play the first card in their hand
        for (int i = 0; i < user.get_hand().get_n_cards(); i++) {
            choice = user.get_hand().card_at(i);

            // compare the cards to see if playable
            if (choice.playable(get_top())) {
                cout << "Computer played card." << endl;
                exit_hand(player_num, i);
                set_top(choice);
                
                // CRAZY 8: computer randomly chooses suit
                if (choice.get_rank() == 7){
                    choice.set_suit(compRand8());
                }
                
                break;
            }

        }

    } else { // no
        
        // Draw cards and increment hand
        // Check if card playable
        draw_hand(player_num);
    }
    
    print_top();

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
    suit--;
    
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

/**
* Function: game_over
* Description: is the game over
* Parameters: -
* Pre-Conditions: We don't know if the game is over
* Post-Conditions: The game is over
*/
bool Game::game_over(int turn) {
    bool over = false;
    
    if (players[turn].get_hand().get_n_cards() == 0) {
        cout << players[turn].get_name() << "'s hand is empty!" << endl;
        cout << "Congrats, " << players[turn].get_name() << "!" << endl;
        over = true;
    }
    
    return over;
}


/**
 * Function: choose_card
 * Description: choose a card from the hand, ensures it's playable
 * Parameters: -
 * Pre-Conditions: The cards is not shown
 * Post-Conditions: The correct card is selected
 */
Card Game::choose_card(Card oldtop, int player_num) {
    Card remove;
    Card temp;
    int selection;
    Player user = get_players(player_num);
    
    do {
        // Is the selection a playable card?
        selection = select_card(player_num);
        temp = user.get_hand().card_at(selection);
        
        if (!(temp.playable(get_top()))) {
            cout << "Select a PLAYABLE card." << endl;
        } else {
            cout << "Playable." << endl;
        }
        
    } while (!(temp.playable(oldtop))); // repeat ask until it is correct

    // remove the card, update hand
    set_players(user, player_num);
    
    exit_hand(player_num, selection);
    temp.toString();
    get_players(player_num).get_hand().print_hand();
    
    return temp;
}


/**
 * Function: select_card
 * Description: select a card from the hand
 * Parameters: -
 * Pre-Conditions: The cards is not shown
 * Post-Conditions: The card is selected
 */
int Game::select_card(int player_num) {
    int userSelect;
    bool valid;
    string s;
    
    cout << "Select a card: 1 to " << get_players(player_num).get_hand().get_n_cards() << endl;

    do {
        getline(cin, s);
        userSelect = atoi(s.c_str());
        
        // check if the selection is within the correct range
        if (userSelect < 1 || userSelect > get_players(player_num).get_hand().get_n_cards()) {
            cout << "Incorrect input." << endl;
            valid = false;
        } else {
            valid = true;
        }
    } while (valid == false);
    
    // the index for the cards will be returned
    return (userSelect-1);
}