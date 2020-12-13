/*********************************************************************
** Program Filename: Linked_List.h
** Author: Andrea Tongsak
** Date: 11/20/2020
** Description: The header file for the Linked List class
** Input:
** Output:
*********************************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

using namespace std;

template <class T>
class Linked_List {
    private:
        unsigned int length; // the number of nodes contained in the list
        Node<T> *head; // a pointer to the first node in the list

    public:
        Linked_List();
        ~Linked_List();
        
        int get_length();

        void print(); 
        void clear();
        
        unsigned int push_front(T); 
        unsigned int push_back(T);
        unsigned int insert(T, unsigned int);
        
        void sort_ascending(); 
        void split(Linked_List<T>&, Linked_List<T>&);
        Node<T>* merge(Node<T>*, Node<T>*);        
        
        void sort_descending(); // sort the nodes in descending order (selection sort)
        Node<T>* selection(Node<T>*);
        void swap(Node<T>** first, Node<T>* old, Node<T>* toSwap, Node<T>* prev);

        void count_primes();

        void num_enter();
        void ask_another();
        void sort_type();
        void cycle();

};

#endif