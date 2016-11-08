// OverloadingOperator.cpp : Defines the entry point for the console application.
// so lets state the overloading operator 

#include "stdafx.h"
#include <iostream>

using namespace std;

class Fraction 
{
private: 
	int m_numerator = 0;
	int m_denomerator = 1;
	

public:
	// Constructor
	Fraction(int numerator=0, int denominator=1):m_numerator(numerator), m_denomerator(denominator)
	{
		// We put Reduce in the constructor to ensure any fractions get reduced
		reduce();
	}

	void print()
	{
		cout << m_numerator << "/" << m_denomerator << '\n';
	}
	// Now we have to add friend functions that are operator overloaded which: 1b multiplication
	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int integer);
	friend Fraction operator*(int integer, const Fraction &f1);
	
	
	friend ostream& operator<<(ostream& out, const Fraction &f1);
	friend istream& operator>> (istream& in, Fraction &f1);

	// Extra credit
	static int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}

	void reduce()
	{
		int gcd = Fraction::gcd(m_numerator, m_denomerator);
		m_numerator /= gcd;
		m_denomerator /= gcd;
	}
	
};
Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denomerator * f2.m_denomerator);
}

Fraction operator*(const Fraction &f1, int integer)
{
	// we can give it anonymous action by equation (numerator * integer)/ denominator
	return Fraction(f1.m_numerator * integer, f1.m_denomerator);
}
Fraction operator*(int integer, const Fraction &f1)
{
	return Fraction(integer * f1.m_numerator, f1.m_denomerator);
}

ostream& operator<<(ostream& out, const Fraction &f1)
{
	out << f1.m_numerator << " / " << f1.m_denomerator;
	return out;
}

istream& operator >> (istream& in, Fraction &f1)
{
	char c;
	in >> f1.m_numerator;
	in >> c; // ignore the '/' separator
	in >> f1.m_numerator;

	return in;
}

int main()
{
	/*Fraction f1(2, 5);
	f1.print();

	Fraction f2(3, 8);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 2;
	f4.print();

	Fraction f5 = 2 * f2;
	f5.print();
	
	
	

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();*/


	Fraction f1;
	cout << "Enter fraction 1: ";
	cin >> f1;

	Fraction f2;
	cout << "Enter fraction 2: ";
	cin >> f2;

	cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

    return 0;
}

