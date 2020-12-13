#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);

   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;

   // create a new vector to assign to
   std::vector<int> stdvCopy;

   stdvCopy = stdv;

    //  test if the template works
   if (stdvCopy.size() == v.size()) {
       cout << "The vectors are the same size!" << endl;
   } else {
       cout << "These vectors aren't the same size." << endl;
   }

   cout << "Test for at(4)." << endl;
   try {
       v.at(4);
   } catch (const std::out_of_range& oor) {
       std::cout << "Out of Range error: " << oor.what() << std::endl;
    } 

   cout << "Test for at(0)." << endl;
   try {
       v.at(0);
   } catch (const std::out_of_range& oor) {
       std::cout << "Out of Range error: " << oor.what() << std::endl;
    } 

    cout << "Test for operator[] 0." << endl;
   cout << v.operator[](0) << endl;

   return 0;
}