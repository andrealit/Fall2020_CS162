/*
	Animal Class
*/
#include <iostream>
#include "animal.h"

using namespace std;

Animal::Animal(string input_name, int age) {
	cout << "Alternate animal constructor called" << endl;
	name = input_name;
	this->age = age;
}

Animal::Animal() {
	cout << "Default animal constructor called" << endl;
	this->name = "Specimen Unknown";
	this->age = 0;
}

Animal& Animal::operator++() {
	++age;
	return *this;
}

Animal Animal::operator++(int) {
	Animal old(*this); // copy constructor
	++(*this);
	return old;
}

ostream& operator<<(ostream& out, const Animal& a) {
	out << "Name: " << a.name << ", Age: " << a.age;
	return out;
}

string Animal::get_name() {
	return name;
}

int Animal::get_age(){
	return age;
}

void Animal::set_name(string name){
    this->name = name;
}