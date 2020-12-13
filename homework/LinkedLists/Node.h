/*********************************************************************
** Program Filename: Node.h
** Author: Andrea Tongsak
** Date: 11/20/2020
** Description: The header file for the Node class
** Input:
** Output:
*********************************************************************/

#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
    public:
        T val;    // the value that this node stores
        Node *next; // a pointer to the next node in the list

};

#endif