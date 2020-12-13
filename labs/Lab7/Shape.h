#ifndef SHAPE
#define SHAPE

#include <iostream>

using namespace std;

// Shape is now an abstract base class
// the function area is polymorphic
// Polymorphic by creating a virtual function
// Pure virtual function could be area

class Shape {
    private:
        string name;
        string color;
    public: 
        Shape();
        Shape(string, string);
        ~Shape();

        virtual float area() const = 0;

        void setName(string);
        void setColor(string);
        string getName();
        string getColor();

        void print_info();

        
};

#endif