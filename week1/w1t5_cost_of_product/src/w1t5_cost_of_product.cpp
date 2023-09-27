//============================================================================
// Name        : w1t5_cost_of_product.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Calculate cost of product
//============================================================================

#include <iostream>
using namespace std;

// test envs
// 100 110 120 5 10
// 115 110 120 5 10
// 150 110 120 5 12.5

int main() {
	double N; // base cost
	double A; // cost = ( N + A > discount == X)
	double B; // cost = ( N + B > discount == Y)
	double X; // discount if N + A %
	double Y; // discount if N + B %

	cin >> N >> A >> B >> X >> Y;

	if ( N > B ){
		N -= N / 100. * Y; // discount in cost B
	} else if ( N > A ){
		N -= N / 100. * X; // discount in cost A
	}

	cout << N;

	return 0;
}
