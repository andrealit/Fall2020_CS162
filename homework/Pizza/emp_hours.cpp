/*********************************************************************
** Program Filename: emp_hours.cpp
** Author: Andrea Tongsak
** Date: 10/3/2020
** Description: The file with employee struct and hour
** Input: 
** Output:
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "emp_hours.h"

using namespace std;

/*
 * function: create_employee
 * description: create the employee struct for filling
 * parameters: size
 * pre-conditions: no employee struct is yet created
 * post-condition: the empty employee struct is created
*/
employee* create_employee(int size) {
    employee *temp = new employee[size];
    return temp;
}

/*
 * function: get_employee_info
 * description: fill in the employee database with information from file
 * parameters: emp *, int, and fstream
 * pre-conditions: the database is not filled at the index
 * post-condition: the emp struct is filled
*/
void get_employee_info(employee* emp, int num, ifstream & file) {
    int tempId;
    string temp;

    for (int i = 0; i < num; i++) {
        file >> tempId;
        emp[i].id = tempId;
        file >> temp;
        emp[i].password = temp;
        file >> temp;
        emp[i].first_name = temp;
        file >> temp;
        emp[i].last_name = temp;
    }
}

/*
 * function: delete_employee
 * description: delete employee information to clear struct
 * parameters: emp *
 * pre-conditions: the database is filled at the index
 * post-condition: it's emptied
*/
void delete_employee(employee ** arr) {
    delete [] (*arr);
    (*arr) = NULL;
}

/*
* Function: display_emp
* Description: display the employees, sorted
* Parameters: take in a employee array and the number of empl
* Pre-Conditions: the emp array is unprinted
* Post-Conditions: printed to user
 */
void display_emp(employee * empArr, int numEm) {
    for (int i = 0; i < numEm; i++) {
        cout << empArr[i].id << " " << empArr[i].last_name << endl;
    }
}

