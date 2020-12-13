/*********************************************************************
** Program Filename: Animal.h
** Author: Andrea Tongsak
** Date: 10/29/2020
** Description: The file with the declaration for the Animal class
** Input:
** Output:
*********************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;

class Animal {
    private:
        string species;
        int age;
        int cost;
        int numOfBabies;
        int revenue;
    
        bool canReproduce;
    
        bool isBaby;
        bool isSick;
        bool isDead;
    
        int feedingCost;

        string name;
    public:
        Animal();
        Animal(string, int);
    
        // Big Three for Animal
        Animal(const Animal&);
        Animal& operator= (const Animal &);
        ~Animal();
    
        string get_species();
        void set_species(string);

        string get_name();
        void set_name(string);

        int get_age();
        void set_age(int);

        void increment_age();

        int get_cost();
        void set_cost(int);
    
        int get_revenue();
        void set_revenue(int);

        int get_numBabies();
        void set_numBabies(int);

        bool get_canReproduce();
        void set_canReproduce(bool);

        bool get_isSick();
        void set_isSick(bool);

        bool get_isDead();
        void set_isDead(bool);
        
        int get_feedingCost();
        void set_feedingCost(int);
        
};

#endif
