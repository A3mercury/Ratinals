//Rational.cpp
#include"Rational.h"
#include<sstream>

Rational::Rational(long NewNumerator, long NewDenominator)
{
	m_Numerator = NewNumerator;
	m_Denominator = NewDenominator;
	Reduce();
}

const Rational& Rational::operator=(const Rational & rValue)
{
	m_Numerator = rValue.m_Numerator;
	m_Denominator = rValue.m_Denominator;
	Reduce();
	return *this;
}

Rational& Rational::operator++()
{
	m_Numerator += m_Denominator;
	Reduce();
	return *this;
}

Rational Rational::operator++(int Garbage)
{
	Rational result = *this;
	m_Numerator += m_Denominator;
	Reduce();
	return result;
}

bool Rational::operator==(const Rational & rValue) const
{
	bool result = true;
	if (m_Numerator != rValue.m_Numerator || m_Denominator != rValue.m_Denominator)
	{
		result = false;
	}
	return result;
}

const Rational Rational::operator+ (const Rational & rValue) const
{
	long lcm = LeastCommonMultiple(rValue.m_Denominator, m_Denominator);
	long resultNumerator = (m_Numerator * (lcm / m_Denominator)) +
		(rValue.m_Numerator * (lcm / rValue.m_Denominator));
	Rational result(resultNumerator, lcm);
	return result;
}

Rational& Rational::operator+= (const Rational & rValue)
{
	*this = *this + rValue;
	Reduce();
	return *this;
}

string Rational::operator()() const
{
	std::stringstream stream;
	stream << m_Numerator << "/" << m_Denominator;
	return stream.str();
}

long Rational::LeastCommonMultiple(long x, long y) const
{
	bool Continue = true;
	long Guess = x;

	while (Continue)
	{
		if (Guess % y == 0)
		{
			Continue = false;
		}
		else
		{
			Guess += x;
		}
	}

	return Guess;
}

long Rational::GreatestCommonDivisor(long x, long y) const
{
	long Remainder = x % y;

	while (Remainder != 0)
	{
		x = y;
		y = Remainder;
		Remainder = x % y;
	}

	return y;
}

void Rational::Reduce()
{
	long GCD = GreatestCommonDivisor(m_Numerator, m_Denominator);

	m_Numerator = m_Numerator / GCD;
	m_Denominator = m_Denominator / GCD;
}

ostream &operator<<(ostream & out, const Rational & Fraction)
{
	out << Fraction.getNumerator() << "/" << Fraction.getDenominator();
	return out;
}

istream &operator>>(istream & in, Rational & Fraction)
{
	int n;
	int d;
	char c;

	in >> n >> c >> d;
}

long Rational::getNumerator()const
{
	return m_Numerator;
}

long Rational::getDenominator()const
{
	return m_Denominator;
}

const Rational operator+ (const long lValue, const Rational & rValue)
{
	Rational newLValue(lValue);
	return newLValue + rValue;
}

const Rational operator- (const long lValue, const Rational & rValue)
{
	Rational newLValue(lValue);
	return newLValue - rValue;
}

const Rational operator* (const long lValue, const Rational & rValue)
{
	Rational newLValue(lValue);
	return newLValue * rValue;
}

const Rational operator/ (const long lValue, const Rational & rValue)
{
	Rational newLValue(lValue);
	return newLValue / rValue;
}

