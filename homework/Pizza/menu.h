//
//  menu.hpp
//  PizzaPortal
//
//  Created by Andrea Tongsak on 10/3/20.
//  Copyright © 2020 Andrea Tongsak. All rights reserved.
//

#ifndef MENU_H
#define MENU_H

#include <string>
#include <fstream>
#include "pizza.h"

using namespace std;

class Menu {
  private:
    int num_pizzas;
    Pizza* pizzas;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    Menu();
    ~Menu();
    Menu(const Menu&);
    
    int get_num_pizzas();
    void set_num_pizzas(int numP);
    
    Pizza* get_pizzas();
    void set_pizzas(Pizza* pizza);

    // Only one of the following two prototypes should be used:
    Menu search_pizza_by_cost(int upper_bound);
    //Menu search_pizza_by_cost(int upper_bound, string size);

    Menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients);
    Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients);
    void add_to_menu(Pizza pizza_to_add);
    void remove_from_menu(int index_of_pizza_on_menu);
    
    // populate pizzas
    void populate_menu_data(ifstream& file);
};

#endif
