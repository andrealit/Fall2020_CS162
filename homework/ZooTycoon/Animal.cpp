/******************************************************
** Program: Animal.cpp
** Author: Andrea Tongsak
** Date: 10/29/2020
** Description: The animal definition file
** Input: -
** Output: -
******************************************************/

#include <iostream>
#include <string>

#include "Animal.h"

using namespace std;

/*
* Function: Animal Constructor
* Description: Creates the hand
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Animal::Animal() {
    species = "General";
    this->age = 0;
    this->cost = 0;
    this->numOfBabies = 0;
    this->revenue = 0;
    
    this->isBaby = false;
    this->isSick = false;
    this->isDead = false;
    
    this->feedingCost = 0;
    
    this->name = "Animal";
}

/*
* Function: Animal Constructor with parameters
* Description: The name is passed into the Constructor
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Animal::Animal(string name, int age) {
    species = "General";
    this->age = age;
    this->cost = 0;
    this->numOfBabies = 0;
    this->revenue = 0;
    
    this->isBaby = false;
    this->isSick = false;
    this->isDead = false;
    
    this->feedingCost = 0;
    
    this->name = "name";
}

/*
* Function: Animal Copy Constructor
* Description: The information from one class is copied over to another
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Animal::Animal(const Animal& oldanimal) {
    this->species = oldanimal.species;
    this->age = oldanimal.age;
    this->cost = oldanimal.cost;
    this->numOfBabies = oldanimal.numOfBabies;
    this->revenue = oldanimal.revenue;
    
    this->isBaby = oldanimal.isBaby;
    this->isSick = oldanimal.isSick;
    this->isDead = oldanimal.isDead;
    
    this->feedingCost = oldanimal.feedingCost;
    
    this->name = oldanimal.name;
}


/*
* Function: Animal Assignment Operator Overload
* Description: The assignment operator overload for the animal class,
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Animal& Animal::operator=(const Animal & oldanimal) {

    this->species = oldanimal.species;
    this->age = oldanimal.age;
    this->cost = oldanimal.cost;
    this->numOfBabies = oldanimal.numOfBabies;
    this->revenue = oldanimal.revenue;
    
    this->isBaby = oldanimal.isBaby;
    this->isSick = oldanimal.isSick;
    this->isDead = oldanimal.isDead;
    
    this->feedingCost = oldanimal.feedingCost;
    
    this->name = oldanimal.name;
    
    return *this;
}


/*
* Function: Destructor
* Description: Destroy the animal
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Animal::~Animal() {
    // destroy the animal
}

/*
* Function: get_species
* Description: Accessor for species
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
string Animal::get_species() {
    return this->species;
}

/*
* Function: set_species
* Description: Mutator for species
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
void Animal::set_species(string speciesIn) {
    speciesIn = species;
}

/*
* Function: get_name
* Description: Accessor for name
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The name is returned
 */
string Animal::get_name() {
    return this->name;
}

/*
* Function: set_name
* Description: Mutator the hand
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The name is set
 */
void Animal::set_name(string nameIn) {
    nameIn = name;
}

/*
* Function: get_age
* Description: Accessor for the age
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The age is set
 */
int Animal::get_age() {
    return this->age;
}

/*
* Function: set_age
* Description: Mutator for the age
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The age is set
 */
void Animal::set_age(int ageIn) {
    this->age = ageIn;
}

/*
* Function: increment_age
* Description: increase the age for one month
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The age is added
 */
void Animal::increment_age() {
    this->age++;
}

/*
* Function: get_cost
* Description: get the cost for the animal
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Return the cost
 */
int Animal::get_cost() {
    return this->cost;
}

/*
* Function: set_cost
* Description: get the cost for the animal
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Return the cost
 */
void Animal::set_cost(int costIn) {
    this->cost = costIn;
}

/*
* Function: get_revenue
* Description: get the revenue for the animal
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Return the revenue
 */
int Animal::get_revenue() {
    return this->revenue;
}

/*
* Function: set_revenue
* Description: set the revenue for the animal
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Set the revenue
 */
void Animal::set_revenue(int rev) {
    this->revenue = rev;
}

/*
* Function: get_numBabies
* Description: get the cost for the animal
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Return the cost
 */
int Animal::get_numBabies() {
    return this->numOfBabies;
}

/*
* Function: set_numBabies
* Description: get the cost for the animal
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Return the cost
 */
void Animal::set_numBabies(int babies) {
    this->numOfBabies = babies;
}

/*
* Function: get_canReproduce
* Description: whether the animal can reproduce
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: We know if the animal is reproduce
 */
bool Animal::get_canReproduce() {
    return this->canReproduce;
}

/*
* Function: set_canReproduce
* Description: set the animal's ability to reproduce
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The animal is set to reproduce
 */
void Animal::set_canReproduce(bool reproduce) {
    this->canReproduce = reproduce;
}

/*
* Function: get_isSick
* Description: check if the animal isSick
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: return if the animal is sick
 */
bool Animal::get_isSick() {
    return this->isSick;
}

/*
* Function: get_isSick
* Description: check if the animal isSick
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: set if the animal is sick
 */
void Animal::set_isSick(bool sick) {
    this->isSick = sick;
}

/*
* Function: get_isDead
* Description: check if the animal isDead (basically happens if the animal is so sick and then isn't healed)
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: we know the animal is dead
 */
bool Animal::get_isDead() {
    return this->isDead;
}

/*
* Function: set_isDead
* Description: check if the animal isDead (basically happens if the animal is so sick and then isn't healed)
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: we know the animal is dead
 */
void Animal::set_isDead(bool dead) {
    this->isDead = dead;
}

/*
* Function: get_feedingCost()
* Description: feeding cost is accessed
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The feeding cost is left
 */
int Animal::get_feedingCost() {
    return this->feedingCost;
}

/*
* Function: get_feedingCost()
* Description: feeding cost is accessed
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The feeding cost is left
 */
void Animal::set_feedingCost(int feed) {
    this->feedingCost = feed;
}
