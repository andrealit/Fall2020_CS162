/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Andrea Tongsak
 ** Date: 11/19/2020
 ** Description: The main method where command line args are read, post game options are given
 ** Input: The two command line arguments (size, debug)
 ** Output: the game to the player
 *********************************************************************/
#include <iostream>
#include <stdexcept>

#include "Game.h"

using namespace std;

/*
* Function: option menu
* Description: gives user choice for what to do after game ends
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: the user choice is returned in number form
*/
int option_menu() {
    int endOption;

    cout << "The game is over! Options:" << endl;

    cout << "1) Restart with same cave config" << endl;
    cout << "2) Restart with new random cave config" << endl;
    cout << "3) Quit" << endl;

    cin >> endOption;

    return endOption;
}

/*
* Function: main
* Description: processes the command line arguments and starts game
* Parameters: command line arguments
* Pre-Conditions: the command line is passed
* Post-Conditions: this will return the game
*/
int main(int argc, char * argv[]) {
    int boardSize;
    string debugOption;
    int debugNum;
    bool debug; 
    int endOption;

    if (argc != 3) {
        cout << "Not the correct number of arguments, exiting." << endl;
        return 0;
    }

    try {
        boardSize = atoi(argv[1]);

        if (boardSize < 4) {
            throw invalid_argument("Not a big enough board!");
        }

        debugOption = argv[2];

        if (debugOption == "true") {
            debug = true;
        } else if (debugOption == "false") {
            debug = false;
        } else {
            throw invalid_argument("Incorrect boolean input.");
        }
        
        cout << endl;

        cout << "Starting up... H U N T  T H E  W U M P U S ⛰️" << endl;

        cout << endl; 

        do {
            Game testGame;
            testGame.game_cycle(boardSize, debug);
            endOption = option_menu();

            if (endOption == 2) {
                boardSize = (rand() % (9 - 4 + 1)) + 4;
                debugNum = (rand() % (2 - 1 + 1)) + 1;

                if (debugNum == 1) {
                    debug = true;
                } else {
                    debug = false;
                }
            }
        } while (endOption == 1 || endOption == 2);

    } catch (const invalid_argument& ia) {
        cout << "Invalid argument: " << ia.what() << endl;
    }

    return 0;
}
