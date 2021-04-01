//============================================================================
// Name        : w2t12_Capitals_helper.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Capitals helper
//============================================================================

#include <iostream>
#include <map>
using namespace std;

void changeCapital(map<string, string>& c, const string& country, const string& capital){
	if(c.count(country) == 0){
		cout << "Introduce new country " << country << " with capital " << capital << endl;
		c[country] = capital;
	} else {
		if(c[country] == capital){
			cout << "Country " << country << " hasn't changed its capital" << endl;
		} else {
			cout << "Country " << country << " has changed its capital from " << c[country] << " to " << capital << endl;
			c[country] = capital;
		}
	}
}

void renameCountry(map<string, string>& c, const string& country, const string& new_country){
	if(country == new_country || !c.count(country) || c.count(new_country)){
		cout << "Incorrect rename, skip" << endl;
	} else {
		string save_capital = c[country];
		c.erase(country);
		c[new_country] = save_capital;
		cout << "Country " << country << " with capital " << save_capital << " has been renamed to " << new_country << endl;
	}
}

void aboutCountry(map<string, string>& c, const string& country){
	if(!c.count(country)){
		cout << "Country " << country << " doesn't exist" << endl;
	} else {
		cout << "Country " << country << " has capital " << c[country] << endl;
	}
}

void dump(map<string, string>& m)
{
	if(!m.size()){
		cout << "There are no countries in the world" << endl;
	} else {
		// !TODO sort by country name/ map need to sort as default, need to test
		for (auto c : m){
			cout << c.first << "/" << c.second << " ";
		}
		cout << endl;
	}
}

int main() {
	map<string, string> countries;
	int op;
	cin >> op;
	string cmd, val1, val2;

	while(op--){
		cin >> cmd;
		if(cmd == "CHANGE_CAPITAL"){
			cin >> val1 >> val2;
			changeCapital(countries, val1, val2);
		} else if(cmd == "RENAME"){
			cin >> val1 >> val2;
			renameCountry(countries, val1, val2);
		} else if(cmd == "ABOUT"){
			cin >> val1;
			aboutCountry(countries, val1);
		} else if(cmd == "DUMP"){
			dump(countries);
		}
	}

	return 0;
}
