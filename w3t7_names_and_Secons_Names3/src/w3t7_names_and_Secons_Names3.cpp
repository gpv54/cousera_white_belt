//============================================================================
// Name        : w3t7_Names_and_Second_Names2.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Nanes & Last names 3
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

#define COURSERA
#define ENABLE_TESTS

#ifndef COURSERA
typedef struct{
	string first_name;
	string last_name;
} sname;
#endif

#ifdef COURSERA
// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
  string name;  // изначально имя неизвестно

  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }

  return name;
}

vector<string> FindNamesHistory(const map<int, string>& names_by_year,
                                int year) {
  vector<string> names;
  // перебираем всю историю в хронологическом порядке
  for (const auto& item : names_by_year) {
    // если очередное имя не относится к будущему и отличается от предыдущего,
    if (item.first <= year && (names.empty() || names.back() != item.second)) {
      // добавляем его в историю
      names.push_back(item.second);
    }
  }
  return names;
}

string BuildJoinedName(vector<string> names) {
  // нет истории — имя неизвестно
  if (names.empty()) {
    return "";
  }
  // меняем прямой хронологический порядок на обратный
  reverse(begin(names), end(names));

  // начинаем строить полное имя с самого последнего
  string joined_name = names[0];

  // перебираем все последующие имена
  for (int i = 1; i < names.size(); ++i) {
    if (i == 1) {
      // если это первое «историческое» имя, отделяем его от последнего скобкой
      joined_name += " (";
    } else {
      // если это не первое имя, отделяем от предыдущего запятой
      joined_name += ", ";
    }
    // и добавляем очередное имя
    joined_name += names[i];
  }

  // если в истории было больше одного имени, мы открывали скобку — закроем её
  if (names.size() > 1) {
    joined_name += ")";
  }
  // имя со всей историей готово
  return joined_name;
}

// см. решение предыдущей задачи
string BuildFullName(const string& first_name, const string& last_name) {
  if (first_name.empty() && last_name.empty()) {
    return "Incognito";
  } else if (first_name.empty()) {
    return last_name + " with unknown first name";
  } else if (last_name.empty()) {
    return first_name + " with unknown last name";
  } else {
    return first_name + " " + last_name;
  }
}

#endif

class Person {
public:
  Person(const string& first_name, const string& last_name, const int year){
	  year_bithday = year;
#ifdef COURSERA
	  first_names[year] = first_name;
	  last_names[year] = last_name;
#else
	  fist_name_in_year_bithday = first_name;
	  last_name_in_year_bithday = last_name;
	 // mNamesInYears[year_bithday] = { first_name, last_name };
      mNamesInYears[year_bithday - 1] = { first_name, last_name };
      for (auto& i : mNamesInYears) {
		if (i.first < year - 1) {
			mNamesInYears.erase(i.first);
		}
	  }
#endif
  }

  void ChangeFirstName(int year, const string& first_name) {
	  if(year < year_bithday){
		  return;
	  }
#ifdef COURSERA
	  first_names[year] = first_name;
#else
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
#endif
	  /*for (auto& i : mNamesInYears) {
		  if (year > i.first) {
			  if (mNamesInYears.count(year) == 0) mNamesInYears[year].last_name = "";
			  mNamesInYears[year].first_name = first_name;
		  }
		  break;
	  }*/
  }

  void ChangeLastName(int year, const string& last_name) {
	  if(year < year_bithday){
		  return;
	  }
#ifdef COURSERA
	  last_names[year] = last_name;
#else
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
	 /* for (auto& i : mNamesInYears) {
		  if (year > i.first) {
			  if (mNamesInYears.count(year) == 0) mNamesInYears[year].first_name = "";
			  mNamesInYears[year].last_name = last_name;
		  }
		  break;
	  }*/
#endif
  }

  string GetFullName(int year) const {
	  if (year < year_bithday)
		  return "No person";
#ifdef COURSERA
	  // найдём историю изменений имени и фамилии
	  // в данном случае это излишне, так как нам достаточно узнать последние имя и фамилию, но почему бы не использовать готовые функции?
	  const vector<string> first_names_history = FindFirstNamesHistory(year);
	  const vector<string> last_names_history = FindLastNamesHistory(year);

	  // подготовим данные для функции BuildFullName: возьмём последние имя и фамилию или оставим их пустыми, если они неизвестны
	  string first_name;
	  string last_name;
	  if (!first_names_history.empty()) {
		first_name = first_names_history.back();
	  }
	  if (!last_names_history.empty()) {
		last_name = last_names_history.back();
	  }
	  return BuildFullName(first_name, last_name);
#else
	  /*if (year_bithday != 0 && year < year_bithday) return "No person";
	  else if (mNamesInYears.size() == 0) {
		  return "Incognito";
	  }
	  else {
		  for (const auto& i : mNamesInYears) {
			  if (year < i.first) return "Incognito";
			  break;
		  }
	  }

	  string nm = "";
	  string sn = "";
	  for (const auto& i : mNamesInYears) {
		  if (i.first <= year && i.second.last_name != "") sn = i.second.last_name;
		  if (i.first <= year && i.second.first_name != "") nm = i.second.first_name;
	  }
	  if (nm == "") return sn + " with unknown first name";
	  else if (sn == "") return nm + " with unknown last name";
	  else return nm + " " + sn;*/
	  if(!mNamesInYears.size() && fist_name_in_year_bithday == "" && last_name_in_year_bithday == "")
		  return "Incognito";

	  string _first_name = "", _last_name = "";

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
#endif
  }

  string GetFullNameWithHistory(int year) const {
	  if (year < year_bithday)
		  return "No person";
#ifdef COURSERA
	  // получим полное имя со всей историей
	  const string first_name = BuildJoinedName(FindFirstNamesHistory(year));
	  // получим полную фамилию со всей историей
	  const string last_name = BuildJoinedName(FindLastNamesHistory(year));
	  // объединим их с помощью готовой функции
	  return BuildFullName(first_name, last_name);
#else
	  	 /*if (year_bithday != 0 && year < year_bithday) return "No person";
		 else if (mNamesInYears.size() == 0) {
			 return "Incognito";
		 }
		 else {
			 for (const auto& i : mNamesInYears) {
				 if (year < i.first) return "Incognito";
				 break;
			 }
		 }
		 string nm = "";
		 string sn = "";
		 vector<string> secondnames;
		 vector<string> firstnames;
		 for (const auto& i : mNamesInYears) {
			 if (i.first <= year && i.second.last_name != "") {
				 if (i.second.last_name != sn && sn != "") {
					 secondnames.push_back(sn);
				 }
				 sn = i.second.last_name;
			 }
			 if (i.first <= year && i.second.first_name != "") {
				 if (i.second.first_name != nm && nm != "") {
					 firstnames.push_back(nm);
				 }
				 nm = i.second.first_name;
			 }
		 }

		 string secnames_string = "", firstnames_string = "";
		 if (secondnames.size() > 0) {
			 secnames_string += " (" + secondnames[secondnames.size() - 1];
			 if (secondnames.size() > 1) {
				 for (int i = secondnames.size() - 1; i > 0; --i) {
					 secnames_string += ", " + secondnames[i - 1];
				 }
			 }
			 secnames_string += ")";
		 }
		 if (firstnames.size() > 0) {
			 firstnames_string += " (" + firstnames[firstnames.size() - 1];
			 if (firstnames.size() >1) {
				 for (int i = firstnames.size() - 1; i > 0; --i) {
					 firstnames_string += ", " + firstnames[i - 1];
				 }
			 }
			 firstnames_string += ")";
		 }

		 if (nm == "") return sn + secnames_string + " with unknown first name";
		 else if (sn == "") return nm + firstnames_string + " with unknown last name";
		 else return nm + firstnames_string + " " + sn + secnames_string;*/
	  // получить имя и фамилию по состоянию на конец года year

	  if(!mNamesInYears.size() && fist_name_in_year_bithday == "" && last_name_in_year_bithday == "")
	  		  return "Incognito";

	  string _first_name = "", _last_name = "";
	  string _list_previous_first_names = "", _list_previous_last_names = "";
	  map<int, string> mFistNames; // Fist names in order to adds
	  map<int, string> mLastNames; // Fist names in order to adds

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
#endif
  }

  void clearHistory(){
#ifdef COURSERA
	  first_names.clear();
	  last_names.clear();
	  first_names[year_bithday - 1] = fist_name_in_year_bithday;
	  last_names[year_bithday - 1] = last_name_in_year_bithday;
#else
	  mNamesInYears.clear();
	  mNamesInYears[year_bithday - 1].first_name = fist_name_in_year_bithday;
	  mNamesInYears[year_bithday - 1].last_name = last_name_in_year_bithday;
#endif
  }
private:
  // приватные поля
#ifdef COURSERA
  vector<string> FindFirstNamesHistory(int year) const {
	return FindNamesHistory(first_names, year);
  }
  vector<string> FindLastNamesHistory(int year) const {
	return FindNamesHistory(last_names, year);
  }
  map<int, string> first_names;
  map<int, string> last_names;
#else
  map<int, sname> mNamesInYears;
#endif
  string fist_name_in_year_bithday;
  string last_name_in_year_bithday;
  int year_bithday;
};

#ifdef ENABLE_TESTS
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

void PrintTestsCasesResult(vector<test_cases>& t, Person& p, const string& testid)
{
	bool _is_failed = false;
	string out_str;
	cout << "Start tests " << testid << endl;
	for (int i = 0; i < t.size(); i++){
		int r = checkCurrentTest(p, t[i], out_str);

		if(t[i].id == NON_ID){
			continue;
		}

		if(!r){
			cout << " (+) Test " << t[i].id << ". With msg: " << " In " << t[i].year << " " << out_str << endl;
		} else {
			_is_failed = true;
			cout << " ( ) Test " << t[i].id << ". With msg: " << " In " << t[i].year << " " << out_str << endl;
		}
	}
	if(!_is_failed){
		cout << "All test " << testid << " succesfull!" << endl;
	}
	cout << endl;
}
#endif

int main() {
#ifdef ENABLE_TESTS
	Person person_t1("", "", 0);

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

	PrintTestsCasesResult(tc, person_t1, "w3t4 - w3t5");

	Person person_t2("Polina", "Sergeeva", 1960);

	vector<test_cases> tc2 = {
	//      // Test w3t7 example 1
		{50, getFullNameWithHistory, 1959, "", "", "No person"},
		{51, getFullNameWithHistory, 1960, "", "", "Polina Sergeeva"},
		{52, chFirstName, 1965, "Appolinaria", "", ""},
		{53, chLastName, 1967, "", "Ivanova", ""},
		{54, getFullNameWithHistory, 1965, "", "", "Appolinaria (Polina) Sergeeva"},
		{55, getFullNameWithHistory, 1967, "", "", "Appolinaria (Polina) Ivanova (Sergeeva)"},
		{56, chFirstName, 1968, "Appolinaria2", "", ""},
		{57, chLastName, 1969, "", "Ivanova2", ""},
		{58, getFullNameWithHistory, 1968, "", "", "Appolinaria2 (Appolinaria, Polina) Ivanova (Sergeeva)"},
		{59, getFullNameWithHistory, 1969, "", "", "Appolinaria2 (Appolinaria, Polina) Ivanova2 (Ivanova, Sergeeva)"},
		{60, chFirstName, 1959, "AppolinariaX", "", ""},
		{61, chLastName, 1900, "", "IvanovaX", ""},
		{62, getFullNameWithHistory, -199, "", "", "No person"},
		{NON_ID, clHistory, 0, "", "", ""},
	};

	PrintTestsCasesResult(tc2, person_t2, "w3t7");

#endif

	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
	cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
	cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}
