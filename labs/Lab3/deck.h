#ifndef DECK_H
#define DECK_H

#include <iostream>
using namespace std;

class Deck {
    private:
        Card deck[52];
        int deck_size;

    public:
        Deck();
        ~Deck();
        
        void create_deck();
        void shuffle_deck();
        void print_deck();
        void write_to_file(string);

        void swap(int, int);
};

#endif