/*********************************************************************
 ** Program Filename: driver.cpp
 ** Author: Andrea Tongsak
 ** Date: 11/23/2020
 ** Description: The main method
 ** Input: 
 ** Output:
 *********************************************************************/

#include <iostream>
#include <stdexcept>

#include "Linked_List.h"
#include "Linked_List.cpp"
#include "Node.h"

using namespace std;

/**
 * Function: main
 * Description: processes the command line arguments and starts game
 * Parameters: command line arguments
 * Pre-Conditions: the command line is passed
 * Post-Conditions: this will return the game
 */
int main(int argc, char * argv[]) {
    int templateType;

    // ask user if they want to do unsigned int or int.
    cout << "Would you like to sort (1) INT or (2) UNSIGNED INT: ";
    
    do {
        while (!(cin >> templateType)) {
            cout << "Enter (1 or 2): ";
            cin.clear();
            cin.ignore();
        }

    } while (templateType != 1 && templateType != 2);
    

    if (templateType == 1) {
        Linked_List<int> list;
        list.cycle();
    } else if (templateType == 2) {
        Linked_List<unsigned int> list;
        list.cycle();
    }   

    
    
}