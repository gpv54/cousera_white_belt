//============================================================================
// Name        : w3t5_Names_and_Second_Names2.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Nanes & Last names 2
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;



typedef struct{
	string first_name;
	string last_name;
} sname;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {

    // добавить факт изменения имени на first_name в год year
	  string _first_name;
	  for(const auto& s : mNamesInYears){
		  if(year >= s.first && s.second.first_name != ""){
			  _first_name = s.second.first_name;
		  }
	  }

	  if(_first_name != first_name){
		  if(mNamesInYears.count(year) == 0)
			  mNamesInYears[year].last_name = "";
		  mNamesInYears[year].first_name = first_name;
	  }
  }

  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	  string _last_name;
	  for(const auto& s : mNamesInYears){
		  if(year >= s.first && s.second.last_name != ""){
			  _last_name = s.second.last_name;
		  }
	  }
	  if(_last_name != last_name){
		  if(mNamesInYears.count(year) == 0)
				  mNamesInYears[year].first_name = "";
		  mNamesInYears[year].last_name = last_name;
	  }
  }

  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
	  string _first_name = "", _last_name = "";

	  if(!mNamesInYears.size())
		  return "Incognito";

	  for(const auto& s : mNamesInYears){
		  if(year >= s.first && s.second.first_name != ""){
			  _first_name = s.second.first_name;
		  }

		  if(year >= s.first && s.second.last_name != ""){
			  _last_name = s.second.last_name;
		  }
	  }

	  string _full_name = "";

	  if(_first_name == "" && _last_name == ""){
		  _full_name += "Incognito";
	  } else if(_first_name != "" && _last_name != ""){
		  _full_name+=_first_name;
		  _full_name+=" ";
		  _full_name+=_last_name;
	  } else if(_first_name != ""){
		  _full_name+=_first_name;
		  _full_name+=" with unknown last name";
	  } else {
		  _full_name+=_last_name;
		  _full_name+=" with unknown first name";
	  }

	  return _full_name;
  }

  string GetFullNameWithHistory(int year) {
	  // получить имя и фамилию по состоянию на конец года year
	  string _first_name = "", _last_name = "";
	  string _list_previous_first_names = "", _list_previous_last_names = "";
	  map<int, string> mFistNames; // Fist names in order to adds
	  map<int, string> mLastNames; // Fist names in order to adds

	  if(!mNamesInYears.size())
		  return "Incognito";

	  for(const auto& s : mNamesInYears){
		  if(year >= s.first && s.second.first_name != ""){
			  _first_name = s.second.first_name;
			  mFistNames[mFistNames.size()] = s.second.first_name;
		  }

		  if(year >= s.first && s.second.last_name != ""){
			  _last_name = s.second.last_name;
			  mLastNames[mLastNames.size()] = s.second.last_name;
		  }
	  }
	  // Last name the same as in current name
	  mFistNames.erase(mFistNames.size() - 1);
	  mLastNames.erase(mLastNames.size() - 1);
	  // The same as current name's
	  if(mFistNames.size() == 1 && mFistNames[0] == _first_name){
		  mFistNames.erase(mFistNames.size() - 1);
	  }
	  if(mLastNames.size() == 1 && mLastNames[0] == _last_name){
		  mLastNames.erase(mLastNames.size() - 1);
	  }

	  for (auto it = mFistNames.rbegin(); it != mFistNames.rend(); it++) {
		  _list_previous_first_names += it->second;
		  _list_previous_first_names += ", ";
	  }
	  if(_list_previous_first_names.size() && _list_previous_first_names[_list_previous_first_names.size() - 1] == ' ')
		  _list_previous_first_names.resize(_list_previous_first_names.size() - 2);

	  for (auto it = mLastNames.rbegin(); it != mLastNames.rend(); it++) {
		  _list_previous_last_names += it->second;
		  _list_previous_last_names += ", ";
	  }

	  if(_list_previous_last_names.size() && _list_previous_last_names[_list_previous_last_names.size() - 1] == ' ')
		  _list_previous_last_names.resize(_list_previous_last_names.size() - 2);

//	  cout << "Previous first names: " << _list_previous_first_names << endl;
//	  cout << "Previous last names: " << _list_previous_last_names << endl;

	  string _full_name = "";

	  if(_first_name == "" && _last_name == ""){
		  _full_name += "Incognito";
	  } else if(_first_name != "" && _last_name != ""){
		  _full_name+=_first_name;
		  if(_list_previous_first_names != ""){
			  _full_name+=" (";
			  _full_name+= _list_previous_first_names;
			  _full_name+=")";
		  }
		  _full_name+=" ";
		  _full_name+=_last_name;
		  if(_list_previous_last_names != ""){
			  _full_name+=" (";
			  _full_name+= _list_previous_last_names;
			  _full_name+=")";
		  }
	  } else if(_first_name != ""){
		  _full_name+=_first_name;
		  if(_list_previous_first_names != ""){
			  _full_name+=" (";
			  _full_name+= _list_previous_first_names;
			  _full_name+=")";
		  }
		  _full_name+=" with unknown last name";
	  } else {
		  _full_name+=_last_name;
		  if(_list_previous_last_names != ""){
			  _full_name+=" (";
			  _full_name+= _list_previous_last_names;
			  _full_name+=")";
		  }
		  _full_name+=" with unknown first name";
	  }
	  return _full_name;
  }

  void clearHistory(){
	  mNamesInYears.clear();
  }
private:
  // приватные поля
  map<int, sname> mNamesInYears;
//  map<int, string> mFistNames; // Fist names in order to adds
//  map<int, string> mLastNames; // Fist names in order to adds
};

#define NON_ID 0

typedef enum {
	chFirstName,
	chLastName,
	getFullName,
	getFullNameWithHistory,
	clHistory,
} em_act;

typedef struct {
	int id;
	em_act act;
	int year;
	string first_name;
	string last_name;
	string result;
} test_cases;

int checkCurrentTest(Person& p, const test_cases& test, string& out)
{
	string res;
	out = "";
	switch(test.act){
	case chFirstName:
		p.ChangeFirstName(test.year, test.first_name);
		out += "Change first_name to ";
		out += test.first_name;
		break;
	case chLastName:
		p.ChangeLastName(test.year, test.last_name);
		out += "Change sername to ";
		out += test.last_name;
		break;
	case getFullName:
		res = p.GetFullName(test.year);
		out += "Her fullname is ";
		out += res;
		break;
	case getFullNameWithHistory:
		res = p.GetFullNameWithHistory(test.year);
		out += "Her fullname is ";
		out += res;
		break;
	case clHistory:
		p.clearHistory();
		break;
	}
	if(res != test.result){
		return -1;
	}
	return 0;
}


int main() {
	Person person;

	string out_str;
	vector<test_cases> tc = {
// Test w3t4 example 1
		{1, chLastName, 1967, "", "Sergeeva", ""},
		{2, chFirstName, 1965, "Polina", "", ""},
		{3, getFullName, 1900, "", "", "Incognito"},
		{4, getFullName, 1965, "", "", "Polina with unknown last name"},
		{5, getFullName, 1990, "", "", "Polina Sergeeva"},
		{6, chFirstName, 1970, "Appolinaria", "", ""},
		{7, getFullName, 1969, "", "", "Polina Sergeeva"},
		{8, getFullName, 1970, "", "", "Appolinaria Sergeeva"},
		{9, chLastName, 1968, "", "Volkova", ""},
		{10, getFullName, 1969, "", "", "Polina Volkova"},
		{11, getFullName, 1970, "", "", "Appolinaria Volkova"},
		{12, chFirstName, 1967, "Polina", "", ""},
		{13, chLastName, 1965, "", "Sergeeva", ""},
		//{getFullName, 1900, "", "", "Incognito"},
		{14, getFullName, 1965, "", "", "Polina Sergeeva"},
		{NON_ID, clHistory, 0, "", "", ""},
		// Test w3t5 example 1
		{15, chFirstName, 1900, "Eugene", "", ""},
		{16, chLastName, 1900, "", "Sokolov", ""},
		{17, chLastName, 1910, "", "Sokolov", ""},
		{18, chFirstName, 1920, "Evgeny", "", ""},
		{19, chLastName, 1930, "", "Sokolov", ""},
		{20, getFullNameWithHistory, 1940, "", "", "Evgeny (Eugene) Sokolov"},
		{NON_ID, clHistory, 0, "", "", ""},
		// Test w3t5 example 2
		{21, chFirstName, 1965, "Polina", "", ""},
		{22, chLastName, 1967, "", "Sergeeva", ""},
		{23, getFullNameWithHistory, 1900, "", "", "Incognito"},
		{24, getFullNameWithHistory, 1965, "", "", "Polina with unknown last name"},
		{25, getFullNameWithHistory, 1990, "", "", "Polina Sergeeva"},
		{26, chFirstName, 1970, "Appolinaria", "", ""},
		{27, getFullNameWithHistory, 1969, "", "", "Polina Sergeeva"},
		{28, getFullNameWithHistory, 1970, "", "", "Appolinaria (Polina) Sergeeva"},
		{29, chLastName, 1968, "", "Volkova", ""},
		{30, getFullNameWithHistory, 1969, "", "", "Polina Volkova (Sergeeva)"},
		{31, getFullNameWithHistory, 1970, "", "", "Appolinaria (Polina) Volkova (Sergeeva)"},
		{32, chFirstName, 1990, "Polina", "", ""},
		{33, chLastName, 1990, "", "Volkova-Sergeeva", ""},
		{34, getFullNameWithHistory, 1990, "", "", "Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)"},
		{35, chFirstName, 1966, "Pauline", "", ""},
		{36, getFullNameWithHistory, 1966, "", "", "Pauline (Polina) with unknown last name"},
		{37, chLastName, 1960, "", "Sergeeva", ""},
		{38, getFullNameWithHistory, 1960, "", "", "Sergeeva with unknown first name"},
		{39, getFullNameWithHistory, 1967, "", "", "Pauline (Polina) Sergeeva"},
		{40, chLastName, 1961, "", "Ivanova", ""},
		{41, getFullNameWithHistory, 1967, "", "", "Pauline (Polina) Sergeeva (Ivanova, Sergeeva)"},
		{NON_ID, clHistory, 0, "", "", ""},
		// Test w3t5 example 3
		{42, chFirstName, 1965, "Polina", "", ""},
		{43, chFirstName, 1965, "Appolinaria", "", ""},
		{44, chLastName, 1965, "", "Sergeeva", ""},
		{45, chLastName, 1965, "", "Volkova", ""},
		{46, chLastName, 1965, "", "Volkova-Sergeeva", ""},
		{47, getFullNameWithHistory, 1964, "", "", "Incognito"},
		{48, getFullNameWithHistory, 1965, "", "", "Appolinaria Volkova-Sergeeva"},
		{49, getFullNameWithHistory, 1966, "", "", "Appolinaria Volkova-Sergeeva"},
		{NON_ID, clHistory, 0, "", "", ""},
	};

	bool _is_failed = false;
	for (int i = 0; i < tc.size(); i++){
		int r = checkCurrentTest(person, tc[i], out_str);
		if(!r){
			//cout << "Test " << tc[i].id << " successfull. With msg: " << " In " << tc[i].year << " " << out_str << endl;
		} else {
			_is_failed = true;
			cout << "Test " << tc[i].id << " has been broken! With msg: " << " In " << tc[i].year << " " << out_str << endl;
		}
	}
	if(!_is_failed){
		cout << "All test succesfull!" << endl;
	}

//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : {1900, 1965, 1990}) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	person.ChangeLastName(1968, "Volkova");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullName(year) << endl;
//	}
	return 0;
}
