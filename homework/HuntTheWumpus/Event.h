/*********************************************************************
** Program Filename: Event.h
** Author: Andrea Tongsak
** Date: 11/10/2020
** Description: The header file for the Event class
** Input:
** Output:
*********************************************************************/

#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

using namespace std;

// Event is an abstract class
class Event {
    protected:
        string message;
        string encounterRead;
    
    public:
        // Event constructor
        Event();
        // Event destructor
        ~Event();
        // // mutator for message
        // void set_percept(string);
        // // mutator for encounter
        // void set_encounter(string);

        // Percept method called whenever the adventurer is in a room
        virtual void percept() const = 0;
        // Encounter method called when the adventurer enters the same room
        virtual void encounter() const = 0;
    
};

#endif /* Event_h */
