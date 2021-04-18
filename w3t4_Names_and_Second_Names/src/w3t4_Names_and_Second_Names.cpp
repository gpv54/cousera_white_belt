//============================================================================
// Name        : w3t4_Names_and_Second_Names.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Names & Second names
//============================================================================

#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef struct{
	string name;
	string sname;
//	bool is_changed_name;
//	bool is_changed_sname;
} sname;
//
//class Person {
//public:
//  void ChangeFirstName(int year, const string& first_name) {
//	  int is_found = pers.count(year);
//
//	  if(!is_found){
////		  string sname = "";
////		  for(const auto& s : pers){ // find last sername if it possible
////			  if(year >= s.first){
////				  sname = s.second.sername;
////			  }
////		  }
//		  pers[year].name = first_name;
//		  //pers[year].sername = sname;
//		  pers[year].sname = "";
////		  for(auto& s : pers){ // change all fist name in next years
////			  if(year < s.first){
////				  s.second.name = first_name;
////			  }
////		  }
//	  }
//  }
//
//  void ChangeLastName(int year, const string& last_name) {
//	  int is_found = pers.count(year);
//
//  	  if(!is_found){
////		  string name = "";
////		  for(const auto& s : pers){
////			  if(year >= s.first){
////				  name = s.second.name;
////			  }
////		  }
//		  pers[year].sname = last_name;
//		  pers[year].name = "";
//		  //pers[year].name = name;
////		  for(auto& s : pers){
////			  if(year < s.first){
////				  s.second.sername = last_name;
////			  }
////		  }
//	  }
//  }
//
//
//
//  string GetFullName(int year) {
//
//	  sname nm = {"", ""};
//
//	  if(!pers.size())
//		  return "Incognito";
//
//	  for(const auto& s : pers){
//		  if(year >= s.first && s.second.sname != ""){
//			  nm.sname = s.second.sname;
//		  }
//		  if(year >= s.first && s.second.name != ""){
//			  nm.name = s.second.name;
//		  }
//	  }
//
//	  string full_name = "";
//
//	  if(nm.name == "" && nm.sname == ""){
//		  full_name += "Incognito";
//	  } else if(nm.name != "" && nm.sname != ""){
//		  full_name+=nm.name;
//		  full_name+=" ";
//		  full_name+=nm.sname;
//	  } else if(nm.name != ""){
//		  full_name+=nm.name;
//		  full_name+=" with unknown last name";
//	  } else {
//		  full_name+=nm.sname;
//		  full_name+=" with unknown first name";
//	  }
//
//	  return full_name;
//  }
//private:
//  map<int, sname> pers;
//};


class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        if (YearNameSoname.count(year) == 0) YearNameSoname[year].sname = "";
        YearNameSoname[year].name = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        if (YearNameSoname.count(year) == 0) YearNameSoname[year].name = "";
        YearNameSoname[year].sname = last_name;
    }
    string GetFullName(int year) {
        if (YearNameSoname.size() == 0) {
            return "Incognito";
        }
        else {
            for (const auto& i : YearNameSoname) {
                if (year < i.first) return "Incognito";
                break;
            }
        }
        string nm = "";
        string sn = "";
        for (const auto& i : YearNameSoname) {
            if (i.first <= year && i.second.sname != "") sn = i.second.sname;
            if (i.first <= year && i.second.name != "") nm = i.second.name;
        }
        if(nm == "") return sn + " with unknown first name";
        else if(sn == "") return nm + " with unknown last name";
        else return nm + " " + sn;
    }
private:
    map<int, sname> YearNameSoname;
};


//typedef enum {
//	chFirstName,
//	chLastName,
//	getFullName
//} em_act;
//
//typedef struct {
//	em_act act;
//	int year;
//	string name;
//	string sname;
//	string result;
//} test_cases;
//
//int checkCurrentTest(Person& p, const test_cases& test, string& out)
//{
//	string res;
//	out = "";
//	switch(test.act){
//	case chFirstName:
//		p.ChangeFirstName(test.year, test.name);
//		out += "Change name to ";
//		out += test.name;
//		break;
//	case chLastName:
//		p.ChangeLastName(test.year, test.sname);
//		out += "Change sername to ";
//		out += test.sname;
//		break;
//	case getFullName:
//		res = p.GetFullName(test.year);
//		out += "Her fullname is ";
//		out += res;
//		break;
//	}
//	if(res != test.result){
//		return -1;
//	}
//	return 0;
//}

int main() {
	Person person;

//	string out_str;
//	vector<test_cases> tc = {
//// common tests
//	{chLastName, 1967, "", "Sergeeva", ""},
//	{chFirstName, 1965, "Polina", "", ""},
//	{getFullName, 1900, "", "", "Incognito"},
//	{getFullName, 1965, "", "", "Polina with unknown last name"},
//	{getFullName, 1990, "", "", "Polina Sergeeva"},
//
//	{chFirstName, 1970, "Appolinaria", "", ""},
//	{getFullName, 1969, "", "", "Polina Sergeeva"},
//	{getFullName, 1970, "", "", "Appolinaria Sergeeva"},
//
//	{chLastName, 1968, "", "Volkova", ""},
//	{getFullName, 1969, "", "", "Polina Volkova"},
//	{getFullName, 1970, "", "", "Appolinaria Volkova"},

//	{chFirstName, 1967, "Polina", "", ""},
//	{chLastName, 1965, "", "Sergeeva", ""},
//	//{getFullName, 1900, "", "", "Incognito"},
//	{getFullName, 1965, "", "", "Sergeeva with unknown first name"},

// custom tests

//	{chFirstName, 1950, "Maximus", "", ""},
//	{chLastName, 1955, "", "Riviera", ""},
//
//	{getFullName, 1949, "", "", "Incognito"},
//	{getFullName, 1955, "", "", "Maximus Riviera"},

//	};

//	for (int i = 1950; i < 2000; i++)
//	{
//		tc.push_back({getFullName, i, "", "", ""});
//	}

//	for (int i = 0; i < tc.size(); i++){
//		int r = checkCurrentTest(person, tc[i], out_str);
//		if(!r){
//			cout << "Test " << i << " successfull. With msg: " << " In " << tc[i].year << " " << out_str << endl;
//		} else {
//			cout << "Test " << i << " has been broken! With msg: " << " In " << tc[i].year << " " << out_str << endl;
//		}
//	}

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}
