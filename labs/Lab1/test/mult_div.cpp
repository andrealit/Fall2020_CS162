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


/**
 * Function: is_valid_dimensions
 * Description: checks if the inputted values are accurate for tables
 * 
 */ 
bool is_valid_dimensions(char *m, char *n) {
    bool check = false;

    if (!(isdigit(*m))) {
        cout << "You did not enter a valid row..." << endl;
        check = false;
    } else if (!(isdigit(*n))) {
        cout << "You did not enter a valid column..." << endl;
        check = false;
    } else if (!(isdigit(*m)) && !(isdigit(*n))) {
        cout << "You did not enter a valid column..." << endl;
        check = false;
    } else {
        check = true;
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
    for (int i = 0; i < m; i++) {
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
            matrix[i][j].div = float(i+1)/float(j+1);
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

int main(int argc, char* argv[]) {
    int rows;
    int cols;
    bool check;

    // check if argv is correct
    if (argc != 3) {
        cout << "Not the correct number of arguments, exiting." << endl;
        return 0;
    }

    do {
        check = is_valid_dimensions(argv[1], argv[2]);
    } while (check == false);

    rows = atoi(argv[1]);
    cols = atoi(argv[2]);

    mult_div_values ** table = create_table(5, 5);

    // multiply
    set_mult_values(table, rows, cols);

    // divide
    set_div_values(table, rows, cols);

    // delete memory
    delete_table(table, rows);

    return 0;
}

