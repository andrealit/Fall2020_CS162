#include "Doctor.h"

using namespace std;

Doctor::Doctor() {
    specialty = "Pediatrician";
    num_patients = 3;
    patientArr = NULL;
}

Doctor::~Doctor() { // destructor
    if (patientArr != NULL) {
        delete[] patientArr;
    }
}

Doctor::Doctor(const Doctor &oldDoc) { // copy constructor
    if (patientArr != NULL) {
        delete[] patientArr;
    }

    this->specialty = oldDoc.specialty;
    this->num_patients = oldDoc.num_patients;

    patientArr = new Patient[num_patients];
    for (int i = 0; i < num_patients; i++) {
        patientArr[i] = oldDoc.patientArr[i];
    }
    
} 

Doctor &Doctor::operator=(const Doctor oldDoc) { // assignment operator overload
    if (patientArr != NULL) {
        delete[] patientArr;
    }

    patientArr = new Patient[num_patients];
    for (int i = 0; i < num_patients; i++) {
        patientArr[i] = oldDoc.patientArr[i];
    }
    this->specialty = oldDoc.specialty;
    this->num_patients = oldDoc.num_patients;

    return *this;
}

void Doctor::set_specialty(string spec) {
    this->specialty = spec;
}

string Doctor::get_specialty() {
    return this->specialty;
}

void Doctor::set_numPatients(int num) {
    this->num_patients = num;
}

int Doctor::get_numPatients() {
    return this->num_patients;
}

void Doctor::addPatient(Patient &patientAdd, string nameAdd) {
    if (num_patients == 0) {
        patientArr = new Patient[1];
        patientArr[0] = patientAdd;
        patientAdd.set_name(nameAdd);
        ++num_patients;
    } else {
        ++num_patients;
        Patient *temp = new Patient[num_patients];

        for (int i = 0; i < num_patients; i++) {
            if (i == (num_patients-1)) { // last patient
                temp[i] = patientAdd;
                patientAdd.set_name(nameAdd);
            } else {
                temp[i] = patientArr[i];
                patientAdd.set_name(nameAdd);
            }
        }

        delete[] patientArr;
        patientArr = temp;
        set_patientArr(patientArr);
        temp = NULL;

    }
} 

void Doctor::set_patientArr(Patient* p1) {
    patientArr = p1;
}