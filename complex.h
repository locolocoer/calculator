#ifndef COMPLEX_H
#define COMPLEX_H
#include<QString>

class Complex
{
private:
    double real;
    double img;
public:
    Complex(double a = 0, double b = 0);
    double getImg();
    double getReal();
    void Display();
    Complex operator+(Complex b);
    Complex operator+(double b);
    Complex operator-(Complex b);
    Complex operator-(double b);
    Complex operator*(Complex b);
    Complex operator*(double b);
    friend Complex operator+(double, Complex);
    friend Complex operator-(double, Complex);
    friend Complex operator*(double, Complex);
    friend Complex operator/(double, Complex);
    Complex operator/(Complex b);
    Complex operator/(double b);
    QString toString();
};
Complex operator+(double a, Complex b);
Complex operator-(double a, Complex b);
Complex operator*(double a, Complex b);
Complex operator/(double a, Complex b);

#endif // COMPLEX_H
