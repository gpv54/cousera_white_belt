//============================================================================
// Name        : w1t2_minimal_string.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Select the minimal string of presented
//============================================================================

#include <iostream>
using namespace std;

int main() {
	string s1, s2, s3;

	//cout << "Please enter tree strings separated with tabs..." << endl;
	cin >> s1 >> s2 >> s3;

	// select minimal string of two first
	if ( s1 < s2){
		// select minimal between s1 and s3
		if( s1 < s3){
			cout << s1;
		} else {
			cout << s3;
		}
	} else {
		// select minimal between s2 and s3
		if( s2 < s3){
			cout << s2;
		} else {
			cout << s3;
		}
	}

	return 0;
}
