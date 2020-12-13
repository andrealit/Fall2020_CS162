/******************************************************
** Program: Tiger.cpp
** Author: Andrea Tongsak
** Date: 10/29/2020
** Description: The tiger class
** Input: -
** Output: -
******************************************************/

#include <iostream>

#include "Tiger.h"

Tiger::Tiger() {
    set_species("Tiger");
    set_age(4*12);
    set_cost(15000);
    set_numBabies(3);
    set_revenue(1500);
    
    set_canReproduce(true);
    set_isSick(false);
    set_isDead(false);
    
    set_feedingCost(100);
    
    set_name("Daniel");
    
}

Tiger::Tiger(string nameIn, int ageIn) : Animal(nameIn, ageIn) {
    cout << "Alternate tiger constructor called." << endl;
    
    set_age(ageIn);
    
    set_name(nameIn);
}



