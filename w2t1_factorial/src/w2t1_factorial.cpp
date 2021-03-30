//============================================================================
// Name        : w2t1_factorial.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Function factorial
//============================================================================

#include <iostream>
using namespace std;

int Factorial(int val) {
	int factorial = 1;

	if(val <= 1)
		return 1;

	do {
		factorial = val * factorial;
	} while (--val);
	return factorial;
}

int main() {
	int val;
	cin >> val;

	cout << Factorial(val);

	return 0;
}
