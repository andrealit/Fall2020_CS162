#ifndef RECTANGLE
#define RECTANGLE

#include "Shape.h"

/**
 * Rectangle
*/
class Rectangle : public Shape {
    private:
        float width;
        float height;
    public:
        Rectangle();
        Rectangle(int, int);
        ~Rectangle();
        
        float area() const;
        float getWidth() const;
        float getHeight() const;
        void setWidth(float w);
        void setHeight(float h);

        void print_info();

        
};

bool operator > (const Rectangle&, const Rectangle&);
bool operator < (const Rectangle&, const Rectangle&);

#endif