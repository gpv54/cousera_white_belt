//============================================================================
// Name        : w2t15_Count_unique_strings.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Calculate count of unique strings
//============================================================================

#include <iostream>
#include <set>
using namespace std;

int main() {
	int cnt;
	set<string> str;
	string val;

	cin >> cnt;
	while (cnt--){
//		for(auto& w : str){
			cin >> val;
			str.insert(val);
		//}
	}

	cout << str.size();

	return 0;
}
