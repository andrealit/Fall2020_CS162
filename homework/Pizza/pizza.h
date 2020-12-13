//
//  pizza.h
//  PizzaPortal
//
//  Created by Andrea Tongsak on 10/3/20.
//  Copyright © 2020 Andrea Tongsak. All rights reserved.
//

#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <fstream>

using namespace std;

class Pizza {
  private:
    string name;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;
    string* ingredients;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    
    // constructor and destructor
    Pizza();
    ~Pizza();
    Pizza(const Pizza&);
    
    
    string get_name();
    void set_name(string);
    
    int get_small_cost();
    void set_small_cost(int);
    
    int get_medium_cost();
    void set_medium_cost(int);
    
    int get_large_cost();
    void set_large_cost(int);
    
    int get_num_ingredients();
    void set_num_ingredients(int);
    
    string* get_ingredients();
    void set_ingredients(string, int);
    void set_ingredients(string);
    
    void populate_pizza_data(ifstream &);
    
    
};

#endif
