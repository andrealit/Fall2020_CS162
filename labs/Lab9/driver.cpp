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

#include "Sort.h"

using namespace std;

/*
* Function: main
* Description: processes the command line arguments and starts game
* Parameters: command line arguments
* Pre-Conditions: the command line is passed
* Post-Conditions: this will return the game
*/
int main(int argc, char * argv[]) {
    Sort sorting;

    sorting.create_array();
    //sorting.num_input();
    
    return 0;
}