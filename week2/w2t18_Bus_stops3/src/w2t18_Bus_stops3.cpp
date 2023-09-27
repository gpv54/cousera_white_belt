//============================================================================
// Name        : w2t18_Bus_stops3.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Bus stops 3
//============================================================================

#include <iostream>
#include <set>
#include <map>
using namespace std;


int main() {
	int op, bus_num = 1;
	map<int, set<string>> bus;


	cin >> op;

	while(op--){
		int count;
		string val;
		set<string> tmp;
		bool exists = false;

		cin >> count;
		while(count--){
			cin >> val;
			tmp.insert(val);
		}

		for(const auto& b : bus ){
			if(b.second == tmp){
				cout << "Already exists for " << b.first << endl;
				exists = true;
			}
		}

		if(!exists){
			bus[bus_num] = tmp;
			cout << "New bus " << bus_num << endl;
			bus_num++;
		}
	}

	return 0;
}
