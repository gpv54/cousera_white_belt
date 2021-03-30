//============================================================================
// Name        : w2t7_revert_order2.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Revert order 2
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

//void PrintVector(const vector<int>& v){
//	for(auto w : v)
//		cout << w << " ";
//	cout << endl;
//}

vector<int> Reversed(const vector<int>& v){
	vector<int> v2;
	if(v.size()){
		for (int i = v.size()-1; i >= 0; i--){
			v2.push_back(v[i]);
		}
	}
	return v2;
}

int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
	vector<int> v2;
	v2 = Reversed(numbers);
	//PrintVector(v2);
	return 0;
}
