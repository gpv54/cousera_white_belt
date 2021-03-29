//============================================================================
// Name        : w1t4_devision.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Devision of two unsigned number in range [ 0 .. 1 000 000 ]
//============================================================================

#include <iostream>
using namespace std;

int main() {
	unsigned int A, B, result;

	cin >> A >> B;

	// test for devision on ZERO
	if ( B == 0 ){
		cout << "Impossible";
	} else {
		cout << (A / B);
	}

	return 0;
}
