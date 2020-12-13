/*********************************************************************
** Program Filename: Linked_List.cpp
** Author: Andrea Tongsak
** Date: 11/20/2020
** Description: Definitions for the Linked List class
** Input:
** Output:
*********************************************************************/

/**
 * References: https://www.geeksforgeeks.org/merge-sort-for-linked-list/
 * https://www.geeksforgeeks.org/recursive-selection-sort-singly-linked-list-swapping-node-links/
 */ 

#include "Linked_List.h"
#include <iostream>
#include <cstddef>

using namespace std;

/*
* Function: Linked_List Constructor
* Description: builds the linked list
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The class is created
 */
template <class T>
Linked_List<T>::Linked_List() {
    length = 0;
    head = NULL;
}

/**
 * Function: Linked_List Destructor
 * Description: destroys the linked list
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: The memory is re-allocated.
 */
template <class T>
Linked_List<T>::~Linked_List() {
    clear();
}

/*
* Function: get_length
* Description: returns the unsigned int
* Parameters: gets the length of the linked list
* Pre-Conditions: -
* Post-Conditions: -
 */
template <class T>
int Linked_List<T>::get_length() {
    return this->length;
}

/*
* Function: print
* Description: output a list of all integers contained within the list
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The linked list is shown to the user
 */
template <class T>
void Linked_List<T>::print() {
    int leng = 0;

    Node<T> *n = head;

    while (n != NULL) {
        cout << n->val << " ";
        n = n->next;

        leng++;
    }
    cout << endl;

    length = leng;

    cout << "Length: " << get_length() << endl;

}

/*
* Function: clear
* Description: delete the entire list (remove all nodes and reset length to 0)
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Clears the linked list
 */
template <class T>
void Linked_List<T>::clear() {

    Node<T> *current = head;
    Node<T> *next;

    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }

    head = NULL;

    length = 0;

}

/*
* Function: push_front
* Description: insert a new value at the front of the list (returns the new length of the list)
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Add to top of linked list
 */
template <class T>
unsigned int Linked_List<T>::push_front(T data) {

    // create a new node
    Node<T> * node_add = new Node<T>;

    // put in the val
    node_add->val = data;

    // link the new to the head
    node_add->next = head;

    // reference the head to the new node
    head = node_add;

    length++;

    return length;
}

/*
* Function: push_back
* Description: insert a new value at the front of the list (returns the new length of the list)
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Add to top of linked list
 */
template <class T>
unsigned int Linked_List<T>::push_back(T data) {

    // create a new node
    Node<T> *node_add = new Node<T>;

    // put in val
    node_add->val = data;
    node_add->next = NULL;

    // go to the tail of the list
    if (head == NULL) {
        head = node_add;
    } else {
        Node<T> *current = head; 
        for (int i = 0; i < length - 1; i++) {
            current = current->next;
        }
        current->next = node_add; // the previous points to the added
    }

    // increase length
    length++;

    return length;
}

/*
* Function: insert
* Description: insert an element wherever the index is
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: Add to a specific spot in linked list;
 */
template <class T>
unsigned int Linked_List<T>::insert(T data, unsigned int index) {
    Node<T> *current = head;

    for (int i = 0; i < index-1; i++) {
        current = current->next;
    }
    
    Node<T> *after = current->next;

    Node<T> *node_add = new Node<T>;

    node_add->val = data;
    node_add->next = after; // the next pointer to the node after
    current->next = node_add; // the current node points to the new added
    
    length++;

    return length;
}

/*
* Function: sort_ascending
* Description: sort the nodes in ascending order (recursive Merge Sort)
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: the linked list is ascending
 */
template <class T>
void Linked_List<T>::sort_ascending() {

    Linked_List<T> left;
    Linked_List<T> right;

    if ((head == NULL) || (head->next == NULL)) { // empty or one node case
        return;
    }

    split(left, right); // this will continue splitting list until one node

    clear(); // clear the current linked list, since we're resetting the "head" for the unsorted
    left.sort_ascending();
    right.sort_ascending();

    head = merge(left.head, right.head); // the new head is the one that is the smallest after recursive merge sort

    left.head = NULL; // get rid of our old lists
    right.head = NULL;

}

/*
* Function: merge
* Description: put the correct node first (recursive)
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The correct linked list is in order
 */
template <class T>
Node<T>* Linked_List<T>::merge(Node<T>* left, Node<T>* right) {
    Node<T>* result = NULL;

    if (left == NULL) { // if one "side" is empty, then return the other half with remaining nodes
        return right;
    } else if (right == NULL) {
        return left;
    }

    if (left->val <= right->val) { // if the left value is smaller
        result = left; // our new "head" is that min value
        result->next = merge(left->next, right); // recursive call for which is the next smallest
    } else {
        result = right; // the right is smaller
        result->next = merge(left, right->next); // compare the next right val to the same left val
    }

    return result;
}

/*
* Function: split
* Description: put the correct node first (recursive)
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The correct linked list is in order
 */
template <class T>
void Linked_List<T>::split(Linked_List<T> &left, Linked_List<T> &right) {
    // get middle after divide
    int middle = length / 2;

    Node<T> * current = head;

    for (int i = 0; i < middle; i++) { // separate into left and right linked lists
        left.push_back(current->val);
        current = current->next;
    }

    for (int j = middle; j < length; j++) {
        right.push_back(current->val);
        current = current->next;
    }
}

/**
 * Function: sort_descending() 
 * Description: sorts the list in descending order with selection sort
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: Sorted from greatest to least
 */
template <class T>
void Linked_List<T>::sort_descending() {

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    head = selection(head);

}

/**
 * Function: selection
 * Description: orders the linked list using recursive selection sort
 * Parameters: node
 * Pre-Conditions: -
 * Post-Conditions: The list is ordered using selection sort
 */
template <class T>
Node<T>* Linked_List<T>::selection(Node<T>* top) {

    if ((top->next == NULL)) { // only one node left
        return top;
    }

    Node<T>* max = top; // the max
    Node<T>* beforeMax; // the value previous of max that needs to link to the switch
    Node<T>* temp;

    // go through linked list
    for (temp = top; temp->next != NULL; temp = temp->next) {
        // check for the max
        if (temp->next->val > max->val) {
            max = temp->next;
            beforeMax = temp; // save the node before the found max to relink with old max
        }
    }

    // if the max and the head aren't the same, swap
    if (max != top) {
        swap(&top, top, max, beforeMax); // the first top needs to be passed by reference bc it's the original max that is updated
    }

    // recursive to cover the next unsorted portion
    top->next = selection(top->next);

    return top;
}

/**
 * Function: swap
 * Description: swaps two nodes
 * Parameters: the head, the old, the swap, the previous
 * Pre-Conditions: -
 * Post-Conditions: The nodes are swapped in place
 */
template <class T>
void Linked_List<T>::swap(Node<T>** first, Node<T>* old, Node<T>* toSwap, Node<T>* prev) {
    // make the toSwap as head
    *first = toSwap;

    prev->next = old;

    Node<T>* temp = toSwap->next;
    toSwap->next = old->next;
    old->next = temp;
}

/**
 * Function: count_primes
 * Description: counts the number of primes in a list
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: Total of primes printed
 */
template <class T>
void Linked_List<T>::count_primes() {
    bool isPrime;
    Node<T>* current = head;
    int count = 0;

    for (int i = 0; i < length; i++) {
        isPrime = true;

        if (current->val <= 1) {
            // negative numbers aren't prime
            isPrime = false;
            break;
        } else {

            for (int j = 2; j*j < current->val; j++) {
                if (current->val % j == 0) {
                    isPrime = false;
                    break;
                }
            } 

            if (isPrime == true) {
                for (int j = 2; j < current->val; j++) {
                    if (current->val % j == 0) {
                        isPrime = false;
                        break;
                    }
                } 
            }

        }

        if (isPrime) {
            count++;
        }
        current = current->next;
    }

    cout << "You have " << count << " prime number(s) in your list." << endl;

    cout << endl;

}

/**
 * Function: num_enter
 * Description: asks user to enter a val for the list
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: the node is pushed to the list
 */
template <class T>
void Linked_List<T>::num_enter() {
    T inputNum;

    cout << "Please enter a number: ";

    while (!(cin >> inputNum))
    {
        cout << "Please enter a number: ";
        cin.clear();
        cin.ignore();
    }

    push_front(inputNum);

    ask_another();

}

/**
 * Function: ask_another
 * Description: whether user wants to enter another number
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: yes, reask. no, go to sort type
 */
template <class T>
void Linked_List<T>::ask_another() {
    char inputUse;

    cout << "Do you want another num (y/n): ";

    do {

        while (!(cin >> inputUse)) {
            cout << "Enter (y/n): ";
            cin.clear();
            cin.ignore();
        }

    } while (inputUse != 'y' && inputUse != 'n');

    if (inputUse == 'y') {
        num_enter();
        return;
    } else if (inputUse == 'n') {
        // time to sort
        sort_type();
        return;
    }
}

/**
 * Function: sort_type
 * Description: let the user choose what type of sort they'd like
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: the sorted list is printed, the primes are shown
 */
template <class T>
void Linked_List<T>::sort_type() {
    char inputSort;

    cout << "Sort ascending or descending (a/d)? ";

    do {

        while (!(cin >> inputSort)) {
            cout << "Enter (a or d): ";
            cin.clear();
            cin.ignore();
        }

    } while (inputSort != 'a' && inputSort != 'd');

    if (inputSort == 'a') {
        sort_ascending();
    } else if (inputSort == 'd') {
        sort_descending();
    }

    cout << endl;

    cout << "Your linked list is: ";
    print();

    count_primes();
}

/**
 * Function: cycle
 * Description: let the user repeat creation of linked lists and sorting if they'd like
 * Parameters: -
 * Pre-Conditions: -
 * Post-Conditions: repeat or end the linked list "sort"
 */
template <class T>
void Linked_List<T>::cycle() {
    char again;
    bool repeat = true;

    do {
        num_enter();

        cout << "Do you want to do this again (y/n)? ";

        do {

            while (!(cin >> again)) {
                cout << "Enter (y/n): ";
                cin.clear();
                cin.ignore();
            }

        } while (again != 'y' && again != 'n');

        if (again == 'y') {
            clear();
            length = 0;
            repeat = true;
        } else if (again == 'n') {
            clear();
            length = 0;
            repeat = false;
        }

        cout << endl;

    } while (repeat == true);

}

