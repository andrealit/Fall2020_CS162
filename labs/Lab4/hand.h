#ifndef HAND_H
#define HAND_H

#include "card.h"

#include <iostream>
using namespace std;

class Hand {
    private:
        Card* cards;    // this is a pointer
        int n_cards;   
    public: 
        // constructor
        Hand();
        // destructor
        ~Hand();
        // copy constructor
        Hand(const Hand&);
        // assignment operator overload
        Hand& operator= (const Hand&);

        // n cards accessors and mutators
        int get_n_cards();
        void set_n_cards(int);

        // cards accessors and mutators
        Card* get_cards();

};

#endif

