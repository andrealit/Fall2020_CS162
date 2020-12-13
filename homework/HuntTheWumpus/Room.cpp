/*********************************************************************
 ** Program Filename: Room.cpp
 ** Author: Andrea Tongsak
 ** Date: 11/19/2020
 ** Description: The Room class definitions
 ** Input: -
 ** Output: -
 *********************************************************************/

#include "Room.h"

/*
* Function: Room constructor
* Description: Room is made
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Room is created
 */
Room::Room() {
    room_event = NULL;
    player = false;
    wumpus_in = false;
}

/*
* Function: Room Assigment Operator Overload
* Description: Assigns the object to a new one
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Room object copies over
 */
Room& Room::operator=(const Room & oldroom) {
    room_event = oldroom.room_event;
    player = oldroom.player;
    wumpus_in = oldroom.wumpus_in;
    event = oldroom.event;
    return *this;
}

/*
* Function: Room destructor
* Description: Memory allcoated for room is destroyed 
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Room is destroyed
 */
Room::~Room() {
    //Destructor for room.
    if (room_event != NULL) {
        delete room_event;
    }
}

/*
* Function: retrieve the entrance
* Description: The entrance is printed out
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Entrance is destroyed
 */
void Room::get_entrance() {
    room_event->encounter();
}

/*
* Function: percept
* Description: The room prints out the message
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Message for room
 */
void Room::get_percept() {
    //room_event->percept();
    room_event->percept();
}

/*
* Function: get_event
* Description: Event accessor
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The event is returned
 */
int Room::get_event() {
    return event;
}

/*
* Function: get_player
* Description: The encounter message prints
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Pit message and user dies
 */
bool Room::get_player() {
    return player;
}

/*
* Function: get_room_event
* Description: The event accessor comes around
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Event is returned
 */
Event* Room::get_room_event() {
    return room_event;
}

/*
* Function: get_wumpus
* Description: Accessor for wumpus
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: wumpus is recieved
 */
bool Room::get_wumpus() {
    return wumpus_in;
}

/*
* Function: set_event
* Description: The event is printed out
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Event is set with the appropriate monster
 */
void Room::set_event(int eventNum) {
    switch (eventNum) {
        case 0: // empty room
            event = eventNum;
            break;
        case 1: // player start and rope
            event = eventNum;
            break;
        case 2:
            event = eventNum;
            wumpus_in = true;
            room_event = new Wumpus;
            break;
        case 3:
            event = eventNum;
            room_event = new Bats;
            break;
        case 4:
            event = eventNum;
            room_event = new Pit;
            break;
        case 5:
            event = eventNum;
            room_event = new Gold;
            break;
        default:
            break;
    }
}

/*
* Function: set_player
* Description: The player is printed out
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Player is set
 */
void Room::set_player(bool playerIn) {
    player = playerIn;
}

/*
* Function: set_room_event
* Description: Mutator for the room event
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Room is set
 */
void Room::set_room_event(Event* eventIn) {
    room_event = eventIn;
}

/*
* Function: set_wumpus
* Description: Mutator for the wumpus
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Wumpus is set
 */
void Room::set_wumpus(bool isWumpus) {
    wumpus_in = isWumpus;
}

