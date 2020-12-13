/*********************************************************************
** Program Filename: Card.cpp
** Author: Andrea Tongsak
** Date: 10/16/2020
** Description: The file with employee struct and hour
** Input:
** Output:
*********************************************************************/

#include "Card.h"

#include <iostream>
#include <string>

using namespace std;

/**
 * Function: Card Constructor
 * Description: Default constructor for Card
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
Card::Card()
{
    // default
}

/**
 * Function: Card Constructor
 * Description: Default constructor for Card with parameters
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
Card::Card(int i_rank, int i_suit)
{
    this->rank = i_rank;
    this->suit = i_suit;
}

/**
 * Function: Card Destructor
 * Description: Default destructor for Card
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
Card::~Card()
{
    // delete the Card object
}

/**
 * Function: get_rank
 * Description: Rank accessor
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
int Card::get_rank()
{
    return this->rank;
}

/**
 * Function: get_suit
 * Description: Suit accessor
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
int Card::get_suit()
{
    return this->suit;
}

/**
 * Function: set_rank
 * Description: Rank mutator
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
void Card::set_rank(int rank)
{
    this->rank = rank;
}

/**
 * Function: set_suit
 * Description: Suit mutator
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
void Card::set_suit(int suit)
{
    this->suit = suit;
}

/**
 * Function: show_card
 * Description: the card is shown to the user
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
void Card::show_card()
{
    // display the card to the user
    cout << "Rank: " << this->get_rank() << ", Suit: " << this->get_suit() << endl;
}

/**
 * Function: playable
 * Description: is the card playable? (with pointer)
 * Parameters: -
 * Pre-Conditions: We don't know if the card we selected is playable
 * Post-Conditions: The card selected is playable
 */
bool Card::playable(Card *faceup)
{
    bool canPlay = false;

    // check against the suit and rank of the top card
    if (this->get_rank() == faceup->get_rank() || this->get_suit() == faceup->get_suit())
    {
        canPlay = true;
    }

    if (this->get_rank() == 7) {
        this->toString();
        canPlay = true;
    }

    return canPlay;
}

/**
 * Function: playable
 * Description: is the card playable?
 * Parameters: -
 * Pre-Conditions: We don't know if the card we selected is playable
 * Post-Conditions: The card selected is playable
 */
bool Card::playable(Card faceup)
{
    bool canPlay = false;

    // check against the suit and rank of the top card
    if (this->get_rank() == faceup.get_rank() || this->get_suit() == faceup.get_suit())
    {
        canPlay = true;
    }

    if (faceup.get_rank() == 7) {
        cout << "CRAZY 8s!" << endl;
        canPlay = true;
    }

    return canPlay;
}

/**
 * Function: replace_card
 * Description: used for the top card
 * Parameters: -
 * Pre-Conditions: The card is replaced with the "new" card
 * Post-Conditions: The card is replaced
 */
void Card::replace_card(Card *replace) {
    this->set_rank(replace->get_rank());
    this->set_suit(replace->get_suit());
}

/**
 * Function: toString
 * Description: the string format of the card is given
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: the correct string is printed "4 of Diamonds, etc"
 */
void Card::toString()
{
    string rankStr;
    string suitStr;
    int rank = this->get_rank();
    int suit = this->get_suit();

    // the rank is the number
    switch (rank)
    {
    case 0:
        rankStr = "Ace of ";
        break;
    case 1:
        rankStr = "Two of ";
        break;
    case 2:
        rankStr = "Three of ";
        break;
    case 3:
        rankStr = "Four of ";
        break;
    case 4:
        rankStr = "Five of ";
        break;
    case 5:
        rankStr = "Six of ";
        break;
    case 6:
        rankStr = "Seven of ";
        break;
    case 7:
        rankStr = "Eight of ";
        break;
    case 8:
        rankStr = "Nine of ";
        break;
    case 9:
        rankStr = "Ten of ";
        break;
    case 10:
        rankStr = "Jack of ";
        break;
    case 11:
        rankStr = "Queen of ";
        break;
    case 12:
        rankStr = "King of ";
    }

    switch (suit)
    {
    case 0:
        suitStr = "Diamonds";
        break;
    case 1:
        suitStr = "Hearts";
        break;
    case 2:
        suitStr = "Spades";
        break;
    case 3:
        suitStr = "Clubs";
    }

    cout << rankStr << suitStr << endl;
}

/**
 * Function: artCard
 * Description: the art version of the card is here
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: the correct string is printed "4 of Diamonds, etc"
 */
void Card::artCard()
{
    // rendering an ASCII image of the card
    // usually return the string version of the card
    // enum suits_name { Spades, Diamonds, Hearts, Clubs };
    // enum suits_symbols { ♠, ♦, ♥, ♣ };
}

