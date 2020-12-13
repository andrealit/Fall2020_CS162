#ifndef student_db_h
#define student_db_h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct student {
    long id;
    string firstName;
    string lastName;
    string major;
};

// create student
student* create_student_db(int);

// get student info
void get_student_db_info(student *, int, ifstream &);

// delete student info
void delete_student_db_info(student **);

// swap
void swap(student *st1, student *st2);

// sort by id number
student * sort_id(student* stArr, int numSt);

// sort by last name
student * sort_lastname(student* stArr, int numSt);

// assign each name to a number
int lastname_num();

// display the sort
void display_students(student * stArr, int numSt);


#endif