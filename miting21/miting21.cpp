#include "stdafx.h"
#include <iostream>
using namespace std;
class Root
{
public:
    virtual void getroot() = 0;
};
class Linear : public Root
{
private:
    double first;
    double second;
public:
    Linear(double f, double s) : first(f), second(s)
    {
    }
    void getroot()
    {
        double x3;
        x3 = (first && second) ? -second / first : 0;
        cout << x3 << endl;
    }

};
class Square : public Root
{
private:
    double a;
    double b;
    double c;
public:
    Square(double A, double B, double C) : a(A), b(B), c(C)
    {
    }
    void getroot()
    {
        double x1, x2, d;
        if (a == 0.0) {
            cout << "Not root equation !\n";
        }

        d = b * b - 4 * a * c;
        cout << "d=" << d << "\n";
        if (d > 0) {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            cout << x1 << x2 << endl;
        }
        else if (d == 0.0) {
            x1 = (-b / (2 * a)); x2 = x1;
            cout << x1;
        }
        else {
            cout << "equation roots not found\n";
        }
    }
};

int main()
{
    Linear line(5, -5);
    Square squa(2, -2, -4);
    line.getroot();
    squa.getroot();
    system("pause");
    return 0;
}