#include <stdlib.h>
#include <stdexcept>
#include <iostream>
#include <vector>
template <class T>
class vector {
   private:
      T *v;
      int s;
      int c;
   public:
      vector(){
             c=0;
             s=0;
             v=NULL;
      }
 
      ~vector(){
             if (v != NULL) {
                    delete [] v;
             }      
      }

      vector(vector<T> &other) { // Copy constructor
          s = other.s;
          c = other.c;
          v = new T[c];
          for (int i =0; i < s; i++) {
                 v[i] = other.v[i]; 
          }
      }

      vector& operator=(vector<T> &other) { // assignment operator
          if (this != &other && c > 0) {
                 delete[] v;
          }
          s = other.s;
          c = other.c;
          v = new T[c];
          for (int i =0; i < s; i++) {
                 v[i] = other.v[i]; 
          }
          
          return *this;
      }

      int size() {
             return s;
      }

      int capacity() {
             return c;
      }

      void push_back(T ele) {
             // if the capacity is less or equal than the size

             if (this->size() >= this->capacity()) {
                    resize();
             } else {
                    v[s++]=ele;
                    return;
             }
             T *temp;
             temp = new T[++s];
             for(int i=0; i<s-1; i++)
                temp[i]=v[i];
             delete [] v;
             v=temp;
             v[s-1]=ele;
      }

       // resizes the capacity of the vector
      void resize() {
              // increase the capacity by 5
              this->c+=5;
      }

       // only performs address arithmetic
      T& operator[](int index) {
             return v[index];
      }

       // check to make sure not out of bounds
      T& at(int index) {
             
                    if (index < 0 || index >= this->size()) {
                           std::cout << "Out of range!" << std::endl;
                           throw std::out_of_range("T& at(): The index is out of range.");
                    } else {
                           return v[index];
                    }
      }

};
