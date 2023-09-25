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
	t.im = c.im - im;
	return t;
}

complex complex::operator-=(const complex other)
{
	complex t;
	t.re -= other.re;
	t.im -= other.im;
	return t;
}

complex complex::operator/=(const complex other)
{
	complex t;
	
	double denominator = other.re * other.re + other.im * other.im;
	double newRe = (re * other.re + im * other.im) / denominator;
	double newIm = (im * other.re - re * other.im) / denominator;

	t.re = newRe;
	t.im = newIm;
	return t;
}

bool complex::operator!=(complex other) const 
{


	return ((other.im != im)&&(other.re != re));
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