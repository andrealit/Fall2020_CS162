#ifndef COURSE_H
#define COURSE_H
#include <iostream>
using namespace std;
#define DEFAULT_ENROLLMENT_CAP 100
class Course {
    private:string name;
    string instructor;
    static string university;
    string *roster;
    int enrollment_cap;
    int current_enrollment;
    public:
        Course(); // default constructorCourse(int); 
        Course(int); // destructor (there can be only one)
        ~Course(); // copy constructor
        Course(const Course&); // copy constructor
        Course& operator=(const); // assignment operator
        
        void set_instructor(string);
        static void set_university(string);
        void set_current_enrollment(int);
        string get_name() const;
        string get_instructor() const;
        static string get_university();
        void enroll_student(string);
        void display_enrollment() const;
    };
#endif