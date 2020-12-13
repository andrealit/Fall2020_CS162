#include <iostream>

#include "./mult_div_values.h"

using namespace std;

int main(int argc, char* argv[]) {
    int rows;
    int cols;
    bool check;

    // check if argv is correct
    if (argc != 3) {
        cout << "Not the correct number of arguments, exiting." << endl;
        return 0;
    }

    check = is_valid_dimensions(argv[1], argv[2]);

    if (check == false) {
        return 0;
    }

    rows = atoi(argv[1]);
    cols = atoi(argv[2]);

    mult_div_values ** table = create_table(rows, cols);

    // multiply
    set_mult_values(table, rows, cols);

    // divide
    set_div_values(table, rows, cols);

    // delete memory
    delete_table(table, rows);

    return 0;
}