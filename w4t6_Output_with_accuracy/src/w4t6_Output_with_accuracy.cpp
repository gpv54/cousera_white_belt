//============================================================================
// Name        : w4t6_Output_with_accuracy.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Output with accuracy
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define COURSERA_VARIANT

int main() {
#ifdef COURSERA_VARIANT
	ifstream input("input.txt");

	double a;

	cout << fixed << setprecision(3);

	while (input >> a) {
		cout << a << endl;
	}
#else

	const string inFileName = "input.txt";
	ifstream inFile(inFileName);
	double val;

	cout << fixed << setprecision(3);

	if(inFile.is_open()){
		while (inFile >> val){
			cout << val << endl;
		}
	} else {
		cout << "Error open file: " << inFileName << endl;
	}
#endif
	return 0;
}
