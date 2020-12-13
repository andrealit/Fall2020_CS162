/*********************************************************************
** Program Filename: Wumpus.cpp
** Author: Andrea Tongsak
** Date: 11/10/2020
** Description: The file with the definition for the Wumpus
** Input: -
** Output: -
*********************************************************************/

#include "Wumpus.h"

using namespace std;

/*
* Function: Wumpus constructor
* Description: The constructor for wumpus
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: all values are set
 */
Wumpus::Wumpus() {
    // set_percept("You smell a terrible stench.");
    // set_encounter("MUNCH! The Wumpus ate you.");
    alive = true;
}

/*
* Function: percept
* Description: inherited from event, specific to wumpus
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: wumpus percept message printed
 */
void Wumpus::percept() const {
    // print out the message
    cout << "You smell a terrible stench." << endl;
}

/*
* Function: encounter
* Description: The encounter mssage for wumpus
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: prints out death message
 */
void Wumpus::encounter() const {
    cout << "MUNCH! The Wumpus ate you." << endl;
}

/*
* Function: get_alive
* Description: Alive checker for wumpus
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: returns whether the wumpus is alive.
 */
bool Wumpus::get_alive() {
    return alive;
}
