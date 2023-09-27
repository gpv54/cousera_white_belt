//============================================================================
// Name        : w3t3_sorted_strings.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Sorted strings
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
	 sortStrings.push_back(s);
	 sort(sortStrings.begin(), sortStrings.end());
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
	  return sortStrings;
  }
private:
  vector<string> sortStrings;
  // приватные поля
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}
