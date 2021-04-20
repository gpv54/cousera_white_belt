//============================================================================
// Name        : w3t8_Initial_ways.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Initial ways
//============================================================================

#include <iostream>
using namespace std;

struct Incognizable {
	int a = 0;
	int b = 0;
};

int main() {
	Incognizable a;
	Incognizable b = {};
	Incognizable c = {0};
	Incognizable d = {0, 1};
	cout << "Success!";
	return 0;
}
