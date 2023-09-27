#ifndef COMPLEX_H
#define COMPLEX_H
#pragma once
#include <iostream>
#include <istream>
using namespace std;

class complex
{
	
public:
	double re = 0;
	double im=0;
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
	
private:
	
};
#endif // !COMPLEX_H

