#include <iostream>

class rat {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b);

public:
    // ������������
    rat();
    rat(int num, int denom);
    rat(int num);

    // ����������� �� double
    rat(double value);
    // ����� ��� ��������� ���������
    int getNumerator();

    // ����� ��� ��������� �����������
    int getDenominator();

    // �������� ��������
    rat operator+(const rat& other);

    // �������� ���������
    rat operator-(const rat& other);

    // �������� ���������
    rat operator*(const rat& other);

    // �������� �������
    rat operator/(const rat& other);


    rat& operator+=(const rat& other);

    rat& operator-=(const rat& other);

    rat& operator*=(const rat& other);

    rat& operator/=(const rat& other);

    // �������� ���������
    bool operator==(const rat& other);

    // �������� �����������
    bool operator!=(const rat& other);

    // �������� "������ ���"
    bool operator<(const rat& other);

    // �������� "������ ���"
    bool operator>(const rat& other);

    // �������� "������ ��� �����"
    bool operator<=(const rat& other);

    // �������� "������ ��� �����"
    bool operator>=(const rat& other);

    // ����� ��� ������ �����
    void print();

    friend std::istream& operator>>(std::istream& in, rat& rat);

    // ������������� �������� ������
    friend std::ostream& operator<<(std::ostream& out, const rat& rat);

};
