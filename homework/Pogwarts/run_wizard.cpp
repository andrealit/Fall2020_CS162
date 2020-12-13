/*********************************************************************
 ** Program Filename: run_wizard.cpp
 ** Author: Andrea Tongsak
 ** Date: 9/23/2020
 ** Description: The main method where the wizard text file is opened and the spellbook text file is opened
 ** Input: The two command line arguments (wizard.txt, spellbook.txt)
 ** Output: sorted file to the screen or an output file
 *********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "catalog.h"

using namespace std;

/*
* Function: file_exist
* Description: takes in the file
* Parameters: takes in a file name
* Pre-Conditions: the file name is processed
* Post-Conditions: this will return whether the file exists
*/
bool file_exist(const char * fileName) {
    ifstream infile(fileName);
    return infile.good();
}

/*
* Function: main
* Description: processes files and starts sort
* Parameters: command line arguments
* Pre-Conditions: the command line is passed
* Post-Conditions: this will return the program abilities
*/
int main(int argc, char* argv[]) {
    
    bool isStudent;
    
    // command line functionality check
    if (argc != 3) {
        cout << "Not the correct number of arguments, exiting." << endl;
        return 0;
    }
    
    // if 2 existent files are specified
    if (file_exist(argv[1]) && file_exist(argv[2])) {
        // opens, creates the wizard array, stores wizard data in a struct, closes, then clears array
        isStudent = openWizard(argv[1]);
        
        // open and closes the spell book safely.
        openSpellbk(argv[2], isStudent);
    } else {
        cout << "The file type is wrong, exiting." << endl;
        return 0;
    }
    
    return 0;
}


