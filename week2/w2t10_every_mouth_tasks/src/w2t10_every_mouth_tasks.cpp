//============================================================================
// Name        : w2t10_every_mouth_tasks.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Every mouth tasks
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	const int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int cur_month = 0; // January
	vector<vector<string>> days(month[cur_month]);

	int op;
	string cmd;
	cin >> op;
	vector<string> tsks;

	while(op--){
		cin >> cmd;
		if(cmd == "ADD"){
			string task;
			int d;
			cin >> d;
			// !TODO test day out in current month
			cin >> task;
			days[d - 1].push_back(task);
		} else if (cmd == "DUMP"){
			int d;
			cin >> d;
			cout << days[d - 1].size();
			for(auto w : days[d - 1]){
				cout << " " << w;
			}
			cout << endl;
		} else if (cmd == "NEXT"){
			int last_month = cur_month;
			cur_month++;
			if(cur_month > 11)
				cur_month = 0;
			if(month[cur_month] < month[last_month]){
				// переносим все дела из выпавших дней в последний день
				tsks.clear();
				for(auto i = month[cur_month]; i < month[last_month];){
					for(auto w : days[i]){
						days[month[cur_month] - 1].push_back(w);
					}
					i++;
				}
				days.resize(month[cur_month]);
				//days[cur_month - 1].insert(end[days[cur_month - 1]], begin(tsks), end(tsks));
			}
			days.resize(month[cur_month]);
		}
	}

	return 0;
}
