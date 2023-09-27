//============================================================================
// Name        : w3t1_Sort_int_numbers.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Sort integer numbers
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct myclass {
  bool operator() (int i,int j) { return (abs(i)<abs(j));}
} myobject;

void PrintVector(const vector<int>& vec/*, const string& s*/){
	//cout << s << endl;
	for (auto w: vec)
		cout << w << " ";
	cout << endl;
}

int main() {
	int N;
	int a;
	vector<int> values;

	cin >> N;

	if(N > 0 && N <= 1000){
		while(N--){
			cin >> a;
			values.push_back(a);
		}

		//PrintVector(values, "Before sort:");
		sort(values.begin(), values.end(), myobject);
		//PrintVector(values, "After sort:");
		PrintVector(values);
	}

	return 0;
}
