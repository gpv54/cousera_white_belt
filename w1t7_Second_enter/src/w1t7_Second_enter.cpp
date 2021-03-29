//============================================================================
// Name        : w1t7_Second_enter.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Second enter
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	int found = 0;
	cin >> s;

	for (int i = 0; i < s.length(); i++){
		if(s[i] == 'f'){
			if(found){
				cout << i;
				found++;
				break;
			}
			found++;
		}
	}

	if (found == 1)	{
		cout << "-1";
	} else if (found == 0){
		cout << "-2";
	}

	return 0;
}
