//============================================================================
// Name        : w2t9_queue.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Queue
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

#define WORRIED true
#define RELAXED false

void Come(vector<bool>& q, int count){
	while(count != 0){
		if(count > 0){
			q.push_back(RELAXED);
			count--;
		} else {
			if(!q.empty())
				q.erase(q.end());
			count++;
		}
	}
}

void Worry(vector<bool>& q, int index){
	if(index >= 0 && index < q.size())
		q[index] = WORRIED;
}

void Quiet(vector<bool>& q, int index){
	if(index >= 0 && index < q.size())
		q[index] = RELAXED;
}

int Worry_count(const vector<bool>& q)
{
	int count_worried = 0;
	for(auto c : q){
		if(c == WORRIED)
			count_worried++;
	}
	return count_worried;
}

//void PrintVector(const vector<int>& v)
//{
//	for(auto w : v)
//		cout << w << endl;
//}

int main() {
	string key;
	int op; // count of operations
	int var; // argument of key
	vector<bool> queue;
	//vector<int> result;
	cin >> op;

	if(op <= 0)
		return 0;

	while(op--){
		cin >> key;
		if(key == "COME"){
			cin >> var;
			Come(queue, var);
		} else if(key == "WORRY") {
			cin >> var;
			Worry(queue, var);
		} else if(key == "QUIET") {
			cin >> var;
			Quiet(queue, var);
		} else if(key == "WORRY_COUNT"){
			//result.push_back(Worry_count(queue));
			cout << Worry_count(queue) << endl;
		}
	}
	//PrintVector(result);

	return 0;
}
