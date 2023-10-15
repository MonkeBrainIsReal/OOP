#pragma once
#ifndef rational_H
#define rational_H
#include "cmath"
#include <iostream>
#include <istream>
using namespace std;
//#include <QLineEdit>

class Rational {
private:
    
public:
    int numerator;
    int denominator;
    Rational();

    Rational(int num , int denum);

    Rational(int num, int denom) : numerator(num), denominator(denom) {};

    Rational(int num) : numerator(num), denominator(1) {};

    Rational(double value);

    int getNumerator()const;

    int getDenominator()const;
    
    Rational operator+(const Rational& other) const;

    Rational operator-(const Rational& other) const;

    Rational operator*(const Rational& other) const;

    Rational operator/(const Rational& other) const;

    Rational& operator+=(const Rational& other);

    Rational& operator-=(const Rational& other);

    Rational& operator*=(const Rational& other);

    Rational& operator/=(const Rational& other);

    bool operator==(const Rational& other) const;

    bool operator!=(const Rational& other) const;

    bool operator<(const Rational& other) const;

    bool operator>(const Rational& other) const;

    bool operator<=(const Rational& other) const;

    bool operator>=(const Rational& other) const;

    void print() const;

    int gcd(int a, int b);

    friend std::istream& operator>>(std::istream& in, Rational& rational);

    friend std::ostream& operator<<(std::ostream& out, const Rational& rational);
    //friend QString& operator <<(QString&, rational&);
    //friend QString& operator >>(QString&, rational&);


};


#endif // !rational_H
