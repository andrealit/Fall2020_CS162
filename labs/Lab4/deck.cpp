#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "card.h"
#include "deck.h"

/*
 * Deck Constructor 
*/
Deck::Deck() {
    // create deck
    create_deck();
}

/*
 * Deck Destructor 
*/
Deck::~Deck() {
    // destroy the deck
    cout << "Deleted the deck" << endl;
}

/*
 * Create Deck 
*/
void Deck::create_deck() {
    // create the empty deck
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++) {
            this->deck[suit*13+rank].set_suit(suit);
            this->deck[suit*13+rank].set_rank(rank);
        }
    }
}

/*
 * Shuffle Deck 
*/
void Deck::shuffle_deck() {
    int iPick;
    srand(time(NULL));
    Card temp;

    for (int index_current = 0; index_current < 52; index_current++) {
        // create a random pick
        iPick = rand() % 52;
        // swap the Cards
        temp = this->deck[iPick];
        this->deck[iPick] = this->deck[index_current];
        this->deck[index_current] = temp;
    }
}

/*
 * Print deck 
*/
void Deck::print_deck() {
    int suit, rank;

    for (int card = 0; card < 52; ++card) {
        suit = this->deck[card].get_suit() + 1;
        rank = this->deck[card].get_rank() + 1;
        cout << "suit: " << suit << ", rank:" << rank << endl;
    }
}

/**
 * Write to file
 */ 
void Deck::write_to_file(string userFile) {
    int suit, rank;
    string outputFile = userFile;
    ofstream MyFile(outputFile + ".txt");

    // write to file
    for (int card = 0; card < 52; card++) {
        suit = this->deck[card].get_suit();
        rank = this->deck[card].get_rank();
        MyFile << suit << ", " << rank << endl;
    }
}