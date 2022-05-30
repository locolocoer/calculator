#include "complex.h"
#include<iostream>
#include"math.h"
using namespace std;

Complex::Complex(double a, double b) {
    real = a;
    img = b;
}

double Complex::getImg()
{
    return this->img;
}

double Complex::getReal()
{
    return this->real;
}

void Complex::Display() {
    cout << real << "+"<< img << "i" << endl;
}

Complex Complex::operator+(Complex b) {
    Complex temp;
    temp.real = this->real + b.real;
    temp.img = this->img + b.img;
    return temp;
}

Complex Complex::operator+(double b) {
    Complex temp;
    temp.real = this->real + b;
    temp.img = this->img;
    return temp;
}

Complex Complex::operator-(Complex b) {
    Complex temp;
    temp.real = this->real - b.real;
    temp.img = this->real - b.real;
    return temp;
}

Complex Complex::operator-(double b) {
    Complex temp;
    temp.real = this->real - b;
    temp.img = this->img;
    return temp;
}

Complex Complex::operator*(Complex b) {
    Complex temp;
    temp.real = this->real * b.real-this->img*b.img;
    temp.img = this->img * b.real+this->real*b.img;
    return temp;
}

Complex Complex::operator*(double b) {
    Complex temp;
    temp.real = this->real*b;
    temp.img = this->img*b;
    return temp;
}
Complex Complex::operator/(double b) {
    Complex temp;
    temp.real = this->real / b;
    temp.img = this->img / b;
    return temp;
}

QString Complex::toString()
{
    QString temp;
    temp.append(QString::number(real));
    if(abs(img)<0.000001){
        return temp;
    }else if(img<0){
        temp.append(QString::number(img));
        temp.append('j');
        return temp;
    }else{
        temp.append('+');
        temp.append(QString::number(img));
        temp.append('j');
        return temp;
    }
}
Complex Complex::operator/(Complex b) {
    Complex temp;
    double t;
    t = 1 / (b.real * b.real + b.img * b.img);
    temp.real = (this->real * b.real + this->img * b.img) * t;
    temp.img = (this->img * b.real - this->real * b.img) * t;
    return temp;
}

Complex operator/(double a, Complex b) {
    Complex temp;
    double t;
    t = 1 / (b.real * b.real + b.img * b.img);
    temp.real = a * b.real * t;
    temp.img = -a * b.img * t;
    return temp;
}

Complex operator+(double a, Complex b)
{
    Complex temp;
    temp.real=a+b.real;
    temp.img=b.img;
    return temp;
}

Complex operator-(double a, Complex b)
{
    Complex temp;
    temp.real=a-b.real;
    temp.img=-b.img;
    return temp;
}

Complex operator*(double a, Complex b)
{
    Complex temp;
    temp.real=a*b.real;
    temp.img=a*b.img;
    return temp;
}
