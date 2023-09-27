//============================================================================
// Name        : w2t17_Sinonims.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Sinonims
//============================================================================

#include <iostream>
#include <set>
#include <map>;

using namespace std;

int main() {
	map<string, set<string>> dic;
	//map<string, > cnt;

	int cnt;
	string val1, val2, cmd;

	cin >> cnt;

	while(cnt--){
		cin >> cmd;
		if(cmd == "ADD"){
			cin >> val1 >> val2;
			set<string>& s = dic[val1];
			s.insert(val2);
			set<string>& s2 = dic[val2];
			s2.insert(val1);

		} else if(cmd == "COUNT"){
			cin >> val1;
			cout << dic[val1].size() << endl;

		} else if(cmd == "CHECK"){
			cin >> val1 >> val2;
			if(dic[val1].count(val2) || dic[val2].count(val1)){
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}

	return 0;
}
