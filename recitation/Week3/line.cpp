#ifndef LINE_H
#define LINE_H
#include "point.h"

class Line {
    private:
        int n_points;
        Point* points;
    public:
        Line();
        Line(int);
        Line(int, int);
        
}
