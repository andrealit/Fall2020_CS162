#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"

#include <iostream>

using namespace std;

void print_shape_info(Shape& shape) {
    cout << "The name: " << shape.getName() << endl;
    cout << "The color: " << shape.getColor() << endl;
    cout << "The area: " << shape.area() << endl;
}

int main() {
    cout << "Shapes test for Lab 6." << endl;

    Rectangle r1(8, 8);
    r1.setName("Rectangle");
    r1.setColor("Red");
    r1.area();
    r1.print_info();

    cout << endl;

    Circle c1(5);
    c1.setName("Circle");
    c1.setColor("Purple");
    c1.area();
    c1.print_info();

    cout << endl;

    try {
        Square sq1(0);
        sq1.setName("Square");
        sq1.setColor("Yellow");
        sq1.area();
        sq1.print_info(); 

    } catch (int a1) {
        cout << "The area is zero!" << endl;
    }
    

    // Now comparing rectangles
    Rectangle r2(1,2); 

    cout << endl;

    Rectangle r3(9,9);
    
    cout << endl;

    if (r1>r2) {
        cout << "Rectangle 1 is larger than rectangle 2." << endl;
    }

    if (r1<r3) {
        cout << "Rectangle 3 is larger than rectangle 1." << endl;
    }

    cout << endl;

    // print out information about rect 1
    print_shape_info(r1);

    //throw invalid_argument 



}