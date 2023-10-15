#include "Trational.h"


int rat::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

rat::rat() : numerator(0), denominator(1) {}
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
rat::rat(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        std::cerr << "err: denomenator = 0" << std::endl;
        denominator = 1;
    }
    int commonFactor = gcd(numerator, denominator);
    numerator /= commonFactor;
    denominator /= commonFactor;
}
rat::rat(int num) : numerator(num), denominator(1) {}//rat numberwweww=0;

// Конструктор из double
rat::rat(double value) {
    int sign = (value < 0) ? -1 : 1;
    value = std::abs(value);
    double epsilon = 1.0e-6; // Точность для округления

    int wholePart = static_cast<int>(value);
    double fractionalPart = value - wholePart;

    int gcdValue = gcd(static_cast<int>(fractionalPart / epsilon), static_cast<int>(1.0 / epsilon));
    numerator = sign * (wholePart * gcdValue + static_cast<int>(fractionalPart / epsilon));
    denominator = gcdValue;
}
// Метод для получения числителя
int rat::getNumerator() {
    return numerator;
}

// Метод для получения знаменателя
int rat::getDenominator() {
    return denominator;
}

// Оператор сложения
rat rat::operator+(const rat& other) {
    int newNumerator = numerator * other.denominator + other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    return rat(newNumerator, newDenominator);
}

// Оператор вычитания
rat rat::operator-(const rat& other) {
    int newNumerator = numerator * other.denominator - other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    return rat(newNumerator, newDenominator);
}

// Оператор умножения
rat rat::operator*(const rat& other) {
    int newNumerator = numerator * other.numerator;
    int newDenominator = denominator * other.denominator;
    return rat(newNumerator, newDenominator);
}

// Оператор деления
rat rat::operator/(const rat& other) {
    if (other.numerator == 0) {
        std::cerr << "Ошибка: Деление на ноль." << std::endl;
        return rat(0, 0);
    }
    int newNumerator = numerator * other.denominator;
    int newDenominator = denominator * other.numerator;
    return rat(newNumerator, newDenominator);
}


rat& rat::operator+=(const rat& other) {
    int newNumerator = numerator * other.denominator + other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    int commonFactor = gcd(newNumerator, newDenominator);
    numerator = newNumerator / commonFactor;
    denominator = newDenominator / commonFactor;
    return *this;
}

rat& rat::operator-=(const rat& other) {
    int newNumerator = numerator * other.denominator - other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    int commonFactor = gcd(newNumerator, newDenominator);
    numerator = newNumerator / commonFactor;
    denominator = newDenominator / commonFactor;
    return *this;
}

rat& rat::operator*=(const rat& other) {
    int newNumerator = numerator * other.numerator;
    int newDenominator = denominator * other.denominator;
    int commonFactor = gcd(newNumerator, newDenominator);
    numerator = newNumerator / commonFactor;
    denominator = newDenominator / commonFactor;
    return *this;
}

rat& rat::operator/=(const rat& other) {
    if (other.numerator == 0) {
        std::cerr << "Ошибка: Деление на ноль." << std::endl;
        return *this;
    }
    int newNumerator = numerator * other.denominator;
    int newDenominator = denominator * other.numerator;
    int commonFactor = gcd(newNumerator, newDenominator);
    numerator = newNumerator / commonFactor;
    denominator = newDenominator / commonFactor;
    return *this;
}

// Оператор равенства
bool rat::operator==(const rat& other) {
    return numerator == other.numerator && denominator == other.denominator;
}

// Оператор неравенства
bool rat::operator!=(const rat& other) {
    return !(*this == other);
}

// Оператор "меньше чем"
bool rat::operator<(const rat& other) {
    return numerator * other.denominator < other.numerator* denominator;
}

// Оператор "больше чем"
bool rat::operator>(const rat& other) {
    return numerator * other.denominator > other.numerator * denominator;
}

// Оператор "меньше или равно"
bool rat::operator<=(const rat& other) {
    return numerator * other.denominator <= other.numerator * denominator;
}

// Оператор "больше или равно"
bool rat::operator>=(const rat& other) {
    return numerator * other.denominator >= other.numerator * denominator;
}

// Метод для вывода дроби
void rat::print() {
    std::cout << numerator << "/" << denominator;
}
std::istream& operator>>(std::istream& in, rat& rat) {
    char slash; // Для чтения символа '/'
    in >> rat.numerator >> slash >> rat.denominator;
    int commonFactor = rat.gcd(rat.numerator, rat.denominator);
    rat.numerator /= commonFactor;
    rat.denominator /= commonFactor;
    return in;
}

// Перегруженный оператор вывода
std::ostream& operator<<(std::ostream& out, const rat& rat) {
    out << rat.numerator;
    if (rat.denominator != 1) {
        out << '/' << rat.denominator;
    }
    return out;
}