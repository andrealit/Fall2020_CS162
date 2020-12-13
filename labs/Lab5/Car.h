#ifndef CAR_H
#define CAR_H

#include <string>
#include <fstream>

using namespace std;

class Car {
    private:
        int year;
        string make;
        int speed;

    public:
        // Non default constructor
        Car(int, string);
        // Destructor
        ~Car();

        // accessors
        int get_year();
        void set_year(int);

        string get_make();
        void set_make(string);

        int get_speed();
        void set_speed(int);

        void accelerate();



};

#endif