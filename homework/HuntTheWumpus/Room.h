/*********************************************************************
 ** Program Filename: Room.h
 ** Author: Andrea Tongsak
 ** Date: 11/19/2020
 ** Description: Room header file
 ** Input: -
 ** Output: -
 *********************************************************************/

#ifndef Room_h
#define Room_h

#include "Event.h"
#include "Wumpus.h"
#include "Bats.h"
#include "Gold.h"
#include "Pit.h"

using namespace std;

class Room {
    protected:
        Event* room_event;
        bool player;
        bool wumpus_in;
        int event;
    
    public:
        Room();
        Room& operator=(const Room &);
        ~Room();
    
        void get_entrance();
        void get_percept();
        int get_event();
        bool get_player();
        Event* get_room_event();
        bool get_wumpus();
        void set_player(bool);
        void set_room_event(Event*);
        void set_event(int);
        void set_wumpus(bool);

};





#endif /* Room_h */
