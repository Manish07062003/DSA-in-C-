#include <iostream>
#include <cstdlib>
using namespace std;
class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    Fraction add(const Fraction &f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * numerator + (y * f2.numerator);
        Fraction fNew(num, lcm);
        fNew.simplify();
        return fNew;
    }
    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }
    void print() const
    {
        cout << this->numerator << " / " << this->denominator << endl;
    }
    Fraction operator+(const Fraction &f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * numerator + (y * f2.numerator);
        Fraction fNew(num, lcm);
        fNew.simplify();
        return fNew;
    }
    bool operator==(const Fraction &f2) const
    {
        return (this->numerator == f2.numerator && this->denominator == f2.denominator);
    }
    Fraction operator*(const Fraction &f2) const
    {
        int num = this->numerator * f2.numerator;
        int den = this->denominator * f2.denominator;
        Fraction fnew(num, den);
        fnew.simplify();
        return fnew;
    }
    // pre increament
    Fraction &operator++()
    {
        this->numerator += this->denominator;
        simplify();
        return *this;
    }
    // post increament
    Fraction operator++(int)
    {
        Fraction fnew(this->numerator, this->denominator);
        this->numerator += this->denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }
    // short hand add operator
    Fraction &operator+=(const Fraction f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * numerator + (y * f2.numerator);
        numerator = num;
        denominator = lcm;
        simplify();
        return *this;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Fraction f1(3, 6);
    Fraction f2(3, 9);
    // addition
    cout << "Addition" << endl;
    Fraction f3 = f1.add(f2);
    f3.print();

    // addition operator
    cout << endl
         << "Addtion Operator" << endl;
    Fraction f4 = f1 + f2;
    f4.print();

    // equality operator
    cout << endl
         << "Equality Operator" << endl;
    if (f1 == f2)
    {
        cout << "F1 and F2 are equal" << endl;
    }
    else
    {
        cout << "F1 and F2 are not equal" << endl;
    }

    // pre increament
    cout << endl
         << "Pre Increament" << endl;
    Fraction f6 = ++(++f1);
    f6.print();

    // post increament
    cout << endl
         << "Post Increament" << endl;
    Fraction f7 = f1++;
    f7.print();

    // multiplication operator
    cout << endl
         << "Multiplication Operator" << endl;
    Fraction f8 = f1 * f2;
    f8.print();

    // short hand add operator
    cout << endl
         << "Short hand add operator" << endl;
    (f1 += f2) += f2;
    f1.print();
}