#include "Patient.h"

using namespace std;

Patient::Patient() {
    name = "Annette";
}

Patient::Patient(const Patient &oldPat) {
    this->name = oldPat.name;
    //cout << "HELLO?" << endl;
}

Patient &Patient::operator= (const Patient oldPat) {
    this->name = oldPat.name;
    return *this;
}


Patient::~Patient() {
    //delete name;
}

// Patient::Patient(string word) {
//     name = word;
// }

string Patient::get_name() {
    return this->name;
}

void Patient::set_name(string word) {
    name = word;
}