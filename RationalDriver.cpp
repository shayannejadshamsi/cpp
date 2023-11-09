#include "Rational.h"
#include <iostream>
using namespace std;

int main(){
	Rational r1(1,2), r2(2,3), r3, r4(2,-3), r5(-2,3);

	cout << r1 + r2 << endl;
	cout << r1.add(r2) << endl;

	cin >> r3;
	cout << r3 << endl;
	Rational a(5, 6);
	Rational b(2, 3);
	Rational c;

	c = a + b;  
	c = a + 25;
	c = 25 + a;

	a = a; //self-assignment test

//	float f = b; //casting operator implicitly called


//	cout << f << endl;
	cout << ++a << endl;
	//Note that the cast operator has precedence over everyting else here!
	//cout << b++ << endl << b << endl << (float)b << endl;

	system("PAUSE");
	return EXIT_SUCCESS;

}