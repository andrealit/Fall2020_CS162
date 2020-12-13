#include "Square.h"

Square::Square() {
    setWidth(1);
    setHeight(1);
}

Square::Square(int side) {
    setWidth(side);
    setHeight(side);
}

Square::~Square() {

}

float Square::area() {
    //
        int area = getWidth()*getHeight();
        if (area == 0) {
            throw area;
        }
    //} catch (int a1) {
      //  cout << "The area is negative! Not a shape." << endl; 
    //}

    return getWidth()*getHeight();
}

void Square::print_info() {
    cout << "The name: " << getName() << endl;
    cout << "The color: " << getColor() << endl;
    cout << "The area: " << area() << endl;
}