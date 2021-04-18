//============================================================================
// Name        : w2t16_set_dictonary_values.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Set dictionary values
//============================================================================

#include <iostream>
#include <set>
#include <map>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m){
	set<string> s;
	for(auto w: m)
		s.insert(w.second);
	return s;
}

int main() {

	set<string> values = BuildMapValuesSet({
	    {1, "odd"},
	    {2, "even"},
	    {3, "odd"},
	    {4, "even"},
	    {5, "odd"}
	});

	for (const string& value : values) {
	  cout << value << endl;
	}

	return 0;
}
