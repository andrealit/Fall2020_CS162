#include <iostream>
#include "course.h"

using namespace std;

string Course::university = "Oregon State University";

// default constructor
Course () {
    this->name = " ";
    this->instructor = " ";
    this->static string = " ";
    this->string *roster = 
    this->int enrollment_cap = 100;
    this->int current_enrollment = 0;

}


// alternate constructor
 {




}

// the destructor
 {


}

// define a copy constructor
// this will be automatically used anytime that a new Course object is
// created from an existing Course object
 {










}

// define an assignment operator overload
// this will be used when an *existing* Course object is set equal to another
Course object
 {
    




}

void Course::set_name(string name) {
	this->name = name;
}

void Course::set_instructor(string name) {
	this->instructor = name;
}

void Course::set_university(string univ) {
	// since this function was declared as static in the header file,
	// there is no "this" pointer
	// for example, this->university is not valid in here!
	university = univ;
}

void Course::set_current_enrollment(int new_enrollment) {
	current_enrollment = new_enrollment;
}

string Course::get_name() const {
	return name;
}

string Course::get_instructor() const {
	return instructor;
}

// this function is declared as static
// but only the header file needs to mention this
string Course::get_university() {
	return university;
}

void Course::enroll_student(string student_name) {
	if (current_enrollment == enrollment_cap) {
		return;
	}

	roster[current_enrollment] = student_name;
	current_enrollment++;
}

void Course::display_enrollment() const {
	for (int i = 0; i < current_enrollment; i++) {
		cout << i << ": " << roster[i] << endl;
	}
}
