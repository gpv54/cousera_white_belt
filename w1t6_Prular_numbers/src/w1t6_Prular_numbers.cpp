//============================================================================
// Name        : w1t6_Prular_numbers.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Plural numbers
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int A, B, i;
	cin >> A >> B;

	for (i = A; i <= B; i++){
		if (i % 2 == 0){
			cout << i;
			if (i != B)
				cout << ' ';
		}
	}

	return 0;
}
