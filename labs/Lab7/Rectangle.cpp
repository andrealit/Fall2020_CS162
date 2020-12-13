#include "Rectangle.h"

// Rectangle for the constructor
Rectangle::Rectangle() {
    this->width = 1;
    this->height = 1;
}

// Constructor parameters
Rectangle::Rectangle(int wid, int hei) {
    this->width = wid;
    this->height = hei;
}

// Destruct the rectangle
Rectangle::~Rectangle() {

}

// Float get the width
float Rectangle::getWidth() const {
    return width;
}

// Float get the height
float Rectangle::getHeight() const {
    return height;
}

void Rectangle::setWidth(float w) {
    this->width = w;
}

void Rectangle::setHeight(float h) {
    this->height = h;
}

// Calculating the Rectangle
float Rectangle::area() const {
    return width * height;
}

void Rectangle::print_info() {
    cout << "The name is: " << getName() << endl;
    cout << "The color is: " << getColor() << endl;
    cout << "The area is: " << area() << endl;
}

bool operator > (const Rectangle& rect1, const Rectangle& rect2) {
    return rect1.area() > rect2.area();
}

bool operator < (const Rectangle& rect1, const Rectangle& rect2) {
    return rect1.area() < rect2.area();
}
