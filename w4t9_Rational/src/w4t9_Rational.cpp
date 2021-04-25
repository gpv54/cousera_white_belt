//============================================================================
// Name        : w4t9_Rational.cpp
// Author      : GPV
// Version     : 1.0
// Copyright   : none
// Description : Rational
//============================================================================


#include <iostream>
//#include <numeric> // gcd
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

//#define PART1
//#define PART2 // Реализуйте для класса Rational операторы ==, + и -
//#define PART3 // Реализуйте для класса Rational операторы * и /
//#define PART4 // Реализуйте для класса Rational операторы << и >>
#define PART5 // Реализовать возможность использовать объекты класса Rational в качестве элементов контейнера set и ключей в контейнере map

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
			cout << "Denominator musn't be zero! (change to 1)" << endl;
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
	//cout << lhs.Numerator() << '/' << lhs.Denominator() << " == " << rhs.Numerator() << '/' << rhs.Denominator();
	if(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()){
//		cout << " is true" << endl;
		return true;
	}
//	cout << " is false" << endl;
	return false;
}

Rational operator*(const Rational& lhs, const Rational& rhs){
	return Rational(lhs.Numerator() * rhs.Numerator(),
				lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs){
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
//	cout << lhs.Numerator() << '/' << lhs.Denominator() << " > " << rhs.Numerator() << '/' << rhs.Denominator();
//	bool val = lhs.toDouble() > rhs.toDouble();
//	cout << " " << lhs.toDouble() << " > " << rhs.toDouble() << " ";
//	if(val){
//		cout << " is true" << endl;
//	} else {
//		cout << " is false" << endl;
//	}

	return lhs.toDouble() > rhs.toDouble();
}

bool operator<(const Rational& lhs, const Rational& rhs){
//	cout << lhs.Numerator() << '/' << lhs.Denominator() << " < " << rhs.Numerator() << '/' << rhs.Denominator();
//	bool val = lhs.toDouble() < rhs.toDouble();
//	cout << " " << lhs.toDouble() << " < " << rhs.toDouble() << " ";
//	if(val){
//		cout << " is true" << endl;
//	} else {
//		cout << " is false" << endl;
//	}

	return lhs.toDouble() < rhs.toDouble();
}


int main() {
#ifdef PART1
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 4;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 5;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 6;
        }
    }
#endif
#ifdef PART2
    {
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b; // 6/6 = 1/1
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}
#endif
#ifdef PART3
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}
#endif
#ifdef PART4
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("");
		Rational r;
		bool correct = !(input >> r);
		if (!correct) {
			cout << "Read from empty stream works incorrectly" << endl;
			return 3;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;

		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 4;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 5;
		}
	}

	{
		istringstream input1("1*2"), input2("1/"), input3("/4");
		Rational r1, r2, r3;
		input1 >> r1;
		input2 >> r2;
		input3 >> r3;
		bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
		if (!correct) {
			cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
				 << r1 << " " << r2 << " " << r3 << endl;

			return 6;
		}
	}
#endif
#ifdef PART5
//	{
//		istringstream s{"5*9"};
//		Rational r;
//
//		if (!(s >> r)) {
//			cout << "TRUE" << endl;
//		  // Ожидаемо, мы должны попасть сюда из-за некорректного разделителя у 5*9...
//		} else {
//		  // ...но мы попадем сюда, если не будем использовать особый метод setstate и
//		  // флаг ios_base::failbit
//			cout << "FALSE" << endl;
//		}
//
//	}

	{
		const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};

		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}
#endif
    cout << "OK" << endl;
    return 0;
}
