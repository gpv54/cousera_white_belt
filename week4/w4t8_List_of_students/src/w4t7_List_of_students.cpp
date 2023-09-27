//============================================================================
// Name        : w4t8_List_of_students.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : List of students
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

struct Student {
	string name;
	string lastname;
	int day;
	int month;
	int year;
};

string Request(vector<Student>& students, const string& req, int id){
	if(id <= 0 || id > students.size()){
		return "bad request";
	}
	const Student& cur_student = students[id - 1];

	if(req == "name"){
		return cur_student.name + ' ' + cur_student.lastname;
	} else if(req == "date"){
		return to_string(cur_student.day) + '.' + to_string(cur_student.month) + '.' + to_string(cur_student.year);
	} else {
		return "bad request";
	}
}

int main() {
	vector<Student> students;
	Student new_student;
	int count, count_req;

	cin >> count;
	if(count < 0 && count > 10000){
		cout << "Wrong count of students, range [0:10000]" << endl;
		return 0;
	}

	while(count){
		cin >> new_student.name;
		cin >> new_student.lastname;
		cin >> new_student.day;
		cin >> new_student.month;
		cin >> new_student.year;
		students.push_back(new_student);
		count--;
	}

	cin >> count_req;
	if(count_req < 0 && count_req > 10000){
		cout << "Wrong count of request, range [0:10000]" << endl;
	}

	string req;
	int id;
	while(count_req){
		cin >> req >> id;
		cout << Request(students, req, id) << endl;
		count_req--;
	}

	return 0;
}
