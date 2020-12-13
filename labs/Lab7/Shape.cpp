#include "Shape.h"

#include <iostream>

using namespace std;

/**
 * Shape default constructor
*/
Shape::Shape() {
    this->name = "Shape";
    this->color = "blue";
}

// parameterized constructor
Shape::Shape(string n1, string c1) {
    try {
        if (n1 == "1") {
            throw c1;
        }
        this->name = n1;
        this->color = c1;

    } catch (string n1) {
         cout << "You entered an integer!" << endl;
    } catch (...) {
         cout << "Exception caught." << endl; 
    }    
}

// Destruct the shape
Shape::~Shape() {
    
}

float Shape::area() const {
    return 0;
}

void Shape::setName(string nIn) {
    this->name = nIn;
}

void Shape::setColor(string cIn) {
    this->color = cIn;
}

string Shape::getName() {
    return this->name;
}

string Shape::getColor() {
    return this->color;
}

void Shape::print_info() {
    cout << "The name: " << name << endl;
    cout << "The color: " << color << endl;
    cout << "The area: " << area() << endl;
}

