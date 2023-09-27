//============================================================================
// Name        : w4t6_Read_and_output_table.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Read and output tablet
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	const string inFileName = "input.txt";
	ifstream inFile(inFileName);
	int n, m;
	int val;

	if(inFile.is_open()){
		inFile >> n;
		inFile.ignore(1);
		inFile >> m;
		while(n){
			for(int i = 0; i < m; ++i){
				if(!(inFile >> val)) {
					break;
				}
				cout << setw(10);
				cout << val;
				if(i < (m-1))
					cout << ' ';
				if(!(inFile.ignore(1))) {
					break;
				}
			}
			n--;
			cout << endl;
		}
	} else {
		cout << "Error open file: " << inFileName << endl;
	}
	return 0;
}
