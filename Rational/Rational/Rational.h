//Rational.h
#include<iostream>
#include<string>

using std::ostream;
using std::istream;
using std::string;

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
public:
	Rational(long NewNumerator = 0, long NewDenominator = 1);

	const Rational & operator=(const Rational & rValue);
	bool operator==(const Rational& rValue) const;
	const Rational operator+ (const Rational& rValue) const;
	const Rational operator- (const Rational& rValue) const;
	const Rational operator* (const Rational& rValue) const;
	const Rational operator/ (const Rational& rValue) const;

	Rational& operator+= (const Rational& rValue);
	Rational& operator-= (const Rational& rValue);
	Rational& operator*= (const Rational& rValue);
	Rational& operator/= (const Rational& rValue);

	string operator()() const;
	operator double() const;

	Rational& operator++();
	Rational& operator--();
	Rational operator++(int Garbage);
	Rational operator--(int Garbage);

	long getNumerator()const;
	long getDenominator()const;
private:
	long m_Numerator;
	long m_Denominator;

	long LeastCommonMultiple(long x, long y) const;
	long GreatestCommonDivisor(long x, long y) const;
	void Reduce();

	//any other private functions you may need
};

//prototypes for non-member methods
ostream &operator<<(ostream&, const Rational& Fraction);
istream &operator>>(istream&, Rational& Fraction);

const Rational operator+ (const long lValue, const Rational & rValue);
const Rational operator- (const long lValue, const Rational & rValue);
const Rational operator* (const long lValue, const Rational & rValue);
const Rational operator/ (const long lValue, const Rational & rValue);

#endif