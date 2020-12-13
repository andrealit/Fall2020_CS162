/*********************************************************************
** Program Filename: Bats.cpp
** Author: Andrea Tongsak
** Date: 11/20/2020
** Description: The file for the Bat class
** Input:
** Output:
*********************************************************************/


#ifndef BATS_H
#define BATS_H

#include "Event.h"
//#include <string.h>

class Bats : public Event {
    protected:
        string message;
        string encounterRead;
    public:
        Bats();
        ~Bats();

    //void set_percept(string);
        void percept() const;
        void encounter() const;
};


#endif /* Bats_h */
