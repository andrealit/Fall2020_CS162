#include "Circle.h"

#include <math.h>

#include <iostream>

using namespace std;

// Constructor for the circle
Circle::Circle() {
    this->radius = 1;
}

// Circle with param
Circle::Circle(int rad) {
    this->radius = rad;
}

// Destructor for the circle
Circle::~Circle() {
    
}

// Calculating the area for radius
float Circle::getRadius() const {
    return radius;
}

// Calculating the area for circle
float Circle::area() const {
    return pow((3.14*getRadius()),2);
}

// print out the Circle info
void Circle::print_info() {
    cout << "The name is: " << getName() << endl;
    cout << "The color is: " << getColor() << endl;
    cout << "The area is: " << area() << endl;
}