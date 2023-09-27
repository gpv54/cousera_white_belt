//============================================================================
// Name        : w4t5_Work_with_files.cpp
// Author      : GPV
// Version     : 1 (part1)
// Copyright   : none
// Description : Work with files
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define PART_TWO

int main() {
	const string inFileName = "input.txt";
#ifdef PART_TWO
	const string outFileName = "output.txt";
#endif
	ifstream inFile(inFileName);
#ifdef PART_TWO
	ofstream outFile(outFileName);
#endif
	string line;
	if(inFile.is_open()){
		while(getline(inFile, line)){
#ifdef PART_TWO
			outFile << line << endl;
#else
			cout << line << endl;
#endif
		}
	} else {
		cout << "Error open file: " << inFileName << endl;
	}
	return 0;
}
