#include "Trational.h"
#include "cmath"
rational::rational() : numerator(0), denominator(1) {}

int rational::gcd(int a, int b)
{
while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
}
return a;
}

rational::rational(double value)
{
    int sign = (value < 0) ? -1 : 1;
    value = std::abs(value);
    double epsilon = 1.0e-6; // Точность для округления

    int wholePart = static_cast<int>(value);
    double fractionalPart = value - wholePart;

    int gcdValue = gcd(static_cast<int>(fractionalPart / epsilon), static_cast<int>(1.0 / epsilon));
    numerator = sign * (wholePart * gcdValue + static_cast<int>(fractionalPart / epsilon));
    denominator = gcdValue;
}


rational::rational(int num, int denom) : numerator(num), denominator(denom)
{
    if (denominator == 0)
    {
        std::cerr << "Ошибка: Знаменатель не может быть равен 0." << std::endl;
        denominator = 1;
    }
}

int rational::getNumerator()  {
    return numerator;
}

int rational::getDenominator()  {
    return denominator;
}

void rational::print()  {
    std::cout << numerator << "/" << denominator;
}

rational rational::operator+(const rational& other)  {
    int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
    int newDenominator = denominator * other.denominator;
    return rational(newNumerator, newDenominator);
}

rational rational::operator-(const rational& other)  {
    int newNumerator = (numerator * other.denominator) - (other.numerator * denominator);
    int newDenominator = denominator * other.denominator;
    return rational(newNumerator, newDenominator);
}

rational rational::operator*(const rational& other)  {
    int newNumerator = numerator * other.numerator;
    int newDenominator = denominator * other.denominator;
    return rational(newNumerator, newDenominator);
}

rational rational::operator/(const rational& other)  {
    if (other.numerator == 0) {
        std::cerr << "Ошибка: Деление на ноль." << std::endl;
        return rational();
    }
    int newNumerator = numerator * other.denominator;
    int newDenominator = denominator * other.numerator;
    return rational(newNumerator, newDenominator);
}

// Операторы с присваиванием
rational& rational::operator+=(const rational& other) {
    *this = *this + other;
    return *this;
}

rational& rational::operator-=(const rational& other) {
    *this = *this - other;
    return *this;
}

rational& rational::operator*=(const rational& other) {
    *this = *this * other;
    return *this;
}

rational& rational::operator/=(const rational& other) {
    *this = *this / other;
    return *this;
}

// Операторы сравнения
bool rational::operator==(const rational& other)  {
    return (numerator * other.denominator) == (other.numerator * denominator);
}

bool rational::operator!=(const rational& other)  {
    return !(*this == other);
}

rational& rational::operator=(const rational& other) {
    if (this == &other) {
        return *this; // Самоприсваивание, ничего делать не нужно
    }

    numerator = other.numerator;
    denominator = other.denominator;

    return *this;
}


ostream& operator<<(ostream& os, rational& c) 
{
        os << "(" << c.numerator << "/" << c.denominator << ")";
        return os;
}


istream& operator >>(istream& is, rational& c)
{
    is >> c.numerator >> c.denominator;
    return is;
}

//QString& operator <<(QString& s, rational& r)
//{
//    s+=QString().setNum(r.denominator);
//    s+="/";
//    s+=QString().setNum(r.numerator);
//    return s;
//}
