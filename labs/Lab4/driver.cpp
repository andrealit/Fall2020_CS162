#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "card.h"
#include "deck.h"
#include "hand.h"

/*
 * Main function 
*/
int main(int argc, char** argv) {

    // welcome the user
    cout << "Welcome! The card game is starting." << endl;

    Deck testDeck;

    cout << "The deck is being shuffled!" << endl;
    testDeck.shuffle_deck();

    Card temp;
    int userInput;
    string userFile;

    // create the output file
    cout << "Do you wish to print out by terminal (1) or output file (2)?" << endl;
    cin >> userInput;

    switch (userInput) {
        case 1:
            cout << "Printing to terminal..." << endl;
            // print the deck to the terminal
            testDeck.print_deck();
            cout << "The deck is printed." << endl;
            break;

        case 2:
            cout << "Enter the name of the output file: " << endl;
            cin >> userFile;

            testDeck.write_to_file(userFile);

            cout << "The deck is printed to an output file." << endl;
            
            break;
    }

    // Hand Big Three is tested

    Hand* testHand = new Hand();
    delete testHand;

    Hand hand2 = Hand();

    // dereference testHand
    Hand handDef = Hand();

    // assignment operator overload is used
    handDef = hand2;
    
}