/*********************************************************************
** Program Filename: catalog.h
** Author: Andrea Tongsak
** Date: 9/23/2020
** Description: The main method where the wizard text file is opened and the spellbook text file is opened
** Input: The two command line arguments (wizard.txt, spellbook.txt)
** Output: sorted file to the screen or an output file
*********************************************************************/
#ifndef catalog_h
#define catalog_h

#include <iostream>
#include <string>

using namespace std;

/*
 struct declarations
*/

// wizard struct for reading in wizard.txt
struct wizard {
    string name;
    int id;
    string password;
    string position_title;
    float beard_length;
};

// spellbook struct for hold info from spellbook.txt
struct spellbook {
    string title;
    string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    struct spell *s;
};

// spellbook struct for read info from spellbook.txt
struct spell {
    string name;
    float success_rate;
    string effect;
};

/*
 function prototypes
*/

// opens the wizard.txt file
bool openWizard(char* file);

// opens the spellbook.txt file
void openSpellbk(char* file, bool isStudent);

// read the data
void read_wizard_data(struct wizard *wizardArray, int numWizard, ifstream &infile);

// validate id
bool check_id(string * idTemp);

// check password and id
bool password_id_ask(struct wizard *wizardArray, int numWizard);

// welcome message and display user info
void welcome_valid_user(struct wizard *wizardArray, int numWizard, int userIndex);

// dynamically allocate an array of spellBooks
spellbook * create_spellbooks(int);

// fill a spellbook struct with info read in
void get_spellbook_data(spellbook *, int, ifstream &, bool isStudent);

// dynamically allocate an array of spells
spell* create_spells(int);

// fill a spell struct with information read in
void get_spell_data(spell *, int, ifstream &);

// fill a spell array of all the spells, regardless of spellbook
void get_all_spells_data(spellbook*, int, spell*, int);

// deletes and clears the wizard dynamic array
void delete_info_wizard(wizard **);

// deletes and clears spellbook
void delete_info_spell(spellbook **, int);

// sorting display message
void sorting_menu(spellbook * spbArr, int numSpb, struct spell * sArr, int numSp, bool isStudent);

// SORT 1: spellbooks by number of pages
spellbook* sort_pages(spellbook * spbArr, int numSpb);

// SORT 2: group spells by the effect, return the sorted array
struct spell* sort_effect(struct spell * spArr, int numSp);

// assign each spell struct a number according to its effect
int effect_num(spell*, int);

// counting the total of spells
int count_total(int bubble, int memory, int fire, int poison, int death);

// counting the total of spells for passing to the central function
int count_total(spellbook * spbArr, int numSpb);

// SORT 3: spellbooks by average success rate
spellbook* sort_success(spellbook * spbArr, int numSpb);

// printing display message
void printing_menu(int sortChoice, spellbook * spbArr, int numSpb, struct spell * spArr, int numSp, bool isStudent);

// prints out to a user screen
void write_to_user(int sortChoice, spellbook * spbArr, int numSpb, struct spell * spArr, int numSp, bool isStudent);

// print out to a file
void write_to_file(int sortChoice, spellbook * spbArr, int numSpb, struct spell * spArr, int numSp, bool isStudent);

// bubble sort helper method for entire spellbook array switching
void swap_descending(spellbook * spb1, spellbook * spb2);

// bubble sort helper method for entire spell array switching
void swap_descending(spell * sp1, spell * sp2);

// don't display dangerous spellbooks for students
void student_safety(spellbook * spbArr, int numSpb, int sortType);

// delete dangerous spells for students
void student_safety(spell * spArr, int numSp);

// spellbook safety: file
void student_safety_file(spellbook * spbArr, int numSpb, int sortType, ofstream& file);

// spell safety: file
void student_safety_file(spell * spArr, int numSp, ofstream& file);

#endif
