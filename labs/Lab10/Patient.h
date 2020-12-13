#ifndef PATIENT
#define PATIENT

#include <iostream>
#include <string>

using namespace std;

class Patient {
    private:
        string name;
    public:
        Patient();
        //Patient(string);
        Patient(const Patient&);
        Patient& operator = (const Patient);
        ~Patient();

        string get_name();
        void set_name(string); 

        
};

#endif