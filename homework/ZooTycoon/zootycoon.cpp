/******************************************************
** Program: zootycoon.cpp
** Author: Andrea Tongsak
** Date: 10/30/2020
** Description: The zoo tycoon file
** Input: -
** Output: -
******************************************************/

#include <iostream>

#include "SeaLion.h"
#include "Tiger.h"
#include "BlackBear.h"
#include "Zoo.h"

int main(int argc, char* argv[]) {
    bool valid;
    string s;
    int input;
    double feed = 80;
    
    cout << "Welcome! Zoo Tycoon is starting." << endl;
    
    Zoo testZoo;
    
    //testZoo.pick_sick();
    
    do { // progress through months until the player does not wish to play again

        feed = testZoo.zoo_cycle(feed);

        if (testZoo.get_bank() == 0) { // the zoo has gone
            cout << "Your zoo has gone bankrupt. Game over." << endl;
            break;
        }

        // ask the user whether they'd like to play again.
        cout << "It's month " << testZoo.get_time() << ". Would you like to continue? (y/n)" << endl;

        do {
            getline(cin, s);
            if (s == "y" || s == "Y") {
                valid = true;
            } else if (s == "n" || s == "N")
            {
                valid = true;
            } else {
                valid = false;
            }

        } while (valid == false);

    } while (s == "y" || s == "Y");
    
    return 0;
}
