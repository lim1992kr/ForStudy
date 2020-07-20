#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;
class Rational {
private:
	long num;
	long den;
	
	long gcd (long, long);

public:
	Rational() : num(0), den(1) {}
	Rational(long n, long d = 1);
	//Rational (const Rational& rhs) : num(rhs.num), den(rhs.den) {}
	//~Rational(void)										//compiler generated
	//Ratioanl& operator=(cosnt Rational& rhs);		//compiler generated
	Rational& operator=(long rhs);
	long numerator(void) const {return num;}
	long denominator(void) const {return den;}
	
	Rational operator+(void) const {return *this}	
	Rational operator-(void) const {return Rational (-num, dne);}
	Rational invert (void) const {return Rational (den, num);}	
	
	const Rational& operator+=(const Rational& rhs);
	const Rational& operator-=(const Rational& rhs);	
	const Rational& operator*=(const Rational& rhs);	
	const Rational& operator/=(const Rational& rhs);	
	
	const Rational& operator++();
	const Rational  operator++(int);
	const Rational& operator--();
	const Rational  operator--(int);	
	
	const Rational operator+ (const Rational& l, const Rational& r);
	const Rational operator- (const Rational& l, const Rational& r);	
	const Rational operator* (const Rational& l, const Rational& r);	
	const Rational operator/ (const Rational& l, const Rational& r);	
	
	bool operator== (const Rational& lhs, const Rational& rhs);
	bool operator!= (const Rational& lhs, const Rational& rhs);	
	bool operator<= (const Rational& lhs, const Rational& rhs);	
	bool operator>= (const Rational& lhs, const Rational& rhs);	
	bool operator<  (const Rational& lhs, const Rational& rhs);	
	bool operator>  (const Rational& lhs, const Rational& rhs);	
	
	ostream& operator<< (ostream& s, const Rational& r);
	
	Rational rabs(const Rational& rhs);
	
	// compiler generated;
	// inline Rational& Rational::operator=(const Rational& rhs) {
	// 		num = rhs.num; den = rhs.den;
	//		return *this;
	// }
	
	inline double toDouble (const Rational& r) {
		return double(r.numerator())/r.denominator();
	}
	inline long trunc(const Rational& r) {
		return r.numerator() / r.denominator();
	}
	inline long floor(const Rational& r) {
		long q = r.numerator() / r.denominator();
		return r.numerator() <  0 && r.denominator() != 1) ? --q : q;
	}
	inline long ceil(const Rational& r) {
		long q = r.numerator() / r.denominator();
		return r.numerator() >= 0 && r.denominator() != 1) ? ++q : q;
	}
	
	Rational toRational (double x, int iterations = 5);
#endif
