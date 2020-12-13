//
//  menu.cpp
//  PizzaPortal
//
//  Created by Andrea Tongsak on 10/3/20.
//  Copyright © 2020 Andrea Tongsak. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

#include "menu.h"

/*
* Function: Menu Constructor
* Description: Default constructor for Menu
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Menu::Menu() {
    this->num_pizzas = 0;
    this->pizzas = nullptr;
}

/*
* Function: Menu Destructor
* Description: Deletes memory for Menu
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Menu::~Menu() {
    if (this->pizzas != nullptr) {
        delete [] this->pizzas;
    }
    this->pizzas = nullptr;
}

Menu::Menu(const Menu& old) {
    this->num_pizzas = old.num_pizzas;
    //this->pizzas = new Pizza[old]
}

/*
* Function: get_num_pizzas
* Description: Returns the number of pizzas
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
int Menu::get_num_pizzas() {
    return this->num_pizzas;
}

/*
* Function: set_num_pizzas
* Description: Sets the value for number of pizzas
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
void Menu::set_num_pizzas(int numP) {
    this->num_pizzas = numP;
}

/*
* Function: get_pizzas
* Description: gets the pizza pointer
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Pizza* Menu::get_pizzas() {
    return this->pizzas;
}

/*
* Function: search_pizza_by_cost
* Description: helps user look for the pizza on menu by cost
* Parameters: int
* Pre-Conditions: the menu is filled
* Post-Conditions: the correct menu is given
 */
Menu Menu::search_pizza_by_cost(int upper_bound) {
    
    for (int i = 0; i < get_num_pizzas(); i++) {
        if (this->pizzas[i].get_small_cost() > upper_bound) {
            return Menu();
        }
    }
    
    return Menu();
}



void Menu::remove_from_menu(int index) {
    if (index >= get_num_pizzas() || index < 0) {
        cout << "Incorrect index..." << endl;
        return;
    }
    // remove item at index
    cout << "Remove: " << this->pizzas[index].get_name() << endl;
    for (int i = 0; i < this->get_num_pizzas(); i++) {
        this->pizzas[i] = this->pizzas[i+1];
    }
    // decrease the amount of items
    this->num_pizzas--;
}

void Menu::populate_menu_data(ifstream& file) {
    while (!file.eof()) {
        this->set_num_pizzas(this->get_num_pizzas() + 1);
        
    }
    file.close();
    cout << "file closed." << endl;
}
