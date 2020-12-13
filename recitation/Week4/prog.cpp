#include <iostream>
#include "animal.h"
#include "monkey.h"

using namespace std;

/*
  Illustrate how to utilize inheritance
*/
int main() {

	// Create a generic animal
	Animal a1("Bambi", 15);
	
	// name is private so we can't access it from mainj
	a1.set_name("Henry");
	// age is protected so we can't access it from main
	//a1.age = 18;
	cout << "Created animal. Retrieved name: " << a1.get_name() << endl;

	Monkey m1;
	// now we can use the inherited variables and functions
	cout << "Created monkey. Retrieved name: " << m1.get_name() << endl;
    m1.set_name("King Louie");
    cout << m1.get_name() << endl;
	cout << m1.get_age() << endl;

	return 0;
}