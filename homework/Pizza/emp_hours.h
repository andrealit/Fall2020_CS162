/*********************************************************************
** Program Filename: emp_hours.h
** Author: Andrea Tongsak
** Date: 10/3/2020
** Description: The file with employee struct and hour
** Input:
** Output:
*********************************************************************/

#ifndef EMP_HOURS_H
#define EMP_HOURS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct employee {
  int id;
  string password;
  string first_name;
  string last_name;
};

struct hours {
  string day;
  string open_hour;
  string close_hour;
};

// open employee file
void openEmployee(char *file);

// allocate employee struct for text read-in
employee* create_employee(int);

// get employee info
void get_employee_info(employee*, int, ifstream &);

// delete employee struct after
void delete_employee(employee**);

// display the employee info
void display_emp(employee *, int);

#endif
