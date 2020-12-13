#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>

using namespace std;

class Sort {
    private:
        int length;
        int size;
        int *array;

    public:
        Sort();
        ~Sort();
        Sort(const Sort &other);
        Sort& operator=(const Sort other);

        int get_length();

        void ask_input();
        void num_input();

        void add_to_array(int);
        void resize_array();

        void print_array(int* arr);

        void create_array();
        
        void merge_sort(int* arr, int first, int last);
        void merge(int* arr, int f, int m, int last);

        void print_prime(int);

};


#endif