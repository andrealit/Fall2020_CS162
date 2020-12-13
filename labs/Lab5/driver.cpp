
#include <iostream>
#include <string>

#include "Car.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Welcome the Car is starting." << endl;

    int yearBuilt = 2005;
    string make = "Volvo";

    // Create the Car object
    Car* testCar = new Car(yearBuilt, make);

    // Display the make and year of the car
    cout << "Make: " << testCar->get_make() << endl;
    cout << "Year: " << testCar->get_year() << endl;

    // The current speed of the car accelerates
    for (int i = 0; i < 5; i++) {
        testCar->accelerate();
        cout << "Speed: " << testCar->get_speed() << endl;
    }
    
    return 0;
}
