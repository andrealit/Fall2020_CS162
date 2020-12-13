#include "Sort.h"
#include <cstdlib>

using namespace std;

Sort::Sort() {
    length = 0;
    size = 5;
    //array = new int[5];
}

Sort::~Sort() {
    if (array != NULL) {
        delete [] array;
    }
}

Sort::Sort(const Sort &other) { // Copy constructor
    length = other.length;
    size = other.size;

    array = new int[length];

    for (int i = 0; i < size; i++) {
        array[i] = other.array[i];
    }
}

Sort &Sort::operator=(const Sort other) {
    if (this != &other && length > 0) {
        delete[] array;
    }
    size = other.size;
    length = other.length;
    array = new int[length];

    for (int i = 0; i < size; i++) {
        array[i] = other.array[i];
    }

    return *this;
}

int Sort::get_length() {
    return this->length;
}

void Sort::ask_input() {
    char inputUse;

    cout << "Do you want another num (y or n): ";

    while (!(cin >> inputUse) && inputUse != 'y' && inputUse != 'n') {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore();
        break;
    }

    if (inputUse == 'y') {
        num_input();
    } else if (inputUse == 'n') {
        // time to sort
        print_array(array);
        merge_sort(array, 0, length-1);
        return;
    } else {
        cout << "Invalid input." << endl;
        return;
    }
    
}

void Sort::num_input() {
    int inputNum;

    do {
        cout << "Please enter a number: ";

        while(!(cin >> inputNum)) {
            cout << "Input of type int." << endl;
            cin.clear();
            cin.ignore();
            break;
        }

    } while (inputNum < 0 || inputNum > 25);

    add_to_array(inputNum);

    ask_input();

}

void Sort::add_to_array(int value) {

    if (length == size) {
        // resize the array
        resize_array();
    }

    array[length] = value;
    length++;
}

void Sort::resize_array() {
    int *temp = new int[size*2];

    if (length == size) {
        cout << "Length is resizing." << endl;
        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }
    }

    for (int j = 0; j < length; j++) {
        array[j] = temp[j];
    }

    size = size * 2;

    delete[] temp;
}

void Sort::print_array(int* arr) {
    for (int x = 0; x < length; x++) {
        cout << arr[x] << " ";
    }
    cout << endl;
}

void Sort::create_array() {
    int arrSize;
    int num;

    cout << "How big do you want your array to be?" << endl;

    do {
        cout << "Enter (0 to 25): ";

        while(!(cin >> arrSize)) {
            cout << "Input of type int." << endl;
            cin.clear();
            cin.ignore();
            break;
        }

    } while (arrSize < 0 || arrSize > 25);

    array = new int[arrSize];

    for (int i = 0; i < arrSize; i++) {
        num = rand() % 100 + 1;

        add_to_array(num);

    }

    print_array(array);

    merge_sort(array, 0, arrSize-1);

    print_array(array);
    
    cout << "Printing out the primes..." << endl;

    for (int i =0; i < length; i++) {
        print_prime(array[i]);
    }
    cout << endl;
}

void Sort::merge_sort(int* arr, int first, int last) {

    if (length <= 1) {
        cout << "Not enough elements to sort." << endl;
        return;
    }

    if (first >= last) { // the first placeholder shouldn't be exceed the last
        return;
    }

    int middle = first + ((last - first) / 2); // else, divide in two halves

    merge_sort(arr, first, middle);  // sort the two halves (use recursion)
    merge_sort(arr, middle+1, last);
    merge(arr, first, middle, last); // merge the two halves

}

void Sort::merge(int* arr, int first, int middle, int last) {
    int size1 = middle - first + 1;
    int size2 = last - middle;
    
    int * left;
    left = new int[size1];
    int * right;
    right = new int[size2];

    for (int i = 0; i < size1; i++) {
        left[i] = arr[first+i];
    }
    for (int j = 0; j < size2; j++) {
        right[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = first;

    while (i < size1 && j < size2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy remaining elements
    while (i < size1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

void Sort::print_prime(int num) {
    bool isPrime;

    if (num <= 1) {
        isPrime = false;
        return;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            isPrime = false;
            return;
        }
    }
    isPrime = true;

    if (isPrime) {
        cout << num << " ";
    }
}