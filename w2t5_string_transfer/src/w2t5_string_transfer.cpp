//============================================================================
// Name        : w2t5_string_transfer.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : String transfer
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination){
	for(auto w : source)
		destination.push_back(w);
	source.clear();
}

void PrintStrings(const vector<string>& str){
	for(auto w : str)
		cout << w << " ";
	cout << endl;
}

int main() {
	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};
	MoveStrings(source, destination);

	PrintStrings(source);
	PrintStrings(destination);
	return 0;
}
