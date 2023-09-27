//============================================================================
// Name        : w4t11_Rational_Throw.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Rational Throw
//============================================================================

#include <iostream>
using namespace std;

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
			throw invalid_argument("Denominator not equal zero!");
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
		throw domain_error("Divide to zero!");
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

int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	} catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	} catch (domain_error&) {
	}

	cout << "OK" << endl;
	return 0;
}
