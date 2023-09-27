//============================================================================
// Name        : w1t8_max_share_dev.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Max share div
//============================================================================

#include <iostream>
//#include <ctime>

using namespace std;


int main() {
	clock_t the_time;
//	double elapsed_time;

	long a, b, min;

	//the_time = clock();

	cin >> a >> b;

	while ( a && b){
		 if (a > b){
			 //long swp = a;
			 a = a % b;
		 } else {
			 b = b % a;
		 }
		 if( (b - a) > 0)
			 b = b - a;
	 }

	 cout << (a + b) << endl;

	 //elapsed_time = double(clock() - the_time);
	 //std::cout << "Elapsed time " << elapsed_time << " ticks." << std::endl;

	return 0;
}
