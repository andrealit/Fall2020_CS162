/*********************************************************************
** Program Filename: Pit.h
** Author: Andrea Tongsak
** Date: 11/9/2020
** Description: The file with the declaration for the Pit class
** Input:
** Output:
*********************************************************************/

#ifndef Pit_h
#define Pit_h

#include "Event.h"

using namespace std;

class Pit : public Event {
    protected:
        string message;
        string encounterRead;
    public:
        Pit();
        ~Pit();
        void percept() const;
        void encounter() const;
};

#endif /* Pit_h */

