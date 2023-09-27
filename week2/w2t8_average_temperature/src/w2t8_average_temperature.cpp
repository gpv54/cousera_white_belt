//============================================================================
// Name        : w2t8_average_temperature.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Average temperature
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int getAverage(const vector<int>& v) {
	int sum = 0;
	for (auto w : v)
		sum += w;
	return sum / v.size();
}

void PrintVector(const vector<int>& v){
	for(auto w : v)
		cout << w << " ";
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> inDays(n);

	// get n values
	for(auto &w : inDays)
		cin >> w;

	// get average from inDays
	int av = getAverage(inDays);

	vector<int> outDays;

	// find index days with values more than average
	for(int i = 0; i < inDays.size(); i++){
		if (inDays[i] > av)
			outDays.push_back(i);
	}

	// OUT values
	cout << outDays.size() << endl;
	PrintVector(outDays);

	return 0;
}
