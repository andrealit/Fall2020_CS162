#include <iostream>
#include <fstream>
using namespace std;

/*
  Demonstrates the basics of file input/output
*/
int main() {

	// read book information from file
	ifstream fin;
	fin.open("book.txt", ios::in);
	if (!fin.is_open()) {
		cout << "Error, unable to open file!" << endl;
		return 1;
	}

	// read the contents of the file and display it on screen
	// each iteration of the loop will read until encountering a space
	while (!fin.eof()) {
		string tmp_string;
		//fin >> tmp_string;
		getline(fin, tmp_string,',');
		cout << "Text: " << tmp_string << endl;
	}

	fin.close();

	return 0;
}
