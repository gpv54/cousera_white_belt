//============================================================================
// Name        : w2t13_Bus_stops1.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Bus stops 1
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void bussesForStop(map<string, vector<string>>& mbus, string stop, map<int, string>& order){
	bool bus_is_accessed = false;
	for(auto& o: order){ // sort out of order busses
		vector<string>& b = mbus[o.second];
		if(count(b.begin(), b.end(), stop) != 0){ // if stops found in this busses
			bus_is_accessed = true;
			for (auto& m : mbus){ // find buses for vector stops
				if(m.second == b){
					cout << m.first << " ";
				}
			}
		}
	}
	if(!bus_is_accessed)
		cout << "No stop";
	cout << endl;
}

void stopForBus(map<string, vector<string>>& mbus, string bus, map<int, string>& order){
	vector<string> tmpbus;
	if(!mbus.count(bus)){ // No busses
		cout << "No bus" << endl;
	} else {
		for(auto& m: mbus[bus]){ // all stops for current bus
			tmpbus.clear();
			cout << "Stop " << m << ": ";
			for(auto b : order){
				if(b.second == bus){
					continue; // skip current bus stop
				} else {
					vector<string>& ss = mbus[b.second];
					if(count(ss.begin(), ss.end(), m)){
						tmpbus.push_back(b.second);
					}
				}
			}

			if(tmpbus.size()){
				for(auto& s : tmpbus){
					cout << s << " ";
				}
			} else {
				cout << "no interchange";
			}
			cout << endl;
		}
	}
}

void allBuses(const map<string, vector<string>>& mbus){
	if(!mbus.size()){
		cout << "No buses" << endl;
	} else {
		for(auto& b : mbus){
			cout << "Bus " << b.first << ": ";
			for(auto& s: b.second){
				cout << s << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	map<string, vector<string>> mbus;
	map<int, string> order;
	int op;
	string cmd, name_bus;
	int bus_counter=0;
	string val;


	cin >> op;

	if(op <= 0)
		return 0;

	while(op--){
		cin >> cmd;
		if(cmd == "NEW_BUS"){
			int cnt;
			cin >> name_bus >> cnt;

			order[bus_counter++] = name_bus;
			vector<string>& bs = mbus[name_bus];
			while(cnt--){
				cin >> val;
				bs.push_back(val);
			}

		} else if(cmd == "BUSES_FOR_STOP"){
			cin >> val;
			bussesForStop(mbus, val, order);
		} else if (cmd == "STOPS_FOR_BUS"){
			cin >> val;
			stopForBus(mbus, val, order);
		} else if (cmd == "ALL_BUSES"){
			allBuses(mbus);
		}
	}

	return 0;
}
