#include <iostream>
#include <cmath>
#include <ctype.h> // this provides the isdigit() function

#include "./mult_div_values.h"

using namespace std;

/**
 * Function: is_valid_dimensions
 * Description: checks if the inputted values are accurate for tables
 * 
 */ 
bool is_valid_dimensions(char *m, char *n) {
    bool check = true;

    if ((*m < 49) || (*m > 57) || (*n < 49) || (*n > 57)) {
        cout << "Your inputs are incorrect!" << endl;
        return false;
    }

    return check;
}

/**
 * Function: create_table
 * Description: creates the empty table of struct
 * 
 */ 
mult_div_values** create_table(int m, int n) {
    mult_div_values ** table = new mult_div_values *[m];
    for (int i = 0; i < m; ++i) {
        table[i] = new mult_div_values[n];
    }
    return table;
}

/**
 * Function: set_mult_values
 * Description: sets the multiplication values
 * 
 */ 
void set_mult_values(mult_div_values ** matrix, int m, int n) {
    cout << m << " x " << n << " Multiplication Table" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j].mult = (i+1)*(j+1);
            cout << matrix[i][j].mult << " ";
        }
        cout << endl;
    }
}

/**
 * Function: set_div_values
 * Description: sets the division values
 * 
 */ 
void set_div_values(mult_div_values ** matrix, int m, int n) {
    cout << m << " / " << n << " Division Table" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j].div = (float(i+1)/float(j+1));
            cout << matrix[i][j].div << " ";
        }
        cout << endl;
    }
}

/**
 * Function: delete_table
 * Description: deletes the dynamic array of strucs
 * 
 */ 
void delete_table(mult_div_values ** matrix, int m) {
    for (int i = 0; i < m; i++) {
        delete [] matrix[i];
    }
    delete[] matrix;
}







