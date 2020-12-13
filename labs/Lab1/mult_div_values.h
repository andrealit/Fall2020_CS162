#ifndef mult_div_values_h
#define mult_div_values_h

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*
struct declarations
*/
struct mult_div_values{
	int mult;
	float div;
};

// check for valid rows/cols input
bool is_valid_dimensions(char *m, char *n);

// create the matrix of structs with the given m*n dimensions
mult_div_values** create_table(int m, int n);

// set the multiplication values
void set_mult_values(mult_div_values **, int, int);

// set the division values
void set_div_values(mult_div_values **, int, int);

// delete matrix from the heap
void delete_table(mult_div_values **table, int m);

#endif