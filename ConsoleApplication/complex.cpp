#include "complex.h"
complex::complex() {

}

complex::complex(const int value) : re(static_cast<double>(value)), im(0.0)
{

}

complex complex::operator* (complex c)
{
	complex t;
	t.re = re * c.re - im * c.im;
	t.im = re * c.im + im * c.re;
	return t;
}

complex complex::operator+ (complex c)
{
	complex t;
	t.re = re + c.re;
	t.im = c.im + im;
	return t;
}

complex complex::operator- (complex c)
{
	complex t;
	t.re = re - c.re;
	t.im = im - c.im;
	return t;
}

complex complex::operator-=(const complex other)
{
	re -= other.re;
	im -= other.im;
	return *this;
}

complex complex::operator/=(const complex other)
{
	double denominator = other.re * other.re + other.im * other.im;
	double newRe = (re * other.re + im * other.im) / denominator;
	double newIm = (im * other.re - re * other.im) / denominator;
	re = newRe;
	im = newIm;
	return *this;
}

bool complex::operator!=(complex other) 
{
	return (re != other.re) || (im != other.im);
}

bool complex::operator== (complex c)
{
	return (re == c.re) && (im == c.im);
}

ostream& operator <<(ostream& os, complex c)
{
	os << "(" << c.re << "+" << c.im << "i)";
	return os;
}

istream& operator >>(istream& is, complex& c)
{
	is >> c.re >> c.im;
	return is;
}