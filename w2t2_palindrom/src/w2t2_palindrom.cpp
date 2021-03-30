//============================================================================
// Name        : w2t2_palindrom.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Implement palindrom
//============================================================================

#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string str) {
	int count = str.size();
	if(count <= 1){
		return true;
	}
	int i = 0, j = count - 1;
	do {
		if(str[i++] != str[j--]){
			return false;
		}
	} while (count--);
	return true;
}

int main() {
	string str;
	cin >> str;
	if(IsPalindrom(str)){
		cout << "true";
	} else {
		cout << "false";
	}

	return 0;
}
