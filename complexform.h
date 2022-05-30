#ifndef COMPLEXFORM_H
#define COMPLEXFORM_H

#include <QWidget>
#include"complex.h"
namespace Ui {
class ComplexForm;
}

class ComplexForm : public QWidget
{
    Q_OBJECT

public:
    explicit ComplexForm(QWidget *parent = nullptr);
    ~ComplexForm();
    void cal_two_num(double a,Complex b,QString opStr);
    void cal_two_num(Complex a,double b,QString opStr);
    void cal_two_num(double a,double b,QString opStr);
    void cal_two_num(Complex a,Complex b,QString opStr);

private:
    Ui::ComplexForm *ui;
private slots:
    void showOut();
    void on_pushButton_clicked();
};

#endif // COMPLEXFORM_H
