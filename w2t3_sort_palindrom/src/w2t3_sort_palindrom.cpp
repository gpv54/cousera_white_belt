//============================================================================
// Name        : w2t3_sort_palindrom.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Order palindrom
//============================================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getWordsFromString(string str) {
	string w;
	vector<string> words;
    for (int i = 0; i < str.size(); i++) {
        if(str[i] == ','){
        	if(w.size())
        		words.push_back(w);
        	w.clear();
        } else {
        	w += str[i];
        }
    }
    if(w.size() && w != ",")
    	words.push_back(w);
    return words;
}

bool IsPalindrom(string str) {
	int count = str.size();
	if(count <= 1){
		return true;
	}
	int i = 0, j = count - 1;
	do {
		if(str[i++] != str[j--]){
			return false;
		}
	} while (count--);
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
	vector<string> orderWords;
	for(auto w : words){
		if(IsPalindrom(w) && w.size() >= minLength)
			orderWords.push_back(w);
	}
	return orderWords;
}

int main() {
	string s;
	int minLenght;
	vector<string> wordsOrder;

	cout << "Enter words separate with comma:" << endl;
	cin >> s;

	cout << "Enter min str length:" << endl;
	cin >> minLenght;

	wordsOrder = PalindromFilter(getWordsFromString(s), minLenght);
	for(auto w : wordsOrder)
		cout << w << " ";

	return 0;
}
