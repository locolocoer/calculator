#include "graphic.h"

void circle::cal_area()
{
    area=PI*r*r;
}

void circle::cal_perimeter()
{
    perimeter = 2 * PI * r;
}

bool circle::is_illegal()
{
    if (r >= 0) {
        return true;
    }
    else {
        return false;
    }
}

circle::circle()
{
    r = 0;
}

void circle::set_size(double R)
{
    r = R;
}

circle::~circle()
{

}

void graphic2D::calculate()
{
    cal_area();
    cal_perimeter();
}

void graphic2D::get(double &arg1, double &arg2)
{
    arg1=get_area();
    arg2=get_perimeter();
}

bool graphic2D::is_illegal()
{
    return true;
}

double graphic2D::get_area()
{
    return area;
}

double graphic2D::get_perimeter()
{
    return perimeter;
}

graphic2D::graphic2D()
{
    area = 0;
    perimeter = 0;
}

graphic2D::~graphic2D()
{

}

bool triangle::is_illegal()
{
    {
        if ((a + b > c) && (a + c > b) && (b + c > a) && a>0 && b>0 && c>0) {
            return true;
        }
        else {
            return false;
        }
    }
}

void triangle::cal_area()
{
    double p = (a + b + c) / 2;
    area=sqrt(p * (p - a) * (p - b) * (p - c));
}

void triangle::cal_perimeter()
{
    perimeter = a + b + c;
}

triangle::triangle()
{
    a = 0;
    b = 0;
    c = 0;
}

void triangle::set_size(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

triangle::~triangle()
{

}

bool rectangle::is_illegal()
{
    if (w > 0 && l > 0) {
        return true;
    }
    else {
        return false;
    }
}

void rectangle::cal_area()
{
    area = w * l;
}

void rectangle::cal_perimeter()
{
    perimeter = 2 * (w + l);
}

rectangle::rectangle()
{
    w = 0;
    l = 0;
}

void rectangle::set_size(double w, double l)
{
    this->w = w;
    this->l = l;
}

rectangle::~rectangle()
{

}

void graphic3D::calculate()
{
    cal_area();
    cal_volume();
}

void graphic3D::get(double &arg1, double &arg2)
{
    arg1=get_area();
    arg2=get_volume();
}

bool graphic3D::is_illegal()
{
    return true;
}

double graphic3D::get_area()
{
    return area;
}

double graphic3D::get_volume()
{
    return volume;
}

graphic3D::graphic3D()
{
    area = 0;
    volume = 0;
}

graphic3D::~graphic3D()
{

}

bool sphere::is_illegal()
{
    if (R >= 0) {
        return true;
    }
    else {
        return false;
    }
}

void sphere::cal_area()
{
    area = 4 * PI * R * R;
}

void sphere::cal_volume()
{
    volume = 4.0 / 3.0 * PI * pow(R, 3);
}

sphere::sphere()
{
    R = 0;
}

void sphere::set_size(double r)
{
    R = r;
}

sphere::~sphere()
{

}

bool cubic::is_illegal()
{
    if (w > 0 && l > 0 && h > 0) {
        return true;
    }
    else {
        return false;
    }
}

void cubic::cal_area()
{
    area = 2 * (w * l + w * h + l * h);
}

void cubic::cal_volume()
{
    volume = w * l * h;
}

cubic::cubic()
{
    w = 0;
    l = 0;
    h = 0;
}

void cubic::set_size(double w, double l, double h)
{
    this->w = w;
    this->l = l;
    this->h = h;
}

cubic::~cubic()
{

}

bool cylinder::is_illegal()
{
    if (R > 0 && h > 0) {
        return true;
    }
    else {
        return false;
    }
}

void cylinder::cal_area()
{
    area = 2 * PI * pow(R, 2) + 2 * PI * R * h;
}

void cylinder::cal_volume()
{
    volume = PI * pow(R, 2) * h;
}

cylinder::cylinder()
{
    R = 0;
    h = 0;
}

void cylinder::set_size(double r, double h)
{
    this->R = r;
    this->h = h;
}

cylinder::~cylinder()
{

}

graphic::~graphic()
{

}
