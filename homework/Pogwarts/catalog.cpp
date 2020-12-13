/*********************************************************************
** Program Filename: catalog.cpp
** Author: Andrea Tongsak
** Date: 9/23/2020
** Description: The file containing all the functions in the header file
** Input:
** Output:
*********************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

#include "catalog.h"
using namespace std;

/*
 * function: openWizard;
 * description: first function that will take in the command line argument and open that file using ifstream, store it in a struct, then deallocate
 * parameters: char * file
 * pre-conditions: it's a CMD line argument
 * post-condition: it will then go to password/ID prompt and dynamically clear the array
*/
bool openWizard(char *file)
{
    // setting program variables
    int numWizards;
    string temp;
    bool isStudent;

    ifstream ifile;
    string s;
    ifile.open(file);

    // read data from file
    if (ifile.fail() || !ifile)
    {
        cout << "Error in opening wizard directory...!!" << endl;
        exit(0);
    }

    // we're reading and printing out the number of wizards from the first line
    getline(ifile, temp);
    istringstream is1(temp);
    is1 >> numWizards;

    // create the array to store the wizards
    wizard *wizardInfo = new wizard[numWizards];

    // loop to go through each wizard
    for (int i = 0; i < numWizards; i++)
    {
        // read and store the wizard data
        read_wizard_data(wizardInfo, i, ifile);
    }

    // ask for id and password
    isStudent = password_id_ask(wizardInfo, numWizards);

    cout << endl;
    ifile.close();

    // clear the dynamic array
    delete_info_wizard(&wizardInfo);

    // indicator of whether the logged in user is student
    return isStudent;
};

/*
 * function: openSpellbk
 * description: second function that will take in the command line argument and open that file using ifstream, store it in a struct, then deallocate
 * parameters: char * file
 * pre-conditions: it's a CMD line argument
 * post-condition: it will then go to password/ID prompt and dynamically clear the array
*/
void openSpellbk(char *file, bool isStudent)
{
    // setting program variables
    int numSpellbk;
    string temp;

    ifstream spellbk;
    string s;
    spellbk.open(file);

    // read data from file
    if (!spellbk)
    {
        cout << "Error in opening spellbook...!!" << endl;
        exit(0);
    }

    // we're reading and printing out the number of spellbooks from the first line
    getline(spellbk, temp);
    istringstream is5(temp);
    is5 >> numSpellbk;

    // dynamically allocate the spellbk array
    spellbook *userSpb;
    userSpb = create_spellbooks(numSpellbk);

    // fill that spellbook array
    get_spellbook_data(userSpb, numSpellbk, spellbk, isStudent);

    cout << endl;
    cout << "closing the spellbook..." << endl;
    spellbk.close();

    // clear the dynamic array
    delete_info_spell(&userSpb, numSpellbk);
};

/*
* Function: read_wizard_data
* Description: using ifstream to funnel data into the array
* Parameters: takes the wizard struct, the number of wizards, and the ifstream
* Pre-Conditions: must have a struct state present
* Post-Conditions: must be deleted after to prevent data chaos
*/
void read_wizard_data(struct wizard *wizardArray, int numWizard, ifstream &infile)
{
    string line;

    // assign the read wizard data to members of the array
    getline(infile, line);
    istringstream is2(line);

    is2 >> wizardArray[numWizard].name >> wizardArray[numWizard].id >> wizardArray[numWizard].password >> wizardArray[numWizard].position_title >> wizardArray[numWizard].beard_length;
}

/*
* Function: check_id
* Description: error handling for the correct type of ID
* Parameters: takes in the ID string through pointers
* Pre-Conditions: user ID is entered
* Post-Conditions: prompts user for either password or re-entering
*/
bool check_id(string *idTemp)
{
    // initialize variables
    string id = *idTemp;
    bool invalidID = false;

    // assuming the username is not made of chars
    while (invalidID == false)
    {
        // iterate through each number in the ID string
        for (int i = 0; i < id.length(); i++)
        {

            // check if each value in the ID is a number
            if (!(id.at(i) >= '0' && id.at(i) <= '9'))
            {
                cout << "Entered an incorrect ID, try again." << endl;
                return false;
            }
            else
            {
                invalidID = true;
            }
        }
        *idTemp = id;
    }
    return invalidID;
}

/*
* Function: password_id_ask
* Description: asking the user for their password and id
* Parameters: takes in the wizard struct, the number of wizards
* Pre-Conditions: must have a struct wizard present
* Post-Conditions: this will return whether the user (once they gain entry) is a student
*/
bool password_id_ask(struct wizard *wizardArray, int numWizard)
{
    string userId;
    string userPass;
    int specialIndex = 0;
    int attempts = 0;
    bool invalidID = false;
    bool idValid = false;
    bool matchFound = false;

    bool isStudent = false;

    do
    {
        cout << "Please enter your id: ";
        cin >> userId;

        // check if the id is all numbers
        if (check_id(&userId) == true)
        {
            invalidID = false;
        }
        else
        {
            invalidID = true;
        }

        // converts the id to a number using stringstream
        stringstream username(userId);
        int idNum;
        username >> idNum;

        // now we're looking for a id match in the wizard array
        for (int i = 0; i < numWizard; i++)
        {
            // if the wizard id equals another
            if (wizardArray[i].id == idNum)
            {
                // set the valid id to true
                idValid = true;

                // now, password check
                cout << "Please enter your password: ";
                cin >> userPass;
                cout << endl;

                // check if password matches the userpass
                if (wizardArray[i].password == userPass)
                {
                    cout << "logging you in..." << endl;

                    // save the working index to a int
                    specialIndex = i;

                    matchFound = true;
                }
                else
                {
                    cout << "Incorrect password." << endl;
                    attempts++;
                }

                // password level: check how many attempts have been done
                if (attempts > 3)
                {
                    cout << "Too many attempts." << endl;
                    exit(0);
                }
            }
        }

        if (idValid != true && invalidID != true)
        {
            attempts++;
        }

    } while (attempts < 3 && matchFound == false);

    // username level: check how many attempts have been done
    if (attempts >= 3)
    {
        cout << "Too many attempts." << endl;
        exit(0);
    }

    if (matchFound)
    {
        cout << "Congrats, the login was successful!" << endl;
        cout << endl;
        if (wizardArray[specialIndex].position_title == "Student")
        {
            isStudent = true;
        }
        welcome_valid_user(wizardArray, numWizard, specialIndex);
    }

    return isStudent;
}

/*
* Function: welcome_valid_user
* Description: displays a welcome message the the valid user and their info
* Parameters: takes in the wizard struct, the number of wizards, and the specific wizard index
* Pre-Conditions: the user/pass combo is successful and verified
* Post-Conditions: this will return the user's information
*/
void welcome_valid_user(struct wizard *wizardArray, int numWizard, int userIndex)
{
    cout << "Welcome " << wizardArray[userIndex].name << endl;
    cout << "ID: " << wizardArray[userIndex].id << endl;
    cout << "Status: " << wizardArray[userIndex].position_title << endl;
    cout << "Beard Length: " << wizardArray[userIndex].beard_length << endl;
}

/*
* Function: create_spellbooks
* Description: creates a 1D dynamic array of spellbooks
* Parameters: takes the number of spellsbooks
* Pre-Conditions: valid number
* Post-Conditions: array is used in populate_spellbook_data
*/
spellbook *create_spellbooks(int numSpells)
{
    // use pointers
    spellbook *spellbookArray = new spellbook[numSpells];
    return spellbookArray;
}

/*
* Function: get_spellbook_data
* Description: fill a spellbook struct with information read in from spellbook.txt
* Parameters: takes the spellbook struct, the number of spellbooks, and the ifstream
* Pre-Conditions: must have a struct spellbook created
* Post-Conditions: must be deleted after to prevent data chaos
*/
void get_spellbook_data(spellbook *spbArr, int numSpb, ifstream &infile, bool isStudent)
{
    string temp;
    // call the create spellbooks here
    spbArr = create_spellbooks(numSpb);
    // need to call the create spells here (when there are spells)
    struct spell *userSp;
    int totalSpells = 0;

    float finalTotal = 0;

    for (int i = 0; i < numSpb; i++)
    {
        // assign the read spellbook data to members of the array
        // The problem: struct doesn't have the float average spell value
        getline(infile, temp, ' ');
        spbArr[i].title = temp;
        getline(infile, temp, ' ');
        spbArr[i].author = temp;
        getline(infile, temp, ' ');
        spbArr[i].num_pages = atoi(temp.c_str());
        getline(infile, temp, ' ');
        spbArr[i].edition = atoi(temp.c_str());

        getline(infile, temp);

        istringstream is5(temp);

        is5 >> spbArr[i].num_spells;

        // create spells here, in the spell value of the struct
        spbArr[i].s = create_spells(spbArr[i].num_spells);

        // populate the spell data for the struct
        get_spell_data(spbArr[i].s, spbArr[i].num_spells, infile);

        // next, calculate the average value of the spells in float
        for (int j = 0; j < spbArr[i].num_spells; j++)
        {
            finalTotal += spbArr[i].s[j].success_rate;
        }
        float avSuccRate = finalTotal / spbArr[i].num_spells;

        spbArr[i].avg_success_rate = avSuccRate;

        finalTotal = 0;
    }

    // can count total now, since data is filled.
    totalSpells = count_total(spbArr, numSpb);
    userSp = create_spells(totalSpells);

    // create the mega-spell array for possible effect sorting
    get_all_spells_data(spbArr, numSpb, userSp, totalSpells);

    // sorting menu
    sorting_menu(spbArr, numSpb, userSp, totalSpells, isStudent);
}

/*
* Function: create_spells
* Description: creates a 1D dynamic array of spells
* Parameters: takes the number of spells
* Pre-Conditions: valid number
* Post-Conditions: array is used in populate_spellbook_data
*/
spell *create_spells(int numSpells)
{
    spell *spellArray = new struct spell[numSpells];
    return spellArray;
}

/*
* Function: get_spell_data
* Description: fill a spell struct with information read in from spellbook.txt
* Parameters: takes the spell struct, the number of spells, and the ifstream
* Pre-Conditions: must have a struct spell created
* Post-Conditions: must be deleted after to prevent data chaos
*/
void get_spell_data(spell *spellArray, int numSpells, ifstream &infile)
{
    string temp;

    for (int i = 0; i < numSpells; i++)
    {
        getline(infile, temp, ' ');

        istringstream is6(temp);

        is6 >> spellArray[i].name;

        spellArray[i].name = temp;

        getline(infile, temp, ' ');
        spellArray[i].success_rate = atof(temp.c_str());

        getline(infile, temp);

        istringstream is7(temp);

        is7 >> spellArray[i].effect;

        spellArray[i].effect = temp;
    }
}

/*
* Function: get_all_spells_data
* Description: fill a spell struct with all the spells present in the file
* Parameters: takes the spellbook struct, the number of spellbooks, spell struct, the number of spells, and the ifstream
* Pre-Conditions: must have a struct spell created
* Post-Conditions: must be deleted after to prevent data chaos
*/
void get_all_spells_data(spellbook *spbArr, int numSpb, spell *allSpells, int total)
{
    //bool done_flag = false;
    int last_index = 0;
    spell temp;

    // loop to assign each spell struct to each otehr
    for (int j = 0; j < numSpb; j++)
    {
        for (int k = 0; k < spbArr[j].num_spells; k++)
        {
            allSpells[last_index] = spbArr[j].s[k];
            last_index++;
            if (last_index > total)
            {
                break;
            }
        }
    }
}

/*
* Function: delete_info_wizard
* Description: deletes all the memory that was dynamically allocated
* Parameters: takes the wizard dynamic array
* Pre-Conditions: must have a struct array of wizard created
* Post-Conditions: the dynamic arrays are deleted
*/
void delete_info_wizard(wizard **wizardArr)
{
    delete[] * wizardArr;
}

/*
* Function: delete_info_spell
* Description: deletes all the memory that was dynamically allocated
* Parameters: takes the spellbook dynamic array, and the number of spells
* Pre-Conditions: must have a struct array of spellbook created
* Post-Conditions: the dynamic arrays are deleted
*/
void delete_info_spell(spellbook **spellbookArr, int num)
{
    for (int i = 0; i < num; i++)
    {
        // clear the spells
        delete[](*spellbookArr)[i].s;
    }
    // clear the spellbook
    delete[](*spellbookArr);
}

/*
* Function: sorting_menu
* Description: asks the user for how they want the data to be sorted
* Parameters: takes the spellbook dynamic array, the number of spellbooks, the spell dynamic array, and the num of spells
* Pre-Conditions: populate_spellbook_data and populate_spell_data filled the structs
* Post-Conditions: the data is sorted, returns the choice number the user entered
 */
void sorting_menu(spellbook *spbArr, int numSpb, struct spell *sArr, int numSp, bool isStudent)
{
    int choice = 0;
    spellbook *sortedArr;
    struct spell *sortedSpells;

    do
    {
        cout << "Which option would you like to choose?" << endl;
        cout << "1. Sort spellbooks by number of pages" << endl;
        cout << "2. Group spells by their effect" << endl;
        cout << "3. Sort spellbooks by average success rate" << endl;
        cout << "4. Quit" << endl;
        cin >> choice;

        if (choice == 1)
        {
            // sort spellbooks by the number of pages
            sortedArr = sort_pages(spbArr, numSpb);
            printing_menu(choice, sortedArr, numSpb, sArr, numSp, isStudent);
        }
        else if (choice == 2)
        {
            // group spells by their effect
            sortedSpells = sort_effect(sArr, numSp);
            printing_menu(choice, spbArr, numSpb, sortedSpells, numSp, isStudent);
        }
        else if (choice == 3)
        {
            // sort spellbooks by average success rate
            sortedArr = sort_success(spbArr, numSpb);
            printing_menu(choice, sortedArr, numSpb, sArr, numSp, isStudent);
        }
        else if (choice == 4)
        {
            cout << "Quitting..." << endl;
            exit(0);
        }
        else
        {
            cout << "Invalid option, quitting." << endl;
            exit(0);
        }

    } while (choice >= 1 && choice <= 3);
}

/*
* Function: sort_pages
* Description: sorts the spellbooks by the number of pages BIG to small
* Parameters: takes in the spellbook array, then the number of spellbooks
* Pre-Conditions: the spellbook struct is all filled correctly
* Post-Conditions: the spellbook struct is sorted by number of pages
 */
spellbook *sort_pages(spellbook *spbArr, int numSpb)
{
    bool swapped;

    for (int i = 0; i < numSpb - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < numSpb - i - 1; j++)
        {
            // use bubble sort to order your pages
            if (spbArr[j].num_pages < spbArr[j + 1].num_pages)
            {
                // switch the bubbles with swap method
                swap_descending(&spbArr[j], &spbArr[j + 1]);
                swapped = true;
            }
        }

        // if no two elements were swapped, breaks
        if (swapped == false)
        {
            break;
        }
    }

    return spbArr;
}

/*
* Function: swap_descending
* Description: is the bubble sort helper method
* Parameters: take in the two spellbook arrays using pointers
* Pre-Conditions: assume that value 2 is greater
* Post-Conditions: the two ints are sorted
 */
void swap_descending(spellbook *spb1, spellbook *spb2)
{
    spellbook temp = *spb1;
    *spb1 = *spb2;
    *spb2 = temp;
}

/*
* Function: swap_descending
* Description: is the bubble sort helper method
* Parameters: take in the two floats using pointers
* Pre-Conditions: assume that value 2 is greater
* Post-Conditions: the two ints are sorted
 */
void swap_descending(spell *sp1, spell *sp2)
{
    spell temp = *sp1;
    *sp1 = *sp2;
    *sp2 = temp;
}

/*
 * Function: sort_effect
 * Description: sort the spells in order of effect
 * Parameters: the spellbook array, the number of spellbooks
 * Pre-Conditions: need the OG spellbook, and the OG spells
 * Post-Conditions: order -- bubble, memory_loss, fire, poison, death
 */
struct spell *sort_effect(struct spell *spArr, int numSp)
{
    bool swapped;

    // sort success
    for (int i = 0; i < numSp - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < numSp - i - 1; j++)
        {
            // assign the array with a number
            if (effect_num(spArr, j) > effect_num(spArr, j + 1))
            {
                // switch the struct order with the swap method!
                swap_descending(&spArr[j], &spArr[j + 1]);
                swapped = true;
            }
        }

        // if no two elements were swapped, break
        if (swapped == false)
        {
            break;
        }
    }

    return spArr;
}

/*
* Function: count_total
* Description: counting the total of spells in the array
* Parameters: each count number of every spell
* Pre-Conditions: spellbook is filled
* Post-Conditions: the total of spells is counted
*/
int count_total(spellbook *spbArr, int numSpb)
{
    int total = 0;

    for (int i = 0; i < numSpb; i++)
    {
        total += spbArr[i].num_spells;
    }

    return total;
}

/*
* Function: effect_num
* Description: assign each effect type to a number
* Parameters: takes in a struct spell, index
* Pre-Conditions: the spell has no number assigned yet
* Post-Conditions: the correct number correlating to the effect is returned
*/
int effect_num(spell *spArr, int i)
{

    // assign each spArr to an number
    if (spArr[i].effect == "bubble")
        return 1;

    if (spArr[i].effect == "memory_loss")
        return 2;

    if (spArr[i].effect == "fire")
        return 3;

    if (spArr[i].effect == "poison")
        return 4;

    if (spArr[i].effect == "death")
        return 5;

    return 0;
}

/*
* Function: sort_success
* Description: sort the spellbooks by average success rate
* Parameters: the spellbook array, the number of spellbooks
* Pre-Conditions: spellbook array is present
* Post-Conditions: the spellbook array is not present
*/
spellbook *sort_success(spellbook *spbArr, int numSpb)
{
    bool swapped;

    // sort success
    for (int i = 0; i < numSpb - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < numSpb - i - 1; j++)
        {
            // use bubble sort or selection sort to order your pages
            if (spbArr[j].avg_success_rate < spbArr[j + 1].avg_success_rate)
            {
                // switch the struct order with swap method
                swap_descending(&spbArr[j], &spbArr[j + 1]);
                swapped = true;
            }
        }

        // if no two elements were swapped, break
        if (swapped == false)
        {
            break;
        }
    }
    return spbArr;
}

/*
* Function: printing_menu
* Description: print out options to user
* Parameters: the user's choice, the spellbook arrays, number of spbs, spell array, and number of spells
* Pre-Conditions: the data is not yet printed out
* Post-Conditions: sorted data is printed
*/
void printing_menu(int sortChoice, spellbook *spbArr, int numSpb, struct spell *spArr, int numSp, bool isStudent)
{
    int userInput;
    bool valid;

    do
    {
        cout << "How would you like the information displayed?" << endl;
        cout << "1. Print to screen (Press 1) " << endl;
        cout << "2. Print to file (Press 2) " << endl;
        cin >> userInput;

        if (userInput < 1 || userInput > 2)
        {
            // must repeat
            cout << "You entered an incorrect input!" << endl;
            valid = false;
        }
        else
        {
            valid = true;
        }

    } while (valid != true);

    if (userInput == 1)
    {
        write_to_user(sortChoice, spbArr, numSpb, spArr, numSp, isStudent);
    }

    if (userInput == 2)
    {
        write_to_file(sortChoice, spbArr, numSpb, spArr, numSp, isStudent);
    }
}

/*
* Function: write_to_user
* Description: print out the sorted info to screen
* Parameters: the sortChoice, spellbook array, the number of spellbooks
* Pre-Conditions: spellbook array is present
* Post-Conditions: the spellbook array is not present
*/
void write_to_user(int sortChoice, spellbook *spbArr, int numSpb, struct spell *spArr, int numSp, bool isStudent)
{
    // the sortChoice is sort spellbooks by number of pages
    if (sortChoice == 1)
    {
        // display the pages
        if (isStudent)
        {
            // use the student safety function
            student_safety(spbArr, numSpb, 1);
        }
        else
        {
            for (int i = 0; i < numSpb; i++)
            {
                cout << (spbArr[i].title) << " " << to_string(spbArr[i].num_pages) << endl;
            }
        }
    }

    // the sortChoice is sort spellbooks by effect
    if (sortChoice == 2)
    {
        // display the effect
        if (isStudent)
        {
            student_safety(spArr, numSp);
        }
        else
        {
            for (int i = 0; i < numSp; i++)
            {
                cout << spArr[i].effect << " " << spArr[i].name << endl;
            }
        }
    }

    // the sortChoice is sort spellbooks by average success rate
    if (sortChoice == 3)
    {
        if (isStudent)
        {
            student_safety(spbArr, numSpb, 3);
        }
        else
        {
            for (int i = 0; i < numSpb; i++)
            {
                cout << (spbArr[i].title) << " " << spbArr[i].avg_success_rate << endl;
            }
        }
    }
}

/*
* Function: write_to_file
* Description: print out the sorted info to a file
* Parameters: the sort choice
* Pre-Conditions: spellbook array is present
* Post-Conditions: the spellbook array is not present
*/
void write_to_file(int sortChoice, spellbook *spbArr, int numSpb, struct spell *spArr, int numSp, bool isStudent)
{
    char userFile[260];

    // Ask user for the name of the output file
    cout << "Enter the name of the output file: ";
    cin >> userFile;

    string outputFile = userFile;

    ofstream MyFile(outputFile + ".txt");

    switch (sortChoice)
    {
    case 1: // the sortChoice is sort spellbooks by number of pages
        if (isStudent)
        {
            student_safety_file(spbArr, numSpb, 1, MyFile);
        }
        else
        {
            for (int i = 0; i < numSpb; i++)
            {
                MyFile << spbArr[i].title << " " << to_string(spbArr[i].num_pages) << endl;
            }
        }
        break;

    case 2: // the sortChoice is sort spellbooks by effect
        if (isStudent)
        {
            student_safety_file(spArr, numSp, MyFile);
        }
        else
        {
            for (int i = 0; i < numSp; i++)
            {
                MyFile << spArr[i].effect << " " << spArr[i].name << endl;
            }
        }
        break;

    case 3: // the sortChoice is sort spellbooks by average success rate
        if (isStudent)
        {
            student_safety_file(spbArr, numSpb, 3, MyFile);
        }
        else
        {
            for (int i = 0; i < numSpb; i++)
            {
                MyFile << spbArr[i].title << " " << spbArr[i].avg_success_rate << endl;
            }
        }
        break;
    }

    MyFile.close();
    cout << "File " << outputFile << ".txt was written to!" << endl;
}

/*
* Function: student_safety
* Description: delete dangerous spellbooks for students
* Parameters: takes the spellbook dynamic array
* Pre-Conditions: all the spellbooks are present
* Post-Conditions: the dangerous spellbooks are gone when displayed
 */
void student_safety(spellbook *spbArr, int numSpb, int sortType)
{
    // find the bad spellbooks.
    for (int i = 0; i < numSpb; i++)
    {
        bool isBad = false;
        for (int j = 0; j < spbArr[i].num_spells; j++)
        {
            if (spbArr[i].s[j].effect == "poison" || spbArr[i].s[j].effect == "death")
            {
                isBad = true;
            }
        }

        switch (sortType)
        {
        case 1:
            if (!isBad)
            {
                cout << spbArr[i].title << " " << to_string(spbArr[i].num_pages) << endl;
            }
            break;

        case 3:
            if (!isBad)
            {
                cout << spbArr[i].title << " " << to_string(spbArr[i].avg_success_rate) << endl;
            }
            break;
        }
    }
}

/*
* Function: student_safety
* Description: remove dangerous spells for students
* Parameters: takes the spell dynamic array
* Pre-Conditions: all the spells are present
* Post-Conditions: the dangerous spells are gone when displayed
 */
void student_safety(spell *spArr, int numSp)
{
    // find the bad spells
    for (int i = 0; i < numSp; i++)
    {
        bool isBad = false;
        if (spArr[i].effect == "poison" || spArr[i].effect == "death")
        {
            isBad = true;
        }

        if (!isBad)
        {
            cout << spArr[i].effect << " " << spArr[i].name << endl;
        }
    }
}

/*
* Function: student_safety_file
* Description: remove dangerous spellbooks for students for files
* Parameters: takes the spellbook dynamic array
* Pre-Conditions: all the books are present
* Post-Conditions: the dangerous books are gone in the file
 */
void student_safety_file(spellbook *spbArr, int numSpb, int sortType, ofstream &MyFile)
{
    for (int i = 0; i < numSpb; i++)
    {
        bool isBad = false;
        for (int j = 0; j < spbArr[i].num_spells; j++)
        {
            if (spbArr[i].s[j].effect == "poison" || spbArr[i].s[j].effect == "death")
            {
                isBad = true;
            }
        }

        switch (sortType)
        {
        case 1:
            if (!isBad)
            {
                MyFile << spbArr[i].title << " " << to_string(spbArr[i].num_pages) << endl;
            }
            break;

        case 3:
            if (!isBad)
            {
                MyFile << spbArr[i].title << " " << to_string(spbArr[i].avg_success_rate) << endl;
            }
            break;
        }
    }
}

/*
* Function: student_safety_file
* Description: remove dangerous spells for students for files
* Parameters: takes the spell dynamic array
* Pre-Conditions: all the spells are present
* Post-Conditions: the dangerous spells are gone in the file
 */
void student_safety_file(spell *spArr, int numSp, ofstream &MyFile)
{
    for (int i = 0; i < numSp; i++)
    {
        bool isBad = false;
        if (spArr[i].effect == "poison" || spArr[i].effect == "death")
        {
            isBad = true;
        }
        if (!isBad)
        {
            MyFile << spArr[i].effect << " " << spArr[i].name << endl;
        }
    }
}
