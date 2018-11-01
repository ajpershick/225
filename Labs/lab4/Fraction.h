#pragma once
#include <string>
using namespace std;

class Fraction
{
public:
	// Constructors and Destructor
	Fraction(void);
	Fraction(int n, int d);
	~Fraction(void);
	Fraction operator+(const Fraction & f) const;
	Fraction operator-(const Fraction & f) const;
	Fraction operator*(const Fraction & f) const;
	Fraction operator/(const Fraction & f) const;

	friend ostream & operator<<(ostream & os, const Fraction & f);
	// Overloaded operators
	// +, -, *, and /


private:
	int numerator;		//the "top" of the fraction
	int denominator;	//the "bottom" of the fraction

	// PRE: 
	// POST: Fraction is simplified, e.g. 3/9, simplifies to 1/3
	void simplify();

	// PRE:
	// POST: Returns the (positive) greatest common divisor of a and b
	int gcd(int a, int b)const;
	
	// Friend functions
	// ...
};

class DivideByZeroException {};
