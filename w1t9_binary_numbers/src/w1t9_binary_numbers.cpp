//============================================================================
// Name        : w1t9_binary_numbers.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Binary numbers
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	// map hex digits
	vector<string> bin = {
			"0000",		// 0
			"0001",		// 1
			"0010",		// 2
			"0011",		// 3
			"0100",		// 4
			"0101",		// 5
			"0110",		// 6
			"0111",		// 7
			"1000",		// 8
			"1001",		// 9
			"1010",		// A
			"1011",		// B
			"1100",		// C
			"1101",		// D
			"1110",		// E
			"1111"		// F
	};

	// input number
	cin >> N;

	// split int to char[4]
	vector<char> hex;
	hex.push_back(N >> 24 & 0xff);
	hex.push_back(N >> 16 & 0xff);
	hex.push_back(N >> 8 & 0xff);
	hex.push_back(N & 0xff);

	string str = "";

	// convert to binary format with helper
	for (int i = 0; i < 4; i++){
		str += bin[hex[i]>>4&0x0f];
		str += bin[hex[i]&0x0f];
	}

	// remove first zeroes
	bool first_zero = true;
	for (unsigned int i = 0; i < str.size(); i++){

		if(str[i] != '0' && first_zero)
			first_zero = false;

		if (!first_zero){
			cout << str[i];
		}
	}

	return 0;
}
