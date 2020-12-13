/*
	Monkey Class
*/
#ifndef MONKEY_H
#define MONKEY_H

#include <iostream>
#include "animal.h"

using namespace std;

class Monkey : public Animal {
public:
	Monkey();
    Monkey(string, int);

private:
	// Note that monkeys can also have extra properties in addition
	// to the ones that are inherited.
	int longest_jump;
    int max_bananas;
};
#endif