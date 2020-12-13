#ifndef CIRCLE
#define CIRCLE

#include "Shape.h"

/**
 * Circle class
 */ 

class Circle : public Shape {
    private:
        float radius;
    public:
        Circle();
        Circle(int);
        ~Circle();

        float area();
        float getRadius();
        void print_info();

};

#endif