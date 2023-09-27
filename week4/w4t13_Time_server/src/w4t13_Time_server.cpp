//============================================================================
// Name        : w4t13_Time_server.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Time server
//============================================================================

#include <iostream>
using namespace std;

#define TEST 0

string AskTimeServer()
{
	string time = "unknown";
#if TEST == 1
	return "10:02:00";
#elif TEST == 2
	throw system_error(error_code());
#elif TEST == 3
	throw invalid_argument("1");
#endif
	return time;
}

class TimeServer {
public:
  string GetCurrentTime(){
		try {
			return last_fetched_time =  AskTimeServer();
		} catch (system_error& ex){
			return last_fetched_time;
		}
  }
private:
  string last_fetched_time = "00:00:00";
};

int main() {
	// Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	} catch (exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}

	return 0;
}
