#include "complexform.h"
#include "ui_complexform.h"
#include "complex.h"
#include<QDebug>
#include<QMessageBox>
ComplexForm::ComplexForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComplexForm)
{
    ui->setupUi(this);
}

ComplexForm::~ComplexForm()
{
    delete ui;
}

void ComplexForm::cal_two_num(double a, Complex b, QString opStr)
{
    Complex res;
    if (opStr=="*"){
        res=a*b;
    }
    else if (opStr=="-"){
        res=a-b;
    }
    else if (opStr=="/"){
        res=a/b;
    }
    else if (opStr=="+"){
        res=a+b;
    }
    else{
        QMessageBox::information(this,"tips","运算符不正确");
        return;
    }
    QString str="("+QString::number(a)+")"+opStr+"("+b.toString()+")";
    ui->expEdit->setText(str);
    str=res.toString();
    ui->resEdit->setText(str);
}

void ComplexForm::cal_two_num(Complex a, double b, QString opStr)
{
    Complex res;
    if (opStr=="*"){
        res=a*b;
    }
    else if (opStr=="-"){
        res=a-b;
    }
    else if (opStr=="/"){
        res=a/b;
    }
    else if (opStr=="+"){
        res=a+b;
    }
    else{
        QMessageBox::information(this,"tips","运算符不正确");
        return;
    }
    QString str="("+a.toString()+")"+opStr+"("+QString::number(b)+")";
    ui->expEdit->setText(str);
    str=res.toString();
    ui->resEdit->setText(str);
}

void ComplexForm::cal_two_num(double a, double b, QString opStr)
{
    double res;
    if (opStr=="*"){
        res=a*b;
    }
    else if (opStr=="-"){
        res=a-b;
    }
    else if (opStr=="/"){
        res=a/b;
    }
    else if (opStr=="+"){
        res=a+b;
    }
    else{
        QMessageBox::information(this,"tips","运算符不正确");
        return;
    }
    QString str=QString::number(a)+opStr+QString::number(b);
    ui->expEdit->setText(str);
    str = QString::number(res);
    ui->resEdit->setText(str);
}



void ComplexForm::showOut()
{
    this->show();
}

void ComplexForm::on_pushButton_clicked()
{
    bool ok=1;
    if((ui->img1->text()=="")||(ui->img2->text()=="")){
        qDebug()<<1;
        if ((ui->img1->text()=="")&&(ui->img2->text()=="")){
            double a=ui->real1->text().toDouble(&ok);
            double b=ui->real2->text().toDouble(&ok);
            QString opStr = ui->opEdit->text();
            if(ok){
                cal_two_num(a,b,opStr);
            }else{
                QMessageBox::information(this,"tips","请输入正确的数字");
            }
        }
        else if (ui->img1->text()==""){
            double a=ui->real1->text().toDouble(&ok);
            double r2=ui->real2->text().toDouble(&ok);
            double i2=ui->img2->text().toDouble(&ok);
            Complex b(r2,i2);
            QString opStr = ui->opEdit->text();
            if(ok){
                cal_two_num(a,b,opStr);
            }else{
                QMessageBox::information(this,"tips","请输入正确的数字");
            }
        }else{
                    double b=ui->real2->text().toDouble(&ok);
                    double r1=ui->real1->text().toDouble(&ok);
                    double i1=ui->img1->text().toDouble(&ok);
                    Complex a(r1,i1);
                    QString opStr = ui->opEdit->text();
                    if(ok){
                        cal_two_num(a,b,opStr);
                    }else{
                        QMessageBox::information(this,"tips","请输入正确的数字");
                    }
                }


    }else{
        double r1=ui->real1->text().toDouble(&ok);
        double i1=ui->img1->text().toDouble(&ok);
        double r2=ui->real2->text().toDouble(&ok);
        double i2=ui->img2->text().toDouble(&ok);
        Complex a(r1,i1);
        Complex b(r2,i2);
        QString opStr = ui->opEdit->text();
        if(ok){
            cal_two_num(a,b,opStr);
        }else{
            QMessageBox::information(this,"tips","请输入正确的数字");
        }
    }
}

void ComplexForm::cal_two_num(Complex a, Complex b,QString opStr)
{
    Complex res;
    if (opStr=="*"){
        res=a*b;
    }
    else if (opStr=="-"){
        res=a-b;
    }
    else if (opStr=="/"){
        res=a/b;
    }
    else if (opStr=="+"){
        res=a+b;
    }
    else{
        QMessageBox::information(this,"tips","运算符不正确");
        return;
    }
    QString str="("+a.toString()+")"+opStr+"("+b.toString()+")";
    ui->expEdit->setText(str);
    str=res.toString();
    ui->resEdit->setText(str);
}
