#include <iostream>
#include <fstream>
#include <string>

#include "student_db.h"

using namespace std;

/*
 * File exists
*/
bool file_exist(const char *fileName)
{
    ifstream infile(fileName);
    return infile.good();
}

/*
 * Main function 
*/
int main(int argc, char *argv[])
{

    // check for correct number of arguments
    if (argc != 2)
    {
        cout << "Incorrect number of arguments, exiting." << endl;
        return 2;
    }

    // first check that the file exists
    if (file_exist(argv[1]))
    {
        // open the file and put the first number in
        int numStudents;
        string temp;
        int userChoice;

        ifstream ifile(argv[1]);

        // read data from file
        if (ifile.fail() || !ifile)
        {
            cout << "Error in opening student file...!!" << endl;
            exit(0);
        }

        // we're reading and printing out the number of wizards from the first line
        ifile >> numStudents;

        student *studentInfo = create_student_db(numStudents);

        // loop to fill in data
        get_student_db_info(studentInfo, numStudents, ifile);

        ifile.close();

        bool exit = false;

        do {
            cout << "Sort by (1) ID, (2) Last Name, or (3) exit?" << endl;
            cin >> userChoice;

            switch (userChoice)
            {
                case 1:
                    studentInfo = sort_id(studentInfo, numStudents);
                    display_students(studentInfo, numStudents);
                    break;
                case 2:
                    studentInfo = sort_lastname(studentInfo, numStudents);
                    display_students(studentInfo, numStudents);
                    break;
                case 3:
                    cout << "Bye!" << endl;
                    exit = true;
                    break;
                default:
                    cout << "Bye!" << endl;
                    return 2;
            }

        } while (exit == false);

        delete_student_db_info(&studentInfo);
    }
    else
    {
        cout << "The file type is incorrect, exiting." << endl;
        return 0;
    }
}