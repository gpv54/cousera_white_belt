//============================================================================
// Name        : w4t12_Rational_calculator.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Rational calculator
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//#define TEST_CASES

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
    	// numerator ( числитель ) - p
		// ---------------------
		// denominator ( знаменатель ) - q
    	p = 0;
    	q = 1;
    }

    Rational(int numerator, int denominator) {
        init(numerator, denominator);
    }

    int Numerator() const {
    	return p;
    }

    int Denominator() const {
    	return q;
    }

    void init(int numerator, int denominator){
		if(denominator == 0){
			//cout << "Denominator musn't be zero! (change to 1)" << endl;
			throw invalid_argument("Invalid argument");
			p = numerator;
			q = 1;
		}

		if(numerator == 0){

			p = 0;
			q = 1;
		} else {
			// computes the greatest common division
			if(numerator < 0 && denominator < 0){
				numerator = -numerator;
				denominator = -denominator;
			} else if(denominator < 0){
				denominator = -denominator;
				numerator = -numerator;
			}
			int devision = this->gcd(abs(numerator), denominator);
			p = numerator / devision;
			q = denominator / devision;
		}
	}

    double toDouble() const {
    	return p * 1. / q * 1.;
    }

private:

    int gcd(int a, int b){
    	while ( a && b){
			if (a > b){
				a = a % b;
			} else {
				b = b % a;
			}
			if( (b - a) > 0)
				b = b - a;
		}
    	return (a + b);
    }

    int p, q;
};

Rational operator+(const Rational& lhs, const Rational& rhs){
	return Rational(lhs.Numerator() * rhs.Denominator() +
			rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs){
	return Rational(lhs.Numerator() * rhs.Denominator() -
				rhs.Numerator() * lhs.Denominator(),
			lhs.Denominator() * rhs.Denominator());
}

bool operator==(const Rational& lhs, const Rational& rhs){
	if(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()){
		return true;
	}
	return false;
}

Rational operator*(const Rational& lhs, const Rational& rhs){
	return Rational(lhs.Numerator() * rhs.Numerator(),
				lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs){
	if(lhs.Denominator() * rhs.Numerator() == 0){
		throw domain_error("Division by zero");
	}

	return Rational(lhs.Numerator() * rhs.Denominator(),
					lhs.Denominator() * rhs.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& rhs){
	stream << rhs.Numerator() << '/' << rhs.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& rhs){
	int numerator, denominator;
	char ch;
	bool is_correct = true;
	if(!(stream >> numerator)){
		is_correct = false;
	}

	if(!(stream >> ch) || ch != '/'){
		is_correct = false;
	}

	if(!(stream >> denominator)){
		is_correct = false;
	}

	if(is_correct){
		rhs.init(numerator, denominator);
	}

// Set ios_base::failbit see lesson attachments
	if(!is_correct){
		stream.setstate(ios_base::failbit);
	}

	return stream;
}

bool operator!(const Rational& lhs){
	if(lhs.Numerator() == 0){ // !0 == 1
		return true;
	}
	return false; // !1 == 0
}

Rational& operator>>(const Rational& lhs, Rational& rhs){
	rhs.init(lhs.Numerator(), lhs.Denominator());
	return rhs;
}

bool operator>(const Rational& lhs, const Rational& rhs){
	return lhs.toDouble() > rhs.toDouble();
}

bool operator<(const Rational& lhs, const Rational& rhs){
	return lhs.toDouble() < rhs.toDouble();
}

string Calc(stringstream& in)
{
	stringstream out;
	char op;
	Rational r1, r2;

	try {
		in >> r1 >> op >> r2;
		switch(op){
			case '+':
				out << r1 + r2;
				break;
			case '-':
				out << r1 - r2;
				break;
			case '*':
				out << r1 * r2;
				break;
			case '/':
				out << r1 / r2;
				break;
			default:
				out << "Unknown operation!";
				break;
		}
	} catch (invalid_argument& ex) {
		return ex.what();
	} catch (domain_error& ex) {
		return ex.what();
	}

	return out.str();
}

int main() {

#ifndef TEST_CASES
	string in_str;
	getline(cin, in_str);
	stringstream ss(in_str);
	cout << Calc(ss);
#else
	string res;
	{
		stringstream in("1/2 + 1/3");
		res = Calc(in);
		if(res != "5/6"){
			cout << "Test cases 1 failed val: " << res;
			return 1;
		}
	}

	{
		stringstream in("1/2 + 5/0");
		res = Calc(in);
		if(res != "Invalid argument"){
			cout << "Test cases 2 failed val: " << res;
			return 2;
		}
	}

	{
		stringstream in("4/5 / 0/8");
		res = Calc(in);
		if(res != "Division by zero"){
			cout << "Test cases 3 failed val: " << res;
			return 3;
		}
	}

	{
		stringstream in("2/3 + 4/3");
		res = Calc(in);
		if(res != "2/1"){
			cout << "Test cases 4 failed val: " << res;
			return 4;
		}
	}

	{
		stringstream in("5/7 - 2/9");
		res = Calc(in);
		if(res != "31/63"){
			cout << "Test cases 5 failed val: " << res;
			return 5;
		}
	}

	{
		stringstream in("2/3 * 4/3");
		res = Calc(in);
		if(res != "8/9"){
			cout << "Test cases 6 failed val: " << res;
			return 6;
		}
	}

	{
		stringstream in("5/4 / 15/8");
		res = Calc(in);
		if(res != "2/3"){
			cout << "Test cases 7 failed val: " << res;
			return 7;
		}
	}

	cout << "OK";
#endif

	return 0;
}
