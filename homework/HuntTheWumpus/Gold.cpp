/*********************************************************************
** Program Filename: Gold.cpp
** Author: Andrea Tongsak
** Date: 11/10/2020
** Description: The declaration file for gold class
** Input: -
** Output: -
*********************************************************************/

#include "Gold.h"

using namespace std;

/*
* Function: Gold Constructor
* Description: Make the gold
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Gold::Gold() {
    // set_percept("You see a glimmer nearby.");
    // set_encounter("Picking up gold...");
}

/*
* Function: Gold Destructor
* Description: Destroy the gold
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Gold::~Gold() {
    // destructor
}

/*
* Function: percept
* Description: message using virtual void function
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
void Gold::percept() const {
    // percept prints out the message
    cout << "You see a glimmer nearby." << endl;
}

/*
* Function: encounter
* Description: message using the encounter message
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
void Gold::encounter() const {
    cout << "Sparkle! Collecting gold. ✨" << endl;
}


