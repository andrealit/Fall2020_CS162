/*********************************************************************
** Program Filename: Event.cpp
** Author: Andrea Tongsak
** Date: 11/10/2020
** Description: The file with the declaration for the Event class
** Input:
** Output:
*********************************************************************/

#include "Event.h"

/*
* Function: Event constructor
* Description: The event is created
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Event abstract class
 */
Event::Event() {
}

/*
* Function: Event destruct 
* Description: The event is destroyed
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Event memory gone
 */
Event::~Event() {
    // event destructor
}

// void Event::set_percept(string perc) {
//     message = perc;
// }

// void Event::set_encounter(string enc) {
//     encounterRead = enc;
// }


/*
* Function: percept
* Description: We fill out the message
* Parameters: -
* Pre-Conditions: The
* Post-Conditions: The grid of the correct size is printed out, rooms filled.
 */
void Event::percept() const {
}

/*
* Function: encounter
* Description: the message prints out when a room is entered
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The message is printed
 */
void Event::encounter() const {
    // called when the adventurer enters the same room
}