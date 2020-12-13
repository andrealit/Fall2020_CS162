/*********************************************************************
** Program Filename: Bats.cpp
** Author: Andrea Tongsak
** Date: 11/20/2020
** Description: The file for the Bat class
** Input:
** Output:
*********************************************************************/

#include "Bats.h"

/*
* Function: Bats constructor
* Description: Bats is made
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Bats is created
 */
Bats::Bats() {
    // set_percept("You hear wings flapping.");
    // set_encounter("FWIP! Bats pick you up and fly to a random room.");
}

/*
* Function: percept
* Description: the bat percept message
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: message is printed
 */
void Bats::percept() const {
    cout << "You hear wings flapping." << endl;
}

/*
* Function: encounter
* Description: the encounter message
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: encounter is printed
 */
void Bats::encounter() const {
    cout << "FWIP! Bats pick you up and fly to a random room." << endl;
}

// Bats::~Bats() {
//     cout << "Bats destroyed." << endl;
//     message.clear();
// }

