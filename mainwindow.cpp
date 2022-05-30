#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include"complexform.h"
#include<QPalette>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette pal = qApp->palette();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //qDebug()<<ui->expLine;
    QString exp = ui->expLine->text();
    cal.get_infix(exp);
    double i = cal.cal_inf();
    if (cal.ill_id!=0){
        QMessageBox::information(this,"error","输入有误");
    }else{
    ui->lineEdit->setText(QString::number(i));
    }
}

void MainWindow::on_btn7_clicked()
{
    QString temp=ui->expLine->text().append('7');
    ui->expLine->setText(temp);
}

void MainWindow::on_btn8_clicked()
{
    QString temp=ui->expLine->text().append('8');
    ui->expLine->setText(temp);
}

void MainWindow::on_btn9_clicked()
{
    QString temp=ui->expLine->text().append('9');
    ui->expLine->setText(temp);
}

void MainWindow::on_btnPlus_clicked()
{
    QString temp=ui->expLine->text().append('+');
    ui->expLine->setText(temp);
}

void MainWindow::on_btnSub_clicked()
{
    QString temp=ui->expLine->text().append('-');
    ui->expLine->setText(temp);
}

void MainWindow::on_btn4_clicked()
{
    QString temp=ui->expLine->text().append('4');
    ui->expLine->setText(temp);
}

void MainWindow::on_btn5_clicked()
{
    QString temp=ui->expLine->text().append('5');
    ui->expLine->setText(temp);
}

void MainWindow::on_btn6_clicked()
{
    QString temp=ui->expLine->text().append('6');
    ui->expLine->setText(temp);
}

void MainWindow::on_btnTimes_clicked()
{
    QString temp=ui->expLine->text().append('*');
    ui->expLine->setText(temp);
}

void MainWindow::on_btnDiv_clicked()
{
    QString temp=ui->expLine->text().append('/');
    ui->expLine->setText(temp);
}

void MainWindow::on_btn1_clicked()
{
    QString temp=ui->expLine->text().append('1');
    ui->expLine->setText(temp);
}

void MainWindow::on_btn2_clicked()
{
    QString temp=ui->expLine->text().append('2');
    ui->expLine->setText(temp);
}

void MainWindow::on_btn3_clicked()
{
    QString temp=ui->expLine->text().append('3');
    ui->expLine->setText(temp);
}

void MainWindow::on_btnLeft_clicked()
{
    QString temp=ui->expLine->text().append('(');
    ui->expLine->setText(temp);
}

void MainWindow::on_btnRight_clicked()
{
    QString temp=ui->expLine->text().append(')');
    ui->expLine->setText(temp);
}

void MainWindow::on_btn0_clicked()
{
    QString temp=ui->expLine->text().append('0');
    ui->expLine->setText(temp);
}

void MainWindow::on_btndot_clicked()
{
    QString temp=ui->expLine->text().append('.');
    ui->expLine->setText(temp);
}

void MainWindow::on_btnRight_2_clicked()
{
    QString temp=ui->expLine->text();
    temp.chop(1);
    ui->expLine->setText(temp);
}

void MainWindow::on_btnMoveBack_clicked()
{
    QString exp=cal.get_next_me();
    ui->expLine->setText(exp);
}

void MainWindow::on_btnMoveBack_2_clicked()
{
    QString exp=cal.get_forwd_me();
    ui->expLine->setText(exp);
}


void MainWindow::on_btnComplex_clicked()
{
    emit cal_com();
}

void MainWindow::on_btnGraph_clicked()
{
    emit cal_graph();
}
