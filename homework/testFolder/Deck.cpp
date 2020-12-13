/*********************************************************************
** Program Filename: Deck.cpp
** Author: Andrea Tongsak
** Date: 10/16/2020
** Description: The file with the declaration for the deck class
** Input: 
** Output:
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>

#include "Deck.h"

using namespace std;

const int NUM_CARDS = 52;
const int NUM_RANK = 13;
const int NUM_SUIT = 4;

/*
* Function: Deck Constructor
* Description: Default constructor for Deck
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Deck::Deck() {
    create_deck();
}

/*
* Function: Deck Destructor
* Description: Default destructor for Deck
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Deck::~Deck() {
    // delete the deck
}

/*
* Function: get_n_cards
* Description: The accessors for the n_cards
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
int Deck::get_n_cards() {
    return this->n_cards;
}

/*
* Function: get_n_cards
* Description: The accessors for the n_cards
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
void Deck::set_n_cards(int cards) {
    this->n_cards = cards;
}

/*
* Function: create_deck
* Description: Create the n_cards
* Parameters: - 
* Pre-Conditions: The deck is not yet created
* Post-Conditions: The deck is created, and the cards have set rank & suit
 */
void Deck::create_deck() {
    // SUITS: 
    // 0 = diamonds
    // 1 = hearts
    // 2 = spades
    // 3 = clubs

    // RANKS:
    // 0 - 12 = Ace, 2, 3 ... Queen, King

    // create the empty deck
    for (int rank = 0; rank < NUM_RANK; rank++) {
        for (int suit = 0; suit < NUM_SUIT; suit++) {
            this->deck[rank*NUM_SUIT+suit].set_rank(rank);
            this->deck[rank*NUM_SUIT+suit].set_suit(suit);
        }
    }

    set_n_cards(NUM_CARDS);

}

/*
* Function: shuffle_deck
* Description: shuffle the deck of cards
* Parameters: -
* Pre-Conditions: The deck is not yet shuffled
* Post-Conditions: The deck is shuffled randomly
 */
void Deck::shuffle_deck() {
    int iPick;
    srand(time(NULL));
    Card temp;

    for (int index_current = 0; index_current < NUM_CARDS; index_current++) {
        // create a random pick
        iPick = rand() % NUM_CARDS;
        // swap the cards
        swap_cards(temp, iPick, index_current);
    }
}

/*
* Function: swap_cards
* Description: switch the cards
* Parameters: Card, int, int 
* Pre-Conditions: Cards are not switched
* Post-Conditions: Cards are switched
 */
void Deck::swap_cards(Card temp, int iPick, int current) {
    temp = this->deck[iPick];
    this->deck[iPick] = this->deck[current];
    this->deck[current] = temp;
}

/*
* Function: deal_card
* Description: deal cards
* Parameters: -
* Pre-Conditions: The deck is present, no card dealt
* Post-Conditions: A card is dealt from the deck, the deck size decreases
 */
Card Deck::deal_card() {
    Card cardOut;
    // the formula: is NUM_CARDS - n_cards = index of the deck we're at
    int index = NUM_CARDS - n_cards;

    // check if the deck is empty
    if (this->get_n_cards() <= 0) {
        cout << "The deck is empty." << endl;
    } else {
        cardOut = deck[index];
        // decrease the number of cards in the deck by one
        set_n_cards(this->get_n_cards() - 1);        
    }
    
    return cardOut;
}

/*
* Function: print_deck
* Description: print the deck of cards
* Parameters: -
* Pre-Conditions: The deck of cards is not printed
* Post-Conditions: The deck is printed
 */
void Deck::print_deck() {
    int index = NUM_CARDS - n_cards;

    cout << "Printing out a deck of " << n_cards << " cards."<< endl;

    for (int card = index; card < NUM_CARDS; ++card) {
        this->deck[card].toString();
    }    
}

/*
* Function: write_to_file
* Description: write to file
* Parameters: string
* Pre-Conditions: -
* Post-Conditions: -
 */
void Deck::write_to_file(string userFile) {
    int suit, rank;
    string outputFile = userFile;
    ofstream MyFile(outputFile + ".txt");

    // write to file
    for (int card = 0; card < NUM_CARDS; card++) {
        suit = this->deck[card].get_suit();
        rank = this->deck[card].get_rank();
        MyFile << suit << ", " << rank << endl;
    }
}





