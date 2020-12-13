/******************************************************
** Program: SeaLion.cpp
** Author: Andrea Tongsak
** Date: 10/29/2020
** Description: The sea lion class
** Input: -
** Output: -
******************************************************/

#include <iostream>
#include "SeaLion.h"

/*
* Function: Sea Lion Constructor
* Description: get the sea lion
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Sea Lion is created
 */
SeaLion::SeaLion() {
    // set the bonus revenue
    set_age(4*12);
    set_cost(800);
    set_numBabies(1);
    set_revenue(160);
    
    set_canReproduce(true);
    set_isSick(false);
    set_isDead(false);
    
    set_feedingCost(100);
    
    set_name("Peter");

}

/*
* Function: Sea Lion Constructor with Parameter
* Description: create the sea lion
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Sea Lion is crafted
 */
SeaLion::SeaLion(string nameIn, int ageIn) : Animal(nameIn, ageIn) {
    
    set_age(ageIn);
    
    set_name(nameIn);
    

}
