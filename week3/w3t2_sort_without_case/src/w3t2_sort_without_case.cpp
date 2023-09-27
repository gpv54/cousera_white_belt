//============================================================================
// Name        : w3t2_sort_without_case.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Sort without case
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct myclass {
  bool operator() (string str1,string str2) {

	  for(auto &s1 : str1){
		  s1 = tolower(s1);
	  }

	  for(auto &s2 : str2){
		  s2 = tolower(s2);
	  }

	  return str1 < str2;
  }
} myobject;

void PrintVector(const vector<string>& vec/*, const string& s*/){
	//cout << s << endl;
	for (auto w: vec)
		cout << w << " ";
	cout << endl;
}

int main() {
	int N;
	string s;
	vector<string> values;

	cin >> N;

	if(N > 0 && N <= 1000){
		while(N--){
			cin >> s;
			//if(s.size() && s.size() <= 15){ // !TODO check available symbols [0-9,a-z,A-Z]
				values.push_back(s);
			//}
		}

		//PrintVector(values, "Before sort:");
		sort(values.begin(), values.end(), myobject);
		//PrintVector(values, "After sort:");
		PrintVector(values);
		//PrintVector(values);
	}

	return 0;
}
