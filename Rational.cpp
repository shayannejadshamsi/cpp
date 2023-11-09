// a Rational object holds one Rational number, one fraction
// Example from Deitel and Deitel: C++ How To Program

#include "Rational.h"

//----------------------------------------------------------------------------
// Rational 
// Parameters are numerator and denominator respectively.
// Takes zero, one, two parameters. Parameters have default values of 0, 1.


Rational::Rational(int n, int d) {
	numerator = d < 0 ? -n : n;            // numerator is always the negative
	denominator = d < 0 ? -d : d;          // denominator is always positive
	reduce();                              // to lowest terms
}

//----------------------------------------------------------------------------
// Rational(Rational) 
// Copy constructor

Rational::Rational(const Rational & r)
: numerator(r.numerator), denominator(r.denominator) { }

//----------------------------------------------------------------------------
// operator=
// overloaded assignment operator

const Rational& Rational::operator=(const Rational & r){
	if (&r != this) {
		numerator = r.numerator;
		denominator = r.denominator;
	}
	return *this;
}

//----------------------------------------------------------------------------
// unary minus member operator
/*
const Rational Rational::operator-() const {
Rational minus;
minus.numerator = -(this->numerator);
minus.denominator = this->denominator;
return minus;
}
*/

//----------------------------------------------------------------------------
// unary minus free operator

const Rational operator-(Rational& a) {
	Rational minus;
	minus.numerator = -(a.numerator);
	minus.denominator = a.denominator;
	return minus;
}

/*
//----------------------------------------------------------------------------
// operator+
// overloaded +: addition of 2 Rationals, current object and parameter
// Result is reduced to lowest terms.

const Rational Rational::operator+(const Rational& a) const {
Rational sum;

sum.numerator = a.numerator * denominator + a.denominator * numerator;
// same as:
// sum.numerator = a.numerator * this->denominator
//                 + a.denominator * this->numerator;

sum.denominator = a.denominator * denominator;
sum.reduce();

return sum;
}
*/

//----------------------------------------------------------------------------
// operator-  
// overloaded -: subtraction of 2 Rationals, current object and parameter
// Result is reduced to lowest terms.

const Rational Rational::operator-(const Rational& s) const {
	Rational sub;

	sub.numerator = s.denominator * numerator - denominator * s.numerator;
	sub.denominator = s.denominator * denominator;
	sub.reduce();

	return sub;
}

//----------------------------------------------------------------------------
// operator*  
// overloaded *: multiplication of 2 Rationals, current object and parameter
// Result is reduced to lowest terms.

const Rational Rational::operator*(const Rational& m) const {
	Rational mult;

	mult.numerator = m.numerator * numerator;
	mult.denominator = m.denominator * denominator;
	mult.reduce();

	return mult;
}

//----------------------------------------------------------------------------
// operator/  
// overloaded /: division of 2 Rationals, current object and parameter,
//               division by zero terminates prog
// Result is reduced to lowest terms.

const Rational Rational::operator/(const Rational& v) const {
	Rational div;

	if (v.numerator != 0) {              // make sure new denominator != zero
		div.numerator = v.denominator * numerator;
		div.denominator = denominator * v.numerator;
		div.reduce();
	}
	else {
		return 0;
	}

	return div;
}

//----------------------------------------------------------------------------
// operator> 
// overloaded >: true if current object is > parameter, otherwise false

const bool Rational::operator>(const Rational& r) const {
	return (float)numerator / denominator > (float)r.numerator / r.denominator;
}

//----------------------------------------------------------------------------
// operator< 
// overloaded <: true if current object is < parameter, otherwise false

const bool Rational::operator<(const Rational& r) const {
	return (float)numerator / denominator < (float)r.numerator / r.denominator;
}

//----------------------------------------------------------------------------
// operator>= 
// overloaded >=: true if current object is >= parameter, otherwise false

const bool Rational::operator>=(const Rational& r) const {
	return *this == r || *this > r;
}

//----------------------------------------------------------------------------
// operator<= 
// overloaded <=: true if current object is <= parameter, otherwise false

const bool Rational::operator<=(const Rational& r) const {
	return *this == r || *this < r;
}

//----------------------------------------------------------------------------
// operator== 
// overloaded ==: true if current object is == parameter, otherwise false

const bool Rational::operator==(const Rational& r) const {
	return (numerator == r.numerator && denominator == r.denominator);
}

//----------------------------------------------------------------------------
// operator!= 
// overloaded !=: true if current object is != parameter, otherwise false

const bool Rational::operator!=(const Rational& r) const {
	return !(*this == r);
}

//----------------------------------------------------------------------------
// operator+=  
// overloaded +=: current object = current object + parameter 
// Result is reduced to lowest terms.

const Rational& Rational::operator+=(const Rational& a) {

	numerator = a.numerator * denominator + a.denominator * numerator;
	denominator = a.denominator * denominator;

	// Or the following although less efficient because of extra new/deletes
	// *this = *this + a;  

	reduce();

	return *this;
}

//----------------------------------------------------------------------------
// reduce 
// reduce fraction to lowest terms

void Rational::reduce() {
	int n = numerator < 0 ? -numerator : numerator;  // make numerator positive
	int d = denominator;
	int largest = n > d ? n : d;           // larger of numerator and denom

	int gcd = 0;                           // greatest common divisor

	// find largest value that divides both numerator and denominator evenly
	for (int loop = largest; loop >= 2; loop--)
	if (numerator % loop == 0 && denominator % loop == 0) {
		gcd = loop;
		break;
	}

	// alter numerator, denominator if originally not reduced to lowest terms
	if (gcd != 0) {
		numerator /= gcd;
		denominator /= gcd;
	}
}

//----------------------------------------------------------------------------
// add method to demonstrate awkwarness

const Rational Rational::add(const Rational & r) const {
	int n = numerator * r.denominator + denominator * r.numerator;
	int d = denominator * r.denominator;
	return Rational(n, d);
}

//----------------------------------------------------------------------------
// prefix increment operator

Rational& Rational::operator++(){
	numerator = numerator + denominator;
	return *this;
}

//----------------------------------------------------------------------------
// postfix increment operator

Rational Rational::operator++(int){
	Rational temp = *this;
	numerator = numerator + denominator;
	return temp;
}

//----------------------------------------------------------------------------
// casting operator

/*
Rational::operator double(){
return numerator / (double)denominator;
}
*/

//----------------------------------------------------------------------------
// operator<< 
// overloaded <<: prints "DIVIDE BY ZERO ERROR!!!" if denominator is zero,
//    prints whole numbers without denominator (as ints), otherwise uses '/'

ostream& operator<<(ostream &output, const Rational &r) {
	if (r.denominator == 0)
		output << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
	else if (r.numerator == 0)                              // zero rational
		output << 0;
	else if (r.denominator == 1)                            // whole number
		output << r.numerator;
	else
		output << r.numerator << "/" << r.denominator;

	return output;
}

//----------------------------------------------------------------------------
// operator>> 
// overloaded >>: takes 2 ints as numerator and denominator, does no
//    error checking, standard C casting between floats, char, etc occurs

istream& operator>>(istream &input, Rational &r) {
	input >> r.numerator >> r.denominator;
	r.reduce();

	return input;
}

//----------------------------------------------------------------------------
// operator+  
// overloaded +: addition of one Rational and one int as parameters
// Result is reduced to lowest terms.

const Rational operator+(const Rational& a, const int& b_int) {
	Rational sum, b(b_int, 1);

	sum.numerator = a.numerator * b.denominator + a.denominator * b.numerator;

	sum.denominator = a.denominator * b.denominator;
	sum.reduce();

	return sum;
}

//----------------------------------------------------------------------------
// operator+  
// overloaded +: addition of one int and one Rational as parameters
// Result is reduced to lowest terms.

const Rational operator+(const int& a_int, const Rational& b) {
	Rational sum, a(a_int, 1);

	sum.numerator = a.numerator * b.denominator + a.denominator * b.numerator;

	sum.denominator = a.denominator * b.denominator;
	sum.reduce();

	return sum;
}


//----------------------------------------------------------------------------
// operator+  
// overloaded +: addition of 2 Rationals as parameters
// Result is reduced to lowest terms.

const Rational operator+(const Rational& a, const Rational& b) {
	Rational sum;

	sum.numerator = a.numerator * b.denominator + a.denominator * b.numerator;

	sum.denominator = a.denominator * b.denominator;
	sum.reduce();

	return sum;
}
