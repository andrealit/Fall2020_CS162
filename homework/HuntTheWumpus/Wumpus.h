/*********************************************************************
 ** Program Filename: Wumpus.h
 ** Author: Andrea Tongsak
 ** Date: 11/19/2020
 ** Description: Header file for Wumpus
 ** Input: -
 ** Output: -
 *********************************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

#include "Event.h"

using namespace std;

class Wumpus : public Event {
    protected:
        string message;
        string encounterRead;
        bool alive;
    
    public:
        Wumpus();

        void percept() const;
        void encounter() const;
        bool get_alive();
};


#endif /* Wumpus_h */
