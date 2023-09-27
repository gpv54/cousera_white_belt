//============================================================================
// Name        : w2t14_Bus_stops2.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Bus stops 2
//============================================================================

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int op;
	map<int, vector<string>> mbus;
	vector<string> curBus;
	int cnt, last_mbus, iter = 1;
	string var;
	bool already_added = false;

	cin >> op;

	if(op <= 0)
		return 0;

	while(op--){

		cin >> cnt;

		// fill current bus stops
		curBus.clear();
		while(cnt--){
			cin >> var;
			curBus.push_back(var);
		}

		//check with curent map of bus stops
		for(auto& b : mbus){

			last_mbus = b.first;
			if(b.second.size() == curBus.size()){
				already_added = true;
				for(int i = 0; i < b.second.size(); i++){
					if(b.second[i] != curBus[i]){
						already_added = false;
						break;
					}
				}
			} else {
				already_added = false;
			}

			if(already_added){
				break;
			}
		}

		if(already_added){
			cout << "Already exists for " << last_mbus << endl;
			already_added = false;
		} else {
			mbus[iter] = curBus;
			cout << "New bus " << iter << endl;
			iter++;
		}
	}

	return 0;
}
