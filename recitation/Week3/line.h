#include <iostream>
#include "line.h"

using namespace std;

Line::Line() {
    n_points = 2;
    points = new Point[n_points];
    points[n_points] = new Point[n_points];
    cout << "Line default constructor called." << endl;
}

Line::Line() {
    n_points = 2; 
    points = new Point[n_points];
    for (int i = 0; i < n; i++) {
        points[i].set_location(i,i);
    }
    cout << "New Line constructor called." << endl;
}

Line::Line(int x1, int x2, int y1, int y2) {
    n_points = 2; 
    points = new Points[num_points];
    points[0].set_location(x1, y1);
    points[1].set_location(x2, y2);
    cout << "Another Line constructor called" << endl;
}

Line::~Line() {
    delete[] points;
    cout << "Line destructor called" << endl;
}

void Line::print_point(int n, Point& p) {
    
}

void Line::set_point(int n, Point& p) {
    points[n] = p;
}