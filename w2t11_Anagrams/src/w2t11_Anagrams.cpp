//============================================================================
// Name        : w2t11_Anagrams.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Anagrams
//============================================================================

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void BuildCharCounters(map<char, int>& a, string word)
{
	a.clear();
	for(auto& ch : word){
		a[ch]++;
	}
}

bool CompareMap(const map<char, int>& a, map<char, int>& b)
{
	if(a.size() != b.size())
		return false;
	for(auto& w : a){
		if(w.second != b[w.first])
			return false;
	}
	return true;
}

void PrintMap(const map<char, int>& m){
	for(auto w : m){
		cout << "Char: " << w.first << " count: " << w.second << endl;
	}
	cout << endl;
}

int main() {
	int cn;
	vector<map<char, int>> dic(2);
	string word1, word2;

	cin >> cn;
	while (cn--){
		cin >> word1 >> word2;
		BuildCharCounters(dic[0], word1);
		BuildCharCounters(dic[1], word2);
		if(CompareMap(dic[0], dic[1]))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
