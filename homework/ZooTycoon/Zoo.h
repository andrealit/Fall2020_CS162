/******************************************************
** Program: Zoo.h
** Author: Andrea Tongsak
** Date: 10/29/2020
** Description: The zoo header file
** Input: -
** Output: -
******************************************************/

#ifndef Zoo_hpp
#define Zoo_hpp

#include <iostream>

#include "SeaLion.h"
#include "Tiger.h"
#include "BlackBear.h"

class Zoo {
    private:
        // initialize a dynamic array
        SeaLion *exhibitSeaLion;
        int numSeaLions; // the total number in the zoo
        int bought_SL; // number of Sea Lions bought
    
        Tiger *exhibitTiger;
        int numTigers;
        int bought_T;
    
        BlackBear *exhibitBlackBear;
        int numBlackBears;
        int bought_B;
    
        int numAnimals; // num animals
    
        double bank; // how much money is in the zoo
        double foodBase;
    
        int sickCosts; // the costs of sick animals
    
        int time; // how long has this zoo been around in months?
    
        bool monthBuy; // has the player bought animals this month?
    
        int animalBuy; // the number of animals the player has bought this month
    
        string user_name;
    
    public:
        // Zoo Constructor
        Zoo();
        // Zoo Destructor
        ~Zoo();
    
        // Zoo Copy Constructor
        Zoo(const Zoo&);
        
        // Zoo Assignment Constructor
        Zoo& operator=(const Zoo);
    
        // Print out the entire Zoo
        void printZoo();
        // Print out the bank
        void print_bank();
        // Check if the bank is empty
        bool bank_empty();
    
        // Monthly choices
        bool month_choices();
        // Choose animal
        int choose_animal();
        // How many animals?
        int many_animal();
        // Buy the animal
        void buy_animal(int, int);
    
        // Setters for the exhibits
        void set_exhibit_sl(SeaLion *);
        void set_exhibit_bb(BlackBear *);
        void set_exhibit_t(Tiger *);
    
        // Get each number of animal (for calculation)
        int get_num_bb();
        int get_num_sl();
        int get_num_tigers();
    
        // get the current bank amount
        double get_bank();
        
        // ADDING ANIMALS to Zoo (either baby or bought)
        void addSeaLion(SeaLion&, int);
        void addTiger(Tiger&, int);
        void addBlackBear(BlackBear&, int);
    
        // REMOVE THE ANIMALS (Once dead)
        void removeSeaLion(int&); // uses the place in the array
        void removeTiger(int&);
        void removeBlackBear(int&);
    
        // CHOOSE A SICK ANIMAL
        void pick_sick();
    
        // HEAL THE SICK ANIMAL
        void sick_animal(int, int);
    
        // ANIMAL DIES
        void animal_dies(int, int);
    
        // GIVES BIRTH
        void gives_birth();
    
        // Boom in zoo attendance
        int boom_zoo(int, int);
    
        // Calculate revenue
        void calculateRevenue(bool);
        
        // Ask the user whether they want to buy an animal
        bool ask_to_buy();
    
        // Deduct the bank cost of the animal
        void deduct_bank(double);
    
        // Calculate food costs
        double calc_food(double);
    
        // Random special event
        bool random_event();
    
        // time passes in the zoo, animals age
        void add_time();
    
        // select the food
        void select_food();
    
        // zoo cycle
        double zoo_cycle(double);
    
        // past month feed helper method
        double month_feed(double);
    
        // increase age
        void increment_age();
    
        // get the time
        int get_time() const;

        // count babies for extra revenue
        int count_babies(int, int);
    
};

#endif /* Zoo_hpp */
