#include <iostream>
#include <fstream>
#include <string>

#include "student_db.h"

using namespace std;

/*
 * function: create_student_db
 * description: create the student struct for filling
 * parameters: index
 * pre-conditions: no student struct is yet created at the index
 * post-condition: the empty student struct is created
*/
student * create_student_db(int index) {
    student *temp = new student[index];
    return temp;
}

/*
 * function: get_student_db_info
 * description: fill in the student database with information from file
 * parameters: student *, int, and fstream
 * pre-conditions: the database is not filled at the index
 * post-condition: the student struct is filled
*/
void get_student_db_info(student * student, int num, ifstream &file) {
    string temp;
    long tempid;
    for (int i = 0; i < num; i++) {
        file >> tempid;
        student[i].id = tempid;
        file >> temp;
        student[i].firstName = temp;
        file >> temp;
        student[i].lastName = temp;
        file >> temp;
        student[i].major = temp;
    }

}

/*
 * function: delete_student_db_info
 * description: delete student information to clear struct
 * parameters: student *
 * pre-conditions: the database is filled at the index
 * post-condition: it's emptied
*/
void delete_student_db_info(student ** arr) {
    delete [] (*arr);
    (*arr) = NULL;
}

/*
* Function: swap
* Description: is the bubble sort helper method
* Parameters: take in the two student arrays using pointers
* Pre-Conditions: assume that value 2 is greater
* Post-Conditions: the two students are sorted
 */
void swap(student *st1, student *st2) {
    student temp = *st1;
    *st1 = *st2;
    *st2 = temp;
}


/*
* Function: sort_id
* Description: sorts the students by id
* Parameters: take in a student arrays, and the number of students
* Pre-Conditions: the student array is filled but unsorted
* Post-Conditions: sorted by id
 */
student * sort_id(student* stArr, int numSt) {
    bool swapped;
    for (int i = 0; i < numSt - 1; i++) {
        
        swapped = false;
        for (int j = 0; j < numSt - i - 1; j++) {
            // bubble sort
            if (stArr[j].id > stArr[j+1].id) {
                // switch the two
                swap(&stArr[j], &stArr[j+1]);
                swapped = true;
            }
        }
        
        if (swapped == false) {
            break;
        }

    }

    return stArr;
}

/*
* Function: sort_lastname
* Description: sorts the students by last name
* Parameters: take in a student arrays, and the number of students
* Pre-Conditions: the student array is filled but unsorted
* Post-Conditions: sorted by last name
 */
student * sort_lastname(student * stArr, int numSt) {
    bool swapped;
    for (int i = 0; i < numSt - 1; i++) {
        swapped = false;
        for (int j = 0; j < numSt - i - 1; j++) {
            if (stArr[j].lastName > stArr[j+1].lastName) {
                swap(&stArr[j], &stArr[j+1]);
                swapped = true;
            }
        }
        
        if (swapped == false) {
            break;
        }

    }
    return stArr;

}

/*
* Function: display_students
* Description: display the students, sorted
* Parameters: take in a student arrays, and the number of students
* Pre-Conditions: the student array is unprinted
* Post-Conditions: printed to user
 */
void display_students(student * stArr, int numSt) {
    for (int i = 0; i < numSt; i++) {
        cout << stArr[i].id << " " << stArr[i].lastName << ", " << stArr[i].firstName << endl;
    }
}


