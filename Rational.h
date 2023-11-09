// a Rational object holds one Rational number, one fraction  // Carol Zander
// Example from Deitel and Deitel: C++ How To Program

#ifndef RAT2_H
#define RAT2_H
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// Rational numbers:  defined as ratios of whole number, otherwise known as 
//    fractions (can be proper or improper), all follow the laws of arithmetic 
//    such as commutative law, associative law, distributive law, etc.
//    Examples include  2/3 , -7/8 , 20/9
//
// Implementation and assumptions:
//   -- Rationals are stored as integer numerators and denominators
//   -- if the rational number is negative, the numerator is the negative
//   -- all stored rationals are reduced to lowest terms
//   -- all arithmetic operators return Rationals reduced to lowest terms
//   -- Dividing by zero returns zero

class Rational {
public:
	// overloaded <<: prints "DIVIDE BY ZERO ERROR!!!" if denominator is zero,
	//    prints whole numbers without denominator (as ints), otherwise uses '/'
	friend ostream& operator<<(ostream&, const Rational&);

	// overloaded >>: takes 2 ints as numerator and denominator, does no
	//    error checking, standard C casting between floats, char, etc occurs
	friend istream& operator>>(istream&, Rational&);

	//overloaded operator+ as friends
	friend const Rational operator+(const Rational&, const int&);
	friend const Rational operator+(const int&, const Rational&);
	friend const Rational operator+(const Rational&, const Rational&);

	// overloaded unary minus operator as friend 
	friend const Rational operator-(Rational&);

	// default constructor:  parameters are numerator and denominator resp.
	Rational(int = 0, int = 1);

	// copy constructor
	Rational(const Rational & r);

	// Assignment operator
	const Rational & operator=(const Rational & r);

	// add member function to demonstrate awkwardness
	const Rational add(const Rational&) const;

	// arithmetic operators
	// const Rational operator-() const;                   // unary minus
	//const Rational operator+(const Rational &) const;   // add 2 Rationals
	const Rational operator-(const Rational &) const;   // subtract 2 Rationals
	const Rational operator*(const Rational &) const;   // multiply 2 Rationals
	const Rational operator/(const Rational &) const;   // divide 2 Rationals
	// division by zero terminates 

	// boolean comparison operators
	const bool operator>(const Rational &) const;       // is object > parameter?
	const bool operator<(const Rational &) const;       // is object < parameter?
	const bool operator>=(const Rational &) const;      // is object >= parameter?
	const bool operator<=(const Rational &) const;      // is object >= parameter?
	const bool operator==(const Rational &) const;      // is object == parameter?
	const bool operator!=(const Rational &) const;      // is object != parameter?

	// assignment operators
	const Rational& operator+=(const Rational &);       // current object += parameter
	// const Rational& operator-=(const Rational &);       // current object -= parameter
	// const Rational& operator*=(const Rational &);       // current object *= parameter
	// const Rational& operator/=(const Rational &);       // current object /= parameter
	// division by zero terminates 

	// increment and decrement operators
	Rational& operator++();
	Rational operator++(int);
    
	// cast operator to cast a Rational into a double
    // operator double();

private:
	int numerator;                       // numerator of fraction
	int denominator;                     // denominator of fraction
	void reduce();                       // reduce fraction to lowest terms
};


#endif
