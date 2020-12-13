#ifndef course_h
#define course_h

#define ENROLL_CAP 100

#include <iostream>
#include <string>

using namespace std;

class Course {
    private:
        string name;
        string instructor;
        string roster[ENROLL_CAP];
        int num_enrolled;
    public:
        string get_name();
        void set_name(string temp);

        string get_instructor();
        void set_instructor(string temp);

        int get_num_enrolled();
        void set_num_enrolled(int temp);

        void enroll_students(string, int);
}

#endif