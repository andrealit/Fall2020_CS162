#ifndef SHAPE
#define SHAPE

#include <iostream>

using namespace std;

class Shape {
    private:
        string name;
        string color;
    public: 
        Shape();
        Shape(string, string);
        ~Shape();

        float area() const;
        void setName(string);
        void setColor(string);
        string getName();
        string getColor();

        void print_info();
};

#endif