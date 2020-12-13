#include "Car.h"

#include <iostream>
#include <string>

using namespace std;

Car::Car(int yearIn, string makeIn) {
    year = yearIn;
    make = makeIn;
    speed = 0;
}

Car::~Car() {
    // destroys the Car object
}

int Car::get_year() {
    return year;
}

void Car::set_year(int yearIn) {
    this->year = yearIn;
}

string Car::get_make() {
    return make;
}

void Car::set_make(string makeIn) {
    this->make = makeIn;
}

int Car::get_speed() {
    return speed;
}

void Car::accelerate() {
    this->speed += 5;
}