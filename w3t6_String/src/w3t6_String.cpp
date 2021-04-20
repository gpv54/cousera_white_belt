//============================================================================
// Name        : w3t6_String.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : String!
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

class ReversibleString {
public:
	ReversibleString() {}

	ReversibleString(const string& s)
	{
		str = s;
	}

	void Reverse(){
		reverse(str.begin(), str.end());
	}

	string ToString() const{
		return str;
	}
private:
	string str;
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;
	return 0;
}
