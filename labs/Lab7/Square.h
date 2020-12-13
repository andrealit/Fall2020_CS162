#ifndef SQUARE
#define SQUARE

#include "Rectangle.h"

class Square : public Rectangle {
    public: 
        Square();
        Square(int);
        ~Square();

        virtual float area();

        void print_info();

};

#endif