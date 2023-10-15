#pragma once
#ifndef rational_H
#define rational_H
#include "cmath"
#include <iostream>
#include <istream>
using namespace std;
//#include <QLineEdit>

class rational {
private:
    
public:
    int numerator;
    int denominator;
    rational();

    rational(double value);

    rational(int num, int denom);

    int getNumerator();

    int getDenominator();

    void print() ;

    rational operator+(const rational& other);

    rational operator-(const rational& other);

    rational operator*(const rational& other);

    rational operator/(const rational& other);

    rational& operator+=(const rational& other);

    rational& operator-=(const rational& other);

    rational& operator*=(const rational& other);

    rational& operator/=(const rational& other);

    bool operator==(const rational& other);

    bool operator!=(const rational& other);

    rational& operator=(const rational& other);

    rational pow(int exponent);

    int gcd(int a, int b);

    friend ostream& operator<<(ostream&, rational&);

    friend istream& operator>>(istream&, rational&);
    //friend QString& operator <<(QString&, rational&);
    //friend QString& operator >>(QString&, rational&);


};


#endif // !rational_H
