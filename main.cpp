#include "mainwindow.h"
#include "complexform.h"
#include <QApplication>
#include"graphform.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ComplexForm c;
    QObject::connect(&w,SIGNAL(cal_com()),&c,SLOT(showOut()));
    GraphForm g;
    QObject::connect(&w,SIGNAL(cal_graph()),&g,SLOT(showOut()));

    return a.exec();
}
