/*********************************************************************
** Program Filename: Blackbear.cpp
** Author: Andrea Tongsak
** Date: 11/5/2020
** Description: The file with the definitions for the Blackbear class
** Input:
** Output:
*********************************************************************/

#include "BlackBear.h"

BlackBear::BlackBear() {
    set_age(4*12);
    set_cost(6000);
    set_numBabies(2);
    set_revenue(600);
    
    set_canReproduce(true);
    set_isSick(false);
    set_isDead(false);
    
    set_feedingCost(100);
    
    set_name("Berenstain");
    
}

BlackBear::BlackBear(string nameIn, int ageIn) : Animal(nameIn, ageIn) {
    set_age(ageIn);
    
    set_name(nameIn);
}