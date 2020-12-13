
#include <iostream>
#include <string>

#include "Doctor.h"
#include "Patient.h"

using namespace std;

void printDocInfo(Doctor d) {
    // print doctor data members and patient names
    cout << "DOCTOR INFO:" << endl;
    cout << "   Specialty: " << d.get_specialty() << endl;
    cout << "   Num of Patients: " << d.get_numPatients() << endl;
    cout << "   Patient Names: ";
    for (int i = 0; i < d.get_numPatients(); i++) {
        //cout << d.patientArr->get_name() << ", ";
    }
}


int main(int argc, char * argv[]) {
    Doctor doc;
    string special;
    int numPat;
    string tempName;

    cout << "Enter the doctor's info." << endl;
    cout << "Specialty: ";
    cin >> special;

    doc.set_specialty(special);

    cout << endl;
    

    cout << "Num of Patients: ";
    cin >> numPat;

    doc.set_numPatients(numPat);

    cout << endl;

    cout << "You have " << doc.get_numPatients() << " patients." << endl;

    // create the dynamic array here
    // Patient* pat = new Patient[doc.get_numPatients()]; 
    // doc.set_patientArr(pat); 

    for (int i = 0; i < doc.get_numPatients(); i++) {
        cout << "Patient " << i << "'s Name: ";
        cin >> tempName;

        Patient p;
        doc.addPatient(p, tempName);
        cout << endl;
    }

    cout << "Finished filling in the Doctor dynamic info!" << endl;

    printDocInfo(doc);

    return 0;
}