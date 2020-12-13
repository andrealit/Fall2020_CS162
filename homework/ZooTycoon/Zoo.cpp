/******************************************************
** Program: Zoo.cpp
** Author: Andrea Tongsak
** Date: 10/29/2020
** Description: The zoo definition file
** Input: -
** Output: -
******************************************************/

#include "Zoo.h"

#include <iostream>
#include <string>

#include "SeaLion.h"
#include "Tiger.h"
#include "BlackBear.h"

using namespace std;

const double BANK = 100000.0;
const double BASE = 80.0;

/*
* Function: Zoo Constructor
* Description: Creates the zoo
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Zoo::Zoo()
{
    string playerName;

    cout << "Enter your name: ";

    getline(cin, playerName);

    user_name = playerName;

    exhibitSeaLion = NULL;
    numSeaLions = 0;
    bought_SL = 0;

    exhibitTiger = NULL;
    numTigers = 0;
    bought_T = 0;

    exhibitBlackBear = NULL;
    numBlackBears = 0;
    bought_B = 0;

    numAnimals = 0;

    bank = BANK;
    foodBase = BASE;

    sickCosts = 0;

    time = 0;

    monthBuy = false;

    animalBuy = 0;
}

/*
* Function: Zoo Destructor
* Description: Destroys the zoo
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Zoo::~Zoo()
{
    // Destroy the zoo
    if (exhibitSeaLion != NULL)
    {
        delete[] exhibitBlackBear;
    }

    if (exhibitTiger != NULL)
    {
        delete[] exhibitTiger;
    }

    if (exhibitSeaLion != NULL)
    {
        delete[] exhibitSeaLion;
    }
}

/*
* Function: Zoo Copy Constructor
* Description: Copies over the zoo
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Zoo::Zoo(const Zoo &oldzoo)
{
    if (exhibitSeaLion != NULL)
    {
        delete[] exhibitSeaLion;
    }
    exhibitSeaLion = new SeaLion[numSeaLions];
    for (int i = 0; i < numSeaLions; i++)
    {
        exhibitSeaLion[i] = oldzoo.exhibitSeaLion[i];
    }
    this->numSeaLions = oldzoo.numSeaLions;
    this->bought_SL = oldzoo.bought_SL;

    if (exhibitTiger != NULL)
    {
        delete[] exhibitTiger;
    }
    exhibitTiger = new Tiger[numTigers];
    for (int i = 0; i < numTigers; i++)
    {
        exhibitTiger[i] = oldzoo.exhibitTiger[i];
    }
    this->numTigers = oldzoo.numTigers;
    this->bought_T = oldzoo.bought_T;

    if (exhibitBlackBear != NULL)
    {
        delete[] exhibitBlackBear;
    }
    exhibitBlackBear = new BlackBear[numBlackBears];
    for (int i = 0; i < numBlackBears; i++)
    {
        exhibitBlackBear[i] = oldzoo.exhibitBlackBear[i];
    }
    this->numBlackBears = oldzoo.numBlackBears;
    this->bought_B = oldzoo.bought_B;

    this->numAnimals = oldzoo.numAnimals;

    this->bank = oldzoo.bank;
    this->foodBase = oldzoo.foodBase;

    this->sickCosts = oldzoo.sickCosts;

    this->time = oldzoo.time;

    this->monthBuy = oldzoo.monthBuy;

    this->animalBuy = oldzoo.animalBuy;
}

/**
 * Function: Zoo Copy Constructor
 * Description: Copies over the zoo
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: -
 */
Zoo &Zoo::operator=(const Zoo oldzoo)
{

    // check if this points to memory
    if (exhibitSeaLion != NULL)
    {
        delete[] exhibitSeaLion;
    }
    exhibitSeaLion = new SeaLion[numSeaLions];
    cout << "Sea Lions: " << numSeaLions << endl;
    for (int i = 0; i < numSeaLions; i++)
    {
        exhibitSeaLion[i] = oldzoo.exhibitSeaLion[i];
    }
    this->numSeaLions = oldzoo.numSeaLions;
    this->bought_SL = oldzoo.bought_SL;

    // tigers
    if (exhibitTiger != NULL)
    {
        delete[] exhibitTiger;
    }
    exhibitTiger = new Tiger[numTigers];
    cout << "Tiger: " << numTigers << endl;
    for (int i = 0; i < numTigers; i++)
    {
        exhibitTiger[i] = oldzoo.exhibitTiger[i];
    }
    this->numTigers = oldzoo.numTigers;
    this->bought_T = oldzoo.bought_T;

    // blackbear
    if (exhibitBlackBear != NULL)
    {
        delete[] exhibitBlackBear;
    }
    exhibitBlackBear = new BlackBear[numBlackBears];
    cout << "BlackBears: " << numBlackBears << endl;
    for (int i = 0; i < numBlackBears; i++)
    {
        exhibitBlackBear[i] = oldzoo.exhibitBlackBear[i];
    }
    this->numBlackBears = oldzoo.numBlackBears;
    this->bought_B = oldzoo.bought_B;

    this->numAnimals = oldzoo.numAnimals;

    this->bank = oldzoo.bank;
    this->foodBase = oldzoo.foodBase;

    this->sickCosts = oldzoo.sickCosts;

    this->time = oldzoo.time;

    this->monthBuy = oldzoo.monthBuy;

    this->animalBuy = oldzoo.animalBuy;

    return *this;
}

/**
 * Function: printZoo
 * Description: The zoo info is printed
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: The zoo is printed
 */
void Zoo::printZoo()
{
    cout << user_name << "'s Zoo Tycoon" << endl;
    cout << "   Number of Sea Lions: " << numSeaLions << endl;
    cout << "   Number of Tigers: " << numTigers << endl;
    cout << "   Number of Black Bears: " << numBlackBears << endl;

    cout << endl;

    cout << "   ";

    print_bank();

    cout << endl;

    cout << "   Total number of animals: " << numAnimals << endl;

    cout << "   Food costs: " << foodBase << endl;

    cout << "   Sick costs: " << sickCosts << endl;

    cout << "   Month: " << time << endl;

    //cout << "   Revenue: " << endl;

    return;
}

/**
 * Function: print_bank
 * Description: The bank amount is printed
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: The bank is printed
 */
void Zoo::print_bank()
{
    cout << "Bank: " << get_bank() << endl;
}

/**
* Function: bank_empty
* Description: The bank amount is returned
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The bank is returned
*/
bool Zoo::bank_empty()
{
    if (bank == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Function: monthly choice to buy
 * Description: The month's options is given to the user
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: The month is given
*/
bool Zoo::month_choices()
{
    bool valid = false;
    string s;
    int input;
    bool buying = false;

    cout << "It's a new month! It's month " << time << "." << endl;
    cout << "Would you like to buy animals? (y/n)" << endl;

    do
    {
        getline(cin, s);
        if (s == "y" || s == "Y")
        {
            valid = true;
            cout << "Buying animals..." << endl;
            buying = true;
        }

        if (s == "n" || s == "N")
        {
            valid = true;
            cout << "No animals bought this month..." << endl;
            buying = false;
        }

    } while (valid == false);

    return buying;
}

/**
 * Function: choose_animal
 * Description: The animal amount is printed
 * Parameters: the correct animal is bought
 * Pre-Conditions: -
 * Post-Conditions: The animal is added to the stock
 */
int Zoo::choose_animal()
{
    bool valid;
    string s;
    int input;
    int species = 0;

    cout << "Choose which species you'd like to purchase: " << endl;
    cout << "   1) Sea Lion     ($800)" << endl;
    cout << "   2) Tiger        ($15,000)" << endl;
    cout << "   3) Black Bear   ($6,000)" << endl;

    do
    {
        getline(cin, s);
        input = atoi(s.c_str());
        if (input < 1 || input > 3)
        {
            cout << "Try again." << endl;
            valid = false;
        }
        else
        {
            valid = true;
            species = input;
        }
    } while (valid == false);

    return species;
}

/**
* Function: many_animal
* Description: We ask how many of the species are added
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: We impose the condition that up to two can be added.
*/
int Zoo::many_animal()
{
    bool valid;
    string s;
    int input;
    int numSpecies = 0;

    cout << "How many of the species?" << endl;
    cout << "   1) x1" << endl;
    cout << "   2) x2" << endl;

    do
    {
        getline(cin, s);
        input = atoi(s.c_str());
        if (input < 1 || input > 2)
        {
            cout << "Try again." << endl;
            valid = false;
        }
        else
        {
            valid = true;
        }
    } while (valid == false);

    switch (input)
    {
        case 1:
        {
            cout << "One animal is bought." << endl;
            numSpecies = 1;
            break;
        }
        case 2:
        {
            cout << "Two animals are bought." << endl;
            numSpecies = 2;
            break;
        }
    }

    return numSpecies;
}

/**
* Function: buy_animal
* Description: The animal is added to the stock
* Parameters: species, amount
* Pre-Conditions: -
* Post-Conditions: The animal is added to the dynamic array, with their age (adults are 48 months)
*/
void Zoo::buy_animal(int species, int numSpecies)
{

    switch (species)
    {
    case 1:
    {
        cout << "Buying a Sea Lion..." << endl;
        for (int i = 0; i < numSpecies; i++)
        {
            if (bank < 800)
            {
                cout << "Not enough money to buy " << numSpecies << " sea lions." << endl;
                return;
            }
            SeaLion sl;
            addSeaLion(sl, 48);
            bought_SL++; // increase monthly count of SL was bought
            numAnimals++;
            deduct_bank(800);
        }
        break;
    }

    case 2:
    {
        cout << "Buying a Tiger..." << endl;
        for (int i = 0; i < numSpecies; i++)
        {
            if (bank < 15000)
            {
                cout << "Not enough money to buy " << numSpecies << " tigers." << endl;
                return;
            }
            Tiger tig;
            addTiger(tig, 48);
            bought_T++; // increase monthly count of T
            numAnimals++;
            deduct_bank(15000);
        }
        break;
    }

    case 3:
    {
        cout << "Buying a Black Bear..." << endl;
        for (int i = 0; i < numSpecies; i++)
        {
            if (bank < 6000)
            {
                cout << "Not enough money to buy " << numSpecies << " bears." << endl;
                return;
            }
            BlackBear bb;
            addBlackBear(bb, 48);
            bought_B++; // increase monthly count of B
            numAnimals++;
            deduct_bank(6000);
        }
        break;
    }
    }
}

/**
* Function: get_num_bb
* Description: get the number of black bears
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The number of black bears is added
*/
int Zoo::get_num_bb()
{
    return numBlackBears;
}

/**
* Function: get_num_sl
* Description: get the number of sea lions
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The number of sea lions is added
*/
int Zoo::get_num_sl()
{
    return numSeaLions;
}

/**
* Function: get_num_t
* Description: get the number of tigers
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The number of tigers is added
*/
int Zoo::get_num_tigers()
{
    return numTigers;
}

/**
 * Function: addSeaLion
 * Description: The sea lion is added
 * Parameters: sealion object
 * Pre-Conditions: -
 * Post-Conditions: The sea lion is added to the stock
 */
void Zoo::addSeaLion(SeaLion &sealionAdd, int age)
{
    if (numSeaLions == 0)
    { // create a new array
        exhibitSeaLion = new SeaLion[1];
        exhibitSeaLion[0] = sealionAdd;
        sealionAdd.set_age(age);
        ++numSeaLions;
    }
    else
    { // use the current array to add to the end
        ++numSeaLions;
        SeaLion *temp = new SeaLion[numSeaLions];

        for (int i = 0; i < numSeaLions; i++)
        { // assign the number of sea lions to the end
            if (i == (numSeaLions - 1))
            { // at the last place
                temp[i] = sealionAdd;
                sealionAdd.set_age(age);
            }
            else
            { // assign the values to the previous
                temp[i] = exhibitSeaLion[i];
                sealionAdd.set_age(age);
            }
        }

        delete[] exhibitSeaLion;
        exhibitSeaLion = temp;
        temp = NULL;
    }
}

/**
 * Function: addTiger
 * Description: The tiger is added
 * Parameters: tiger object
 * Pre-Conditions: -
 * Post-Conditions: The tiger is added to the stock
 */
void Zoo::addTiger(Tiger &tigerAdd, int age)
{
    if (numTigers == 0)
    { //  create a new array
        exhibitTiger = new Tiger[1];
        exhibitTiger[0] = tigerAdd;
        tigerAdd.set_age(age);
        ++numTigers;
    }
    else
    { // use the current array to add to the end
        ++numTigers;

        Tiger *temp = new Tiger[numTigers];

        cout << "addTiger function: " << numTigers << endl;

        for (int i = 0; i < numTigers; i++)
        { // assign the number of tigers to the end
            if (i == (numTigers - 1))
            {
                temp[i] = tigerAdd;
                tigerAdd.set_age(age);
            }
            else
            { // assign the value to the previous
                temp[i] = exhibitTiger[i];
                tigerAdd.set_age(age);
            }
        }

        delete[] exhibitTiger;
        exhibitTiger = temp;
        set_exhibit_t(exhibitTiger);
        temp = NULL;
    }

    return;
}

/**
* Function: addBlackBear
* Description: The black bear is added
* Parameters: black bear object
* Pre-Conditions: -
* Post-Conditions: The black bear is added to the stock
*/
void Zoo::addBlackBear(BlackBear &blackBearAdd, int age)
{
    if (numBlackBears == 0)
    { // create a new array
        exhibitBlackBear = new BlackBear[1];
        exhibitBlackBear[0] = blackBearAdd;
        blackBearAdd.set_age(age);
        ++numBlackBears;
    }
    else
    {
        ++numBlackBears;
        BlackBear *temp = new BlackBear[numBlackBears + 1];

        cout << "addBlackBears function: " << numBlackBears << endl;

        for (int i = 0; i < numBlackBears; i++)
        { // assign the number of blackbears to the end
            if (i == (numBlackBears - 1))
            {
                temp[i] = blackBearAdd;
                blackBearAdd.set_age(age);
            }
            else
            { // assign the value to the previous
                temp[i] = exhibitBlackBear[i];
                blackBearAdd.set_age(age);
            }
        }

        delete[] exhibitBlackBear;
        exhibitBlackBear = temp;
        set_exhibit_bb(exhibitBlackBear);
        temp = NULL;
    }

    return;
}

/**
* Function: removeSeaLion
* Description: A sea lion is removed
* Parameters: The correct place in the array
* Pre-Conditions: -
* Post-Conditions: The array is reshaped
*/
void Zoo::removeSeaLion(int &location)
{
    bool sealionFound = false;
    SeaLion sl;

    if (numSeaLions == 0)
    {
        cout << "None to remove." << endl;
        return;
    }
    else
    {
        // create a new array of the size
        SeaLion *temp = new SeaLion[numSeaLions - 1];

        for (int i = 0; i < numSeaLions - 1; i++)
        {
            // look for the sea lion
            if (i == location)
            {
                sealionFound = true;
                // remove the sea lion.
                sl = exhibitSeaLion[location];
            }

            if (sealionFound)
            {
                temp[i] = exhibitSeaLion[i + 1]; // iterate over
            }
            else
            {
                temp[i] = exhibitSeaLion[i]; // set as normal
            }
        }

        delete[] exhibitSeaLion;
        exhibitSeaLion = temp;
        set_exhibit_sl(exhibitSeaLion);
        temp = NULL;
    }

    numSeaLions--;
    numAnimals--;

    return;
}

/**
* Function: removeTiger
* Description: The tiger amount is printed
* Parameters: the location in the array
* Pre-Conditions: -
* Post-Conditions: The array is reshaped, without the tiger
*/
void Zoo::removeTiger(int &location)
{
    bool tigerFound = false;
    Tiger t;

    if (numSeaLions == 0)
    {
        cout << "None to remove." << endl;
        return;
    }
    else
    {
        // create a new array of the size
        Tiger *temp = new Tiger[numTigers - 1];

        for (int i = 0; i < numTigers - 1; i++)
        {
            // look for the sea lion
            if (i == location)
            {
                tigerFound = true;
                // remove the sea lion.
                t = exhibitTiger[location];
            }

            if (tigerFound)
            {
                temp[i] = exhibitTiger[i + 1]; // iterate over
            }
            else
            {
                temp[i] = exhibitTiger[i]; // set as normal
            }
        }

        delete[] exhibitTiger;
        exhibitTiger = temp;
        set_exhibit_t(exhibitTiger);
        temp = NULL;
    }

    numTigers--;
    numAnimals--;

    return;
}

/**
* Function: removeBlackBear
* Description: The black bear amount is printed
* Parameters: the location in the array
* Pre-Conditions: -
* Post-Conditions: The array is reshaped, without the black bear
*/
void Zoo::removeBlackBear(int &location)
{
    bool bbFound = false;
    BlackBear bb;

    if (numSeaLions == 0)
    {
        cout << "None to remove." << endl;
        return;
    }
    else
    {
        // create a new array of the size
        BlackBear *temp = new BlackBear[numBlackBears - 1];

        for (int i = 0; i < numBlackBears - 1; i++)
        {
            // look for the sea lion
            if (i == location)
            {
                bbFound = true;
                // remove the sea lion.
                bb = exhibitBlackBear[location];
            }

            if (bbFound)
            {
                temp[i] = exhibitBlackBear[i + 1]; // iterate over
            }
            else
            {
                temp[i] = exhibitBlackBear[i]; // set as normal
            }
        }

        delete[] exhibitBlackBear;
        exhibitBlackBear = temp;
        set_exhibit_bb(exhibitBlackBear);
        temp = NULL;
    }

    numBlackBears--;
    numAnimals--;

    return;
}

/**
* Function: deduct_bank
* Description: The bank amount is printed
* Parameters: the cost
* Pre-Conditions: -
* Post-Conditions: The bank is updated appropriately
*/
void Zoo::deduct_bank(double cost)
{
    bank -= cost;
}

/**
 * Function: random_event
 * Description: The event is generated
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: The random event is chosen
 */
bool Zoo::random_event()
{
    bool boom = false;

    // check if there are any animals in the zoo
    if (numAnimals == 0)
    {
        cout << "You have no animals! Special events can't apply to your zoo yet." << endl;
    }

    // use srand to chose between four events
    int event;
    srand(time); // Initialize random number generator
    event = rand() % 4;

    switch (event)
    {
        case 0:
        {
            cout << "One randomly chosen animal gets sick." << endl;
            pick_sick();
            break;
        }
        case 1:
        {
            cout << "A randomly chosen adult gives birth." << endl;
            gives_birth();
            break;
        }
        case 2:
        {
            cout << "A boom in zoo attendance occurs." << endl;
            //calculateRevenue(true);
            boom = true;
            break;
        }
        case 3:
        {
            cout << "No special event this month." << endl;
            break;
        }
    }

    return boom;
}

/**
 * Function: pick_sick
 * Description: choose a sick animal
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: the sick animal is chosen
 */
void Zoo::pick_sick()
{
    bool speciesExist = false;

    int species;
    srand(time); // Initialize random number generator
    species = rand() % 3;

    // check if the species exist
    //do
    //{
        switch (species)
        {
            case 0:
            { // Sea Lion
                if (numSeaLions == 0)
                {
                    speciesExist = false;
                }
                else
                {
                    sick_animal(0, numSeaLions);
                    speciesExist = true;
                }
                break;
            }
            case 1:
            { // Tiger
                if (numTigers == 0)
                {
                    speciesExist = false;
                }
                else
                {
                    sick_animal(1, numTigers);
                    speciesExist = true;
                }
                break;
            }

            case 2:
            { // Black Bear
                if (numBlackBears == 0)
                {
                    speciesExist = false;
                }
                else
                {
                    sick_animal(2, numBlackBears);
                    speciesExist = true;
                }
                break;
            }
        }
    //} while (speciesExist == false);

    return;
}

/**
* Function: sick_animal
* Description: choose a sick animal
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: the sick animal is chosen
*/
void Zoo::sick_animal(int species, int numSpecies)
{
    string ani;

    switch (species)
    {
    case 0:
        ani = "Sea Lion";
        break;
    case 1:
        ani = "Tiger";
        break;
    case 2:
        ani = "Black Bear";
        break;
    }

    // sick animal gets chosen
    cout << "A " << ani << " is sick." << endl;

    // choose the number of species
    switch (species)
    {
    case 0:
    { // sea lion
        int sealion;
        srand(time);
        sealion = rand() % numSeaLions;
        if (bank > 400)
        {
            deduct_bank(400);
            sickCosts = 400;
        }
        else
        {
            cout << "Not enough money to heal the sea lion." << endl;
            animal_dies(0, 0);
        }

        break;
    }
    case 1:
    { // tiger
        int tiger;
        srand(time);
        tiger = rand() % numTigers;
        if (bank > 7500)
        {
            deduct_bank(7500);
            sickCosts = 7500;
        }
        else
        {
            cout << "Not enough money to heal the tiger." << endl;
            animal_dies(1, 0);
        }

        break;
    }
    case 2:
    { // black bear
        int blackbear;
        srand(time);
        blackbear = rand() % numBlackBears;
        if (bank > 3000)
        {
            deduct_bank(3000);
            sickCosts = 3000;
        }
        else
        {
            cout << "Not enough money to heal the black bear." << endl;
            animal_dies(2, 0);
        }

        break;
    }
    }

    return;
}

/*
* Function: animal_dies
* Description: Check if the zoo owner has enough money
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The zoo owner has enough money
 */
void Zoo::animal_dies(int species, int animal)
{
    switch (species)
    {
        case 0:
        {
            cout << "Sea Lion " << exhibitSeaLion[animal].get_name() << " has died..." << endl;
            removeSeaLion(animal);
            break;
        }
        case 1:
        {
            cout << "Tiger " << exhibitTiger[animal].get_name() << " has died...." << endl;
            // remove it from the dynamic array.
            removeTiger(animal);
            break;
        }
        case 2:
        {
            cout << "Black bear " << exhibitBlackBear[animal].get_name() << "has died..." << endl;
            // remove it from the dynamic array.
            removeBlackBear(animal);
            break;
        }
    }
}

/*
* Function: gives_birth
* Description: The animal gives birth
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: A baby animal is added.
 */
void Zoo::gives_birth()
{
    bool speciesExist = false;
    bool adultFound = false;

    int species;
    srand(time);
    species = rand() % 3;

    cout << "An baby animal has arrived to your zoo!" << endl;

    //do {
    switch (species)
    {
    case 0:
    {
        if (numSeaLions == 0)
        {
            speciesExist = false;
        }
        else
        {
            // check the age?
            for (int i = 0; i < numSeaLions; i++)
            {
                if (exhibitSeaLion[i].get_age() > 48)
                {
                    cout << "There exists an adult!" << endl;
                    adultFound = true;
                    break;
                }
            }
            if (adultFound)
            {
                SeaLion sl;
                addSeaLion(sl, 0);
                numAnimals++;
            }
        }
        break;
    }
    case 1:
    {
        if (numTigers == 0)
        {
            speciesExist = false;
        }
        else
        {
            // check the age
            for (int i = 0; i < numTigers; i++)
            {
                if (exhibitTiger[i].get_age() > 48)
                {
                    cout << "There exists an adult!" << endl;
                    adultFound = true;
                    break;
                }
            }
            if (adultFound)
            {
                Tiger t1, t2, t3;
                addTiger(t1, 0);
                addTiger(t2, 0);
                addTiger(t3, 0);
                numAnimals++;
                numAnimals++;
                numAnimals++;
            }
        }
        break;
    }
    case 2:
    {
        if (numBlackBears == 0)
        {
            speciesExist = false;
        }
        else
        {
            for (int i = 0; i < numBlackBears; i++)
            {
                if (exhibitBlackBear[i].get_age() > 48)
                {
                    cout << "There exists an adult!" << endl;
                    break;
                }
            }
            if (adultFound)
            {
                BlackBear bb1, bb2;
                addBlackBear(bb1, 0);
                addBlackBear(bb2, 0);
                numAnimals++;
                numAnimals++;
            }
        }
        break;
    }
    }

    //} while (speciesExist == false && adultFound == false);
}

/*
 * Function: boom_zoo
 * Description: There is a boom in zoo attendance
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: The sea lion revenue is larger
 */
int Zoo::boom_zoo(int adult, int baby)
{
    int totalSL = 0;

    int extraRevenue;
    srand(time);
    extraRevenue = 150 + (rand() % 400);

    if (numSeaLions == 0)
    {
        totalSL = 0;
    }
    else
    {
        totalSL = (adult * extraRevenue) + (baby * extraRevenue * 2);
    }

    return totalSL;
}

/*
* Function: calculateRevenue
* Description: The revenue is calculated from the number of animals
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Revenue calculated
 */
void Zoo::calculateRevenue(bool isBoom)
{
    int total = 0;
    int babyTotal = 0;
    int adultTiger;
    int adultBear;
    int adultSeaLion;

    adultTiger = numTigers - count_babies(numTigers, 1);
    adultBear = numBlackBears - count_babies(numBlackBears, 2);
    adultSeaLion = numSeaLions - count_babies(numSeaLions, 3);

    if (isBoom)
    {
        cout << "A boom in zoo attendance has occurred, sea lions add extra $$$." << endl;
        // calculate babies with extra revenue
        total = (adultTiger * 1500) + (adultBear * 600) + (boom_zoo(adultSeaLion, count_babies(numSeaLions, 3)) * 160);
        bank += total;
    }
    else
    {
        // calculate babies with extra revenue
        babyTotal = count_babies(numTigers, 1) * 3000 + count_babies(numBlackBears, 2) * 1200 + count_babies(numSeaLions, 3) * 320;
        
        cout << "Baby Total: " << babyTotal << endl;
        total = (adultTiger * 1500) + (adultBear * 600) + (adultSeaLion * 160);
        cout << "Adult Total: " << total << endl;
        bank += total;
    }
}

/*
* Function: count_babies
* Description: The number of babies is calculated
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Babies calculated
 */
int Zoo::count_babies(int numAnimal, int species)
{
    int numBabies = 0;

    switch (species) {
        case 1: {
            for (int i = 0; i < numAnimal; i++)
            {
                if (exhibitTiger[i].get_age() < 6)
                {
                    numBabies++;
                }
            }
            break;
        }
        case 2: {
            for (int i = 0; i < numAnimal; i++)
            {
                if (exhibitBlackBear[i].get_age() < 6)
                {
                    numBabies++;
                }
            }
            break;
        }
        case 3: {
            for (int i = 0; i < numAnimal; i++)
            {
                if (exhibitSeaLion[i].get_age() < 6)
                {
                    numBabies++;
                }
            }
            break;
        }
    }
    
    return numBabies;
}

/*
* Function: calc_food
* Description: The monthly cost of food is calculated and deducted from the bank account
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Cost is needed for food
 */
double Zoo::calc_food(double pastMonthCost) {
    double foodTotal;

    // The base cost changes to a random value between 80% and 120% of the base cost from the month before.
    cout << "Months: " << time << endl;
    cout << "What is the prior month cost: " << pastMonthCost << endl;
    
    // choose the food percentage to multiply by
    int randomPercent;
    srand(time);
    randomPercent = 80 + (rand() % static_cast<int>(80 + 120 + 1));

    cout << "Random Percent: " << randomPercent << "%" << endl;
    
    double base;
    base = randomPercent * 0.01 * pastMonthCost;

    cout << "Calculation: " << base << endl;

    // The animal amount that is equal to a percentage of the initial cost of the species.
    double bearFood = get_num_bb() * base * 3;
    double sealionFood = get_num_sl() * base;
    double tigersFood = get_num_tigers() * base * 5;
    foodTotal = bearFood + sealionFood + tigersFood;

    foodBase = base;
    
    deduct_bank(foodTotal);

    return foodBase;

}

/*
* Function: add_time()
* Description: The month is added, all animals get older
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The zoo age is updated
 */
void Zoo::add_time() {
    time++;
}

/*
 * Function: select_food()
 * Description: Let the zoo owner choose what type of feed there is
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: This choice influences the probability of sickness
 */
void Zoo::select_food() {
    cout << "What food selection would you like to make?" << endl;
    cout << "   1) premium  " << endl;
    cout << "   2) regular  " << endl;
    cout << "   3) cheap    " << endl;
}

/*
* Function: set_exhibit_sl
* Description: The monthly sea lion exhibit is set
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Sea lion exhibit is set
 */
void Zoo::set_exhibit_sl(SeaLion * sl)
{
    exhibitSeaLion = sl;
}

/*
* Function: set_exhibit_bb
* Description: The monthly black bear exhibit is set
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: black bear exhibit is set
 */
void Zoo::set_exhibit_bb(BlackBear * bb)
{
    exhibitBlackBear = bb;
}

/*
* Function: set_exhibit_t
* Description: The monthly tiger exhibit is set
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Tiger exhibit is set
 */
void Zoo::set_exhibit_t(Tiger * t)
{
    exhibitTiger = t;
}

/*
* Function: get_bank
* Description: The value of bank is retrieved
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Bank is retrieved
 */
double Zoo::get_bank()
{
    return bank;
}

/*
* Function: zoo_cycle
* Description: The game reiterates: increase age, a special event occurs, recieves monthly revenue for animal, buy up to two adult animals of a single species
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Zoo cycle starts
 */
double Zoo::zoo_cycle(double pastMonth)
{
    bool boom = false;
    double currentMonthFeed;

    printZoo();

    cout << endl;

    cout << "All animals age one month." << endl;

    increment_age();
    add_time();

    cout << endl;

    cout << "A special event occurs." << endl;

    boom = random_event(); // random event

    if (bank_empty())
    {
        return 0;
    }

    cout << endl;

    cout << "Monthly revenue for animals." << endl;

    if (boom)
    { // a boom occurs
        calculateRevenue(true);
    }
    else
    { // no boom
        calculateRevenue(false);
    }

    cout << endl;

    cout << "Buy some animals." << endl;

    bool buy = month_choices(); // choices

    if (buy)
    {
        int choice = 0;
        int numSpecies = 0;

        choice = choose_animal();
        numSpecies = many_animal();

        buy_animal(choice, numSpecies);
    }

    if (bank_empty())
    {
        return 0;
    }

    cout << endl;

    cout << "Pay the upcoming feeding costs." << endl;
    
    if (time >= 0 && numAnimals == 0) {
        cout << "No animals! Feeding costs is zero." << endl;
        currentMonthFeed = 80;
    }

    if ((time >= 1 && numAnimals == 1) || (time >= 1 && numAnimals == 2))
    { // the first time the owner buys an animal
        currentMonthFeed = calc_food(80);
    }
    else
    {
        cout << "Feeding costs (PAST MONTH): " << pastMonth << endl;
        currentMonthFeed = month_feed(pastMonth);
        cout << "Feeding cost (THIS MONTH): " << currentMonthFeed << endl; // this is recursive
    }

    cout << endl;

    printZoo();

    cout << endl;

    return currentMonthFeed;
}

/*
* Function: month_feed
* Description: the feed will increment for all animals in your zoo (month)
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: month passes in and updates
 */
double Zoo::month_feed(double feed)
{
    double current_month;

    cout << "Prior Month Feed: " << feed << endl;

    current_month = calc_food(feed);

    return current_month;
}

/*
* Function: increment_age
* Description: the age will increment for all animals in your zoo (month)
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: age increases
 */
void Zoo::increment_age()
{
    // add age to all animals in your zoo

    // sea lions
    for (int i = 0; i < numSeaLions; i++)
    {
        exhibitSeaLion[i].increment_age();
    }

    // tigers
    for (int i = 0; i < numTigers; i++)
    {
        exhibitTiger[i].increment_age();
    }

    // black bear
    for (int i = 0; i < numBlackBears; i++)
    {
        exhibitBlackBear[i].increment_age();
    }
}

        /*
* Function: get_time
* Description: accessor for the time
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: time increases
 */
int Zoo::get_time() const
{
    return time;
}
