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
	
	complex(const int&);
	complex(double realValue) : re(realValue), im(0.0) {}
	complex operator* (complex);
	complex operator+ (complex);
	complex operator- (complex);
	bool operator== (complex);

	complex operator-=(const complex& other) {
		re -= other.re;
		im -= other.im;
		return *this;
	}
	complex operator/=(const complex& other) {
		double denominator = other.re * other.re + other.im * other.im;
		double newRe = (re * other.re + im * other.im) / denominator;
		double newIm = (im * other.re - re * other.im) / denominator;

		re = newRe;
		im = newIm;

		return *this;
	}
	bool operator!=(double other) const 
	{
		return value != other;
	}
	double toDouble() const {
		return re; // ¬озвращает действительную часть как double
	}
	
	friend ostream& operator <<(ostream&, complex);
	friend istream& operator >>(istream&, complex&);
};
#endif // !COMPLEX_H

