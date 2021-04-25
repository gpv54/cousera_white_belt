//============================================================================
// Name        : _w5t1_Final_DB.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Final task for white belt
//============================================================================

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

//#define TEST

// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
	Date(int y, int m, int d){
		if (m < 1 || m > 12)
		{
			throw invalid_argument("Month value is invalid: " + std::to_string(m));
		} else if (d < 1 || d > 31)
		{
			throw invalid_argument("Day value is invalid: " + std::to_string(d));
		}

		year = y;
		month = m;
		day = d;
	}

	int GetYear() const {
		return year;
	}

	int GetMonth() const {
		return month;
	}

	int GetDay() const {
		return day;
	}

	string toString() const {
		stringstream ss;

		if(year < 0){
			ss << '-' << setw(4) << setfill('0') << to_string(year * -1) << '-'
			   << setw(2) << setfill('0') << to_string(month) << '-'
			   << setw(2) << setfill('0') << to_string(day);
		} else {
			ss << setw(4) << setfill('0') << to_string(year) << '-'
			   << setw(2) << setfill('0') << to_string(month) << '-'
			   << setw(2) << setfill('0') << to_string(day);
		}


		return ss.str();
	}

private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs){

	if(lhs.GetYear() < rhs.GetYear()){
		return true;
	}
	if(lhs.GetYear() == rhs.GetYear()){
		if(lhs.GetMonth() < rhs.GetMonth()){
			return true;
		}
		if(lhs.GetMonth() == rhs.GetMonth()){
			if(lhs.GetDay() < rhs.GetDay()){
				return true;
			}
		}
	}
	return false;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event){
		if (!event.empty())
			db[date.toString()].insert(event);
	}

	bool DeleteEvent(const Date& date, const string& event){
		string date_str = date.toString();
		if(db.count(date_str) > 0){
			if(db[date_str].count(event) > 0){
				db[date_str].erase(event);
				cout << "Deleted successfully" << endl;
#ifdef TEST
				addToTestOut("Deleted successfully");
#endif
				return true;
			} else {
				cout << "Event not found" << endl;
#ifdef TEST
				addToTestOut("Event not found");
#endif
				return false;
			}
		}
		return false;
	}

	int  DeleteDate(const Date& date){
		int count_events = 0;
		string date_str = date.toString();

		if(db.count(date_str) > 0){
			count_events = db.at(date_str).size();
			db.erase(date_str);
		}

		return count_events;
	}

	set<string> Find(const Date& date) const {
		string date_str = date.toString();
		set<string> cur_date_events;
		if(db.count(date_str) > 0){
			cur_date_events = db.at(date_str);
		}
		return cur_date_events;
	}

#ifdef TEST
	void Print() {
#else
	void Print() const {
#endif
		string date;
		if(db.size()){
			for(auto& d : db){
				for(auto e : d.second){
					if(d.first[0] != '-'){ // minus date
						cout << d.first << ' ' << e << endl;
#ifdef TEST
						addToTestOut(d.first + ' ' + e);
#endif
					}
				}
			}
		}
	}
#ifdef TEST
	vector<string>& getLastTestOut() {
		return cout_text;
	}
	void addToTestOut(string str) {
		cout_text.push_back(str);
	}

	void clearTestOut(){
		cout_text.clear();
	}
#endif
private:
#ifdef TEST
	vector<string> cout_text;
#endif
	map<string, set<string>> db;
};

Date StringToDate(string &str) {
	int y, m, d;
	bool is_correct = true;
	stringstream ss(str);

	is_correct = is_correct && (ss >> y);
	is_correct = is_correct && (ss.peek() == '-');
	ss.ignore(1);

	is_correct = is_correct && (ss >> m);
	is_correct = is_correct && (ss.peek() == '-');
	ss.ignore(1);

	is_correct = is_correct && (ss >> d);
	is_correct = is_correct && ss.eof();

	if (!is_correct)
	{
		throw invalid_argument("Wrong date format: " + str);
	}

	return Date(y, m, d);
}

void Processing(Database& db, string& command)
{
// Считайте команды с потока ввода и обработайте каждую
	if(command != ""){ // skip empty line
		stringstream ss(command);
		string action, date, event;
		ss >> action;
		// Parse action
		if(action == "Add"){
			ss >> date;
			ss >> event;
			if((event != "") && (event != " "))
				db.AddEvent(StringToDate(date), event);
		} else if(action == "Del"){
			event = "";
			ss >> date;
			if (!ss.eof()) {
				ss >> event;
			}

			if (!event.empty()){
				db.DeleteEvent(StringToDate(date), event);
			} else {
				int count = db.DeleteDate(StringToDate(date));
				cout << "Deleted " << count << " events" << endl;
#ifdef TEST
				db.addToTestOut("Deleted " + to_string(count) + " events");
#endif
			}
		} else if(action == "Find"){
			ss >> date;
			set<string> events = db.Find(StringToDate(date));
			for (string ev : events) {
				cout << ev << endl;
#ifdef TEST
				db.addToTestOut(ev);
#endif
			}
			//db.Find(StringToDate(date));
		} else if(action == "Print"){
			db.Print();
		} else {
			string res = string("Unknown command: " + action);
			throw invalid_argument(res.c_str());
		}
	}
}

typedef struct {
	int id;
	string cmd;
	vector<string> res = {};
} stest;

int main() {
	Database db;
#ifdef TEST
		vector<stest> test_cases = {
		{ 1, "Add 0-1-2 event1"},
		{ 2, "Add 1-2-3 event2"},
		{ 3, "Find 0-1-2", {"event1"} },
		{ 4, "", },
		{ 5, "Del 0-1-2", {"Deleted 1 events"} },
		{ 6, "Print", {"0001-02-03 event2"} },
		{ 7, "Del 1-2-3 event2", {"Deleted successfully"} },
		{ 8, "Del 1-2-3 event2", {"Event not found"} },
// USER SCENARIES
// CMD ADDs
		{ 9, "Add 1-1-1 event1" },
		{ 10, "Add 2-2-2 event2" },
		{ 11, "Add 1-1-1 event3" },
		{ 12, "Add -1-1-1 eventX" },
		{ 13, "Add 1-1-1 event1" },
		{ 14, "Print", {"0001-01-01 event1", "0001-01-01 event3", "0002-02-02 event2"}},
// Find
		{ 15, "Find 1-1-1", {"event1", "event3"}},
// Test command
		{ 16, "Send 1-1-1", {"Unknown command: Send"}},
		{ 17, "Find 1--1-1", {"Month value is invalid: -1"}},
		{ 18, "Find 1-1--1", {"Day value is invalid: -1"}},
		{ 19, "Find 1-+1-+1", {"event1", "event3"}},
		{ 20, "Find 1-1-+1", {"event1", "event3"}},
		{ 21, "Find 1-+1-1", {"event1", "event3"}},
		{ 22, "Find +1-+1-1", {"event1", "event3"}},
		{ 23, "Find -1-+1-1", {"eventX"}},
		{ 24, "Find 1---1-1", {"Wrong date format: 1---1-1"}},
		{ 25, "Find --1-1-1", {"Wrong date format: --1-1-1"}},
		{ 26, "Find 1---1-1", {"Wrong date format: 1---1-1"}},
		{ 27, "Find 1-1---1", {"Wrong date format: 1-1---1"}},
		{ 28, "Add 0-13-32 event1", {"Month value is invalid: 13"}},
		{ 29, "Del -1-1-1 eventX", {"Deleted successfully"}},
		};
		for(auto tid = 0; tid < test_cases.size(); tid++){
			stest& tc = test_cases[tid];
			cout << "[" << tc.id << "] ";
			if(tc.res.size() == 0)
				cout << endl;
			db.clearTestOut();
			try {
				Processing(db, tc.cmd);
			} catch (invalid_argument& e){
				cout << e.what() << endl;
				db.addToTestOut(string(e.what()));
			}
			if(tc.res.size() != db.getLastTestOut().size()){
				cout << "[-] Id(" << tc.id << ") Answer has not correct size!" << endl;
				return 1;
			}

			if(tc.res.size()){
				vector<string>& res = db.getLastTestOut();
				for (auto i = 0; i < tc.res.size(); i++){
					if(tc.res[i] != res[i]){
						cout << "[-] Id(" << tc.id << ") line (" << i <<") Wrong answer!" << endl;
						return 1;
					}
				}
			}
		}
		cout << "OK";
#else
	try {
		string command;
		while (getline(cin, command)) {
			Processing(db, command);
		}
	} catch(invalid_argument& e){
		cout << e.what() << endl;
	}
#endif


	return 0;
}
