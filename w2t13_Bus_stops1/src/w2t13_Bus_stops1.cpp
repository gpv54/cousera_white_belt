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
			for (auto& m : mbus){ // find busses for vector stops
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

void stopForBus(map<string, vector<string>>& mbus, string bus){
	if(!mbus.count(bus)){ // No busses
		cout << "No bus" << endl;
	} else {
		for(auto& m: mbus[bus]){ // all stops for current bus
			cout << "Stop " << m << ": ";
			for(auto& b: mbus){ // sort out all buses
				if(b.first == bus){
					continue; // skip current bus stop
				} else {
					if(count(b.second.begin(), b.second.end(), m)){
						cout << b.first << " ";
					} else {
						cout << "no interchange";
						break;
					}
				}
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

//			if(mbus.count(name_bus)){ // No busses
//				break;
//			} else if (cnt <= 0){
//				break;
//			} // !TODO check bus stops equal to cnt

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
			stopForBus(mbus, val);
		} else if (cmd == "ALL_BUSES"){
			allBuses(mbus);
		}
	}

	return 0;
}
