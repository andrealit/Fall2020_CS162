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

        virtual float area() const;
        float getRadius() const;
        void print_info();

};

#endif