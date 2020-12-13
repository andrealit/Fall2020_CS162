/*********************************************************************
** Program Filename: SeaLion.h
** Author: Andrea Tongsak
** Date: 10/29/2020
** Description: The header file for the Sea Lion
** Input:
** Output:
*********************************************************************/

#ifndef SEALION_H
#define SEALION_H

#include <iostream>
#include "Animal.h"

using namespace std;

class SeaLion : public Animal {
    public:
        SeaLion();
        SeaLion(string, int);

    private:
        // Note that sea lions have extra properties
        int bonusRevenue;


};

#endif
