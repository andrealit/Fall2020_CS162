#ifndef DOCTOR
#define DOCTOR

#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;

class Doctor {
    private:
        string specialty;
        int num_patients;
        // dynamic array of Patient objects
        Patient *patientArr;
    public:
        Doctor();

        // big three
        ~Doctor();
        Doctor(const Doctor&); // copy constructor
        Doctor& operator = (const Doctor); // assignment operator

        void set_specialty(string);
        string get_specialty();

        void set_numPatients(int);
        int get_numPatients();

        void set_patientArr(Patient* p1);

        void addPatient(Patient &patientAdd, string nameAdd);


};

#endif