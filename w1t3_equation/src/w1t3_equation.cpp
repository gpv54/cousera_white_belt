//============================================================================
// Name        : w1t3_equation.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Square equation
//============================================================================

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double D;
	double A, B, C;
	double x1, x2;

	// Get a, b, c
	cin >> A >> B >> C;


	if ( A == 0 ){
	// A=0, Bx + C = 0;
		if ( B != 0 ) // If B == 0, than devision on zero!
		{
			x1 = -C / B;
			cout << x1 << endl;
		}
	} else {
	// Ax2 + Bx + C = 0, Check D && find results
		D = B*B - 4 * A * C;
		if(D > 0){
				// We are have 2 result
				x1 = (-B + sqrt(D)) / ( 2 * A);
				x2 = (-B - sqrt(D)) / ( 2 * A);
				cout << x1 << " " << x2 << endl;
			} else if (D == 0) {
				// We are have 1 result
				x1 = (-B + sqrt(D)) / ( 2 * A);
				cout << x1 << endl;
			}
		// else {
		//		cout "We don't have result."
		// }
	}

	return 0;
}
