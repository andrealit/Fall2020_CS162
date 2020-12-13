/*********************************************************************
** Program Filename: Gold.h
** Author: Andrea Tongsak
** Date: 11/20/2020
** Description: Gold header file
** Input: -
** Output: -
*********************************************************************/

#ifndef GOLD_H
#define GOLD_H

#include "Event.h"

class Gold : public Event {
    protected:
        string message;
        string encounterRead;
    public:
        Gold();
        ~Gold();
        void percept() const;
        void encounter() const;
};

#endif /* Gold_h */
