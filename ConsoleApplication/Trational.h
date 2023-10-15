#include <iostream>

class rat {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b);

public:
    // Конструкторы
    rat();
    rat(int num, int denom);
    rat(int num);

    // Конструктор из double
    rat(double value);
    // Метод для получения числителя
    int getNumerator();

    // Метод для получения знаменателя
    int getDenominator();

    // Оператор сложения
    rat operator+(const rat& other);

    // Оператор вычитания
    rat operator-(const rat& other);

    // Оператор умножения
    rat operator*(const rat& other);

    // Оператор деления
    rat operator/(const rat& other);


    rat& operator+=(const rat& other);

    rat& operator-=(const rat& other);

    rat& operator*=(const rat& other);

    rat& operator/=(const rat& other);

    // Оператор равенства
    bool operator==(const rat& other);

    // Оператор неравенства
    bool operator!=(const rat& other);

    // Оператор "меньше чем"
    bool operator<(const rat& other);

    // Оператор "больше чем"
    bool operator>(const rat& other);

    // Оператор "меньше или равно"
    bool operator<=(const rat& other);

    // Оператор "больше или равно"
    bool operator>=(const rat& other);

    // Метод для вывода дроби
    void print();

    friend std::istream& operator>>(std::istream& in, rat& rat);

    // Перегруженный оператор вывода
    friend std::ostream& operator<<(std::ostream& out, const rat& rat);

};
