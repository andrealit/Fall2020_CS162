#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"

#include <iostream>

using namespace std;

int main() {
    cout << "Shapes test for Lab 6." << endl;
    Shape s1;   
    s1.setName("Bob");
    s1.setColor("blue");
    cout << endl;
    s1.print_info();

    cout << endl;

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

    Square sq1(5);
    sq1.setName("Square");
    sq1.setColor("Yellow");
    sq1.area();
    sq1.print_info(); 

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

}