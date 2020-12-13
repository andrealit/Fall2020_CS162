/*
	Animal Class
*/
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal {
public:
	Animal();
	Animal(string, int);
	Animal& operator++();
	Animal operator++(int);
	
	string get_name();
	int get_age();
    void set_name(string);

private:
	string name; //no one can see me

protected:
	int age; //derived class access, not main

};
#endif