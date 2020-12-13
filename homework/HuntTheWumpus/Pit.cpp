/*********************************************************************
** Program Filename: Pit.cpp
** Author: Andrea Tongsak
** Date: 11/9/2020
** Description: The file with the declaration for the Pit class
** Input: -
** Output: - 
*********************************************************************/

#include "Pit.h"

/*
* Function: Pit constructor
* Description: The pit is created
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Pit constructor
 */
Pit::Pit() {
    // set_percept("You feel a breeze.");
    // set_encounter("You fell in and died.");
}

/*
* Function: percept
* Description: The percept message prints
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Pit message is print
 */
void Pit::percept() const {
    cout << "WHOOSH! You feel a breeze." << endl;
}

/*
* Function: encounter
* Description: The encounter message prints
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Pit message and user dies
 */
void Pit::encounter() const {
    cout << "You fell in and died." << endl;
    cout << "GAME OVER." << endl;
}

