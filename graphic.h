#ifndef GRAPHIC_H
#define GRAPHIC_H
#define PI 3.1415926
#include <math.h>

class graphic{
public:
    virtual bool is_illegal()=0;
    virtual void calculate()=0;
    virtual void get(double& arg1,double &arg2)=0;
    virtual ~graphic();
};

class graphic2D:public graphic {
protected:
    double area;
    double perimeter;
public:
    virtual void calculate();
    virtual void get(double& arg1,double &arg2);
    virtual void cal_area() = 0;
    virtual void cal_perimeter() = 0;
    virtual bool is_illegal();
    double get_area();
    double get_perimeter();
    graphic2D();
    virtual ~graphic2D();
};

class circle :public graphic2D {
private:
    double r;
public:
    virtual void cal_area();
    virtual void cal_perimeter();
    virtual bool is_illegal();
    circle();
    void set_size(double R);
    virtual ~circle();
};

class triangle :public graphic2D {
private:
    double a, b, c;
public:
    virtual bool is_illegal();
    virtual void cal_area();
    virtual void cal_perimeter();
    triangle();
    void  set_size(double a,double b,double c);
    virtual ~triangle();
};

class rectangle :public graphic2D {
private:
    double w, l;//w即width,l即length
public:
    virtual bool is_illegal();
    virtual void cal_area();
    virtual void cal_perimeter();
    rectangle();
    void set_size(double w, double l);
    virtual ~rectangle();
};

class graphic3D:public graphic {
protected:
    double area;
    double volume;
public:
    virtual void calculate();
    virtual void get(double& arg1,double &arg2);
    virtual bool is_illegal();
    virtual void cal_area() = 0;
    virtual void cal_volume() = 0;
    double get_area();
    double get_perimeter();
    double get_volume();
    graphic3D();
    virtual ~graphic3D();
};

class sphere :public graphic3D {
private:
    double R;
public:
    virtual bool is_illegal();
    virtual void cal_area();
    virtual void cal_volume();
    sphere();
    void set_size(double r);
    virtual ~sphere();
};

class cubic :public graphic3D {
private:
    double w, l, h;
public:
    virtual bool is_illegal();
    virtual void cal_area();
    virtual void cal_volume();
    cubic();
    void set_size(double w, double l, double h);
    virtual ~cubic();
};

class cylinder :public graphic3D {
private:
    double R;
    double h;
public:
    virtual bool is_illegal();
    virtual void cal_area();
    virtual void cal_volume();
    cylinder();
    void set_size(double r,double h);
    virtual ~cylinder();
};
#endif //!GRAPHIC_H
