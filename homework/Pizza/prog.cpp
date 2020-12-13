//
//  prog.cpp
//  PizzaPortal
//
//  Created by Andrea Tongsak on 10/2/20.
//  Copyright © 2020 Andrea Tongsak. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

#include "emp_hours.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    /* read in for EMP_HOURS */

    // check for correct number of arguments
    if (argc != 2)
    {
        cout << "Incorrect number of arguments, exiting." << endl;
        return 2;
    }

    // check the file exists
    int numEmp;
    string temp;

    ifstream ifile(argv[1]);

    // read data from file
    if (ifile.fail() || !ifile)
    {
        cout << "Error in opening student file...!!" << endl;
        exit(0);
    }

    // we're reading and printing out the number of wizards from the first line
    ifile >> numEmp;
    
    employee * empInfo = create_employee(numEmp);

    // fill data
    get_employee_info(empInfo, numEmp, ifile);

    ifile.close();

    display_emp(empInfo, numEmp);

    delete_employee(&empInfo);

    return 0;
}
