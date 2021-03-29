//============================================================================
// Name        : w1t1_a_plus_b.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Week 1, Task 1, A+B
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int d1, d2;
	//cout << "Please enter two digits..." << endl;
	// 1. digits no more than abs(100000)
	cin >> d1 >> d2;
	// 2. we not need to check 1-st condition
	cout << (d1 + d2);
	return 0;
}
