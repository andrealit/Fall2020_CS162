#include <iostream>
#include <string>

#include "course.h"

using namespace std;

string Course::get_name() {
    return name;
}

void Course::set_name(string temp) {
    this->name = temp;
}

string Course::get_instructor() {
    return instructor;
}

void Course::set_instructor(string temp) {
    this->instructor = temp;
}

int Course::get_num_enrolled() {
    return num_enrolled;
}

void Course::set_num_enrolled(int temp) {
    this->num_enrolled = temp;
}

void Course::enroll_students(string student, int index) {
    this->roster[index] = student;
}
