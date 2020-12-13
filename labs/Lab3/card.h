#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card {
    private:
        int suit;
        int rank;

    public:
        Card();
        Card(int suit, int rank);
        ~Card();

        void set_suit(int new_suit);
        int get_suit();
        
        void set_rank(int new_rank);
        int get_rank();

};

#endif