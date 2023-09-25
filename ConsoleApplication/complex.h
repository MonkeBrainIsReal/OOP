#ifndef COMPLEX_H
#define COMPLEX_H
#pragma once
#include <iostream>
#include <istream>
using namespace std;

class complex
{
	double re, im;
	double value;
public:
	complex();
	complex(const int);
	complex(double realValue) : re(realValue), im(0.0) {}
	complex operator* (complex);
	complex operator+ (complex);
	complex operator- (complex);
	complex operator-=(const complex other);
	complex operator/=(const complex other);
	bool operator== (complex);
	bool operator!=(double other) const;
	
	friend ostream& operator <<(ostream&, complex);
	friend istream& operator >>(istream&, complex&);

};
#endif // !COMPLEX_H

