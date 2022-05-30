#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"calculator.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void cal_com();
    void cal_graph();
private slots:
    void on_pushButton_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_btnPlus_clicked();

    void on_btnSub_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btnTimes_clicked();

    void on_btnDiv_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btnLeft_clicked();

    void on_btnRight_clicked();

    void on_btn0_clicked();

    void on_btndot_clicked();

    void on_btnRight_2_clicked();

    void on_btnMoveBack_clicked();

    void on_btnMoveBack_2_clicked();

    void on_btnComplex_clicked();

    void on_btnGraph_clicked();

private:
    Calculator cal;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
