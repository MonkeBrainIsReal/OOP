#include <iostream>

class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    // Конструкторы
    Rational() : numerator(0), denominator(1) {}
    Rational(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            std::cerr << "err: denomenator = 0" << std::endl;
            denominator = 1;
        }
        int commonFactor = gcd(numerator, denominator);
        numerator /= commonFactor;
        denominator /= commonFactor;
    }
    Rational(int num) : numerator(num), denominator(1) {}

    // Конструктор из double
    Rational(double value) {
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
    int getNumerator() const {
        return numerator;
    }

    // Метод для получения знаменателя
    int getDenominator() const {
        return denominator;
    }

    // Оператор сложения
    Rational operator+(const Rational& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Rational(newNumerator, newDenominator);
    }

    // Оператор вычитания
    Rational operator-(const Rational& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Rational(newNumerator, newDenominator);
    }

    // Оператор умножения
    Rational operator*(const Rational& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Rational(newNumerator, newDenominator);
    }

    // Оператор деления
    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            std::cerr << "Ошибка: Деление на ноль." << std::endl;
            return Rational();
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Rational(newNumerator, newDenominator);
    }


    Rational& operator+=(const Rational& other) {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        int commonFactor = gcd(newNumerator, newDenominator);
        numerator = newNumerator / commonFactor;
        denominator = newDenominator / commonFactor;
        return *this;
    }

    Rational& operator-=(const Rational& other) {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        int commonFactor = gcd(newNumerator, newDenominator);
        numerator = newNumerator / commonFactor;
        denominator = newDenominator / commonFactor;
        return *this;
    }

    Rational& operator*=(const Rational& other) {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        int commonFactor = gcd(newNumerator, newDenominator);
        numerator = newNumerator / commonFactor;
        denominator = newDenominator / commonFactor;
        return *this;
    }

    Rational& operator/=(const Rational& other) {
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
    bool operator==(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    // Оператор неравенства
    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    // Оператор "меньше чем"
    bool operator<(const Rational& other) const {
        return numerator * other.denominator < other.numerator* denominator;
    }

    // Оператор "больше чем"
    bool operator>(const Rational& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    // Оператор "меньше или равно"
    bool operator<=(const Rational& other) const {
        return numerator * other.denominator <= other.numerator * denominator;
    }

    // Оператор "больше или равно"
    bool operator>=(const Rational& other) const {
        return numerator * other.denominator >= other.numerator * denominator;
    }

    // Метод для вывода дроби
    void print() const {
        std::cout << numerator << "/" << denominator;
    }

    friend std::istream& operator>>(std::istream& in, Rational& rational) {
        char slash; // Для чтения символа '/'
        in >> rational.numerator >> slash >> rational.denominator;
        int commonFactor = rational.gcd(rational.numerator, rational.denominator);
        rational.numerator /= commonFactor;
        rational.denominator /= commonFactor;
        return in;
    }

    // Перегруженный оператор вывода
    friend std::ostream& operator<<(std::ostream& out, const Rational& rational) {
        out << rational.numerator;
        if (rational.denominator != 1) {
            out << '/' << rational.denominator;
        }
        return out;
    }

};
