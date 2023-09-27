//============================================================================
// Name        : w2t6_revert_order.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Revert order
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

//void PrintVector(const vector<int>& v){
//	for(auto w : v)
//		cout << w << " ";
//	cout << endl;
//}

void Reverse(vector<int>& v) {
	int i = 0;
	int j = v.size() - 1;
	int tmp;

	if(v.size()){
		while (i != j) {
			// swap
			tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
			i++;
			if(i == j)
				break;
			j--;
		}
	}
	//PrintVector(v);
}


int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
	Reverse(numbers);
	return 0;
}
