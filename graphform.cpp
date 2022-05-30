#include "graphform.h"
#include "ui_graphform.h"
#include "graphic.h"
#include <QMessageBox>
#include<QDebug>
GraphForm::GraphForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphForm)
{
    ui->setupUi(this);
    //QObject::connect(ui->TwoOrThreeComb,SIGNAL())
}

GraphForm::~GraphForm()
{
    delete ui;
}

void GraphForm::showOut()
{
    this->show();
}

void GraphForm::on_TwoOrThreeComb_activated(const QString &arg1)
{
    if (arg1=="二维图形"){
        ui->kindOfGraphComb->clear();
        ui->kindOfGraphComb->addItem("圆");
        ui->kindOfGraphComb->addItem("三角形");
        ui->kindOfGraphComb->addItem("矩形");
    }else if(arg1=="三维图形"){
        ui->kindOfGraphComb->clear();
        ui->kindOfGraphComb->addItem("球体");
        ui->kindOfGraphComb->addItem("长方体");
        ui->kindOfGraphComb->addItem("圆柱");
    }
}

void GraphForm::on_pushButton_clicked()
{
    if(ui->kindOfGraphComb->currentText()=="圆"){
        ui->label->setText("半径：");
        ui->label_2->clear();
        ui->label_3->clear();
        ui->arg1Line->show();
        ui->arg2Line->close();
        ui->arg3Line->close();
    }else if (ui->kindOfGraphComb->currentText()=="三角形") {
        ui->label->setText("边1：");
        ui->label_2->setText("边2：");
        ui->label_3->setText("边3：");
        ui->arg1Line->show();
        ui->arg2Line->show();
        ui->arg3Line->show();
    }else if(ui->kindOfGraphComb->currentText()=="矩形"){
        ui->label->setText("长：");
        ui->label_2->setText("宽：");
        ui->label_3->setText("");
        ui->arg1Line->show();
        ui->arg2Line->show();
        ui->arg3Line->close();
    }else if(ui->kindOfGraphComb->currentText()=="球体"){
        ui->label->setText("半径：");
        ui->label_2->setText("");
        ui->label_3->setText("");
        ui->arg1Line->show();
        ui->arg2Line->close();
        ui->arg3Line->close();
    }else if(ui->kindOfGraphComb->currentText()=="长方体"){
        ui->label->setText("长：");
        ui->label_2->setText("宽：");
        ui->label_3->setText("高：");
        ui->arg1Line->show();
        ui->arg2Line->show();
        ui->arg3Line->show();
    }else if(ui->kindOfGraphComb->currentText()=="圆柱"){
        ui->label->setText("半径：");
        ui->label_2->setText("高：");
        ui->label_3->setText("");
        ui->arg1Line->show();
        ui->arg2Line->show();
        ui->arg3Line->close();
    }else{};
    if(ui->TwoOrThreeComb->currentText()=="二维图形"){
        ui->label_5->setText("面积：");
        ui->label_6->setText("周长：");
    }else{
        ui->label_5->setText("面积：");
        ui->label_6->setText("体积：");
}
}

void GraphForm::on_calBtn_clicked()
{
    graphic *p;
    bool ok;
    if(ui->kindOfGraphComb->currentText()=="圆"){
        double arg1 = ui->arg1Line->text().toDouble(&ok);
        c.set_size(arg1);
        p=&c;
    }else if (ui->kindOfGraphComb->currentText()=="三角形") {
        double arg1=ui->arg1Line->text().toDouble(&ok);
        double arg2=ui->arg2Line->text().toDouble(&ok);
        double arg3=ui->arg3Line->text().toDouble(&ok);
        t.set_size(arg1,arg2,arg3);
        p=&t;
    }else if(ui->kindOfGraphComb->currentText()=="矩形"){
        double arg1=ui->arg1Line->text().toDouble(&ok);
        double arg2=ui->arg2Line->text().toDouble(&ok);
        r.set_size(arg1,arg2);
        p=&r;
    }else if(ui->kindOfGraphComb->currentText()=="球体"){
        double arg1 = ui->arg1Line->text().toDouble(&ok);
        s.set_size(arg1);
        p=&s;
    }else if(ui->kindOfGraphComb->currentText()=="长方体"){
        double arg1=ui->arg1Line->text().toDouble(&ok);
        double arg2=ui->arg2Line->text().toDouble(&ok);
        double arg3=ui->arg3Line->text().toDouble(&ok);
        cb.set_size(arg1,arg2,arg3);
        p=&cb;
    }else{
        double arg1=ui->arg1Line->text().toDouble(&ok);
        double arg2=ui->arg2Line->text().toDouble(&ok);
        cd.set_size(arg1,arg2);
        p=&cd;
    }
    qDebug()<<p->is_illegal();
    if(!p->is_illegal()||!ok){
        QMessageBox::information(this,"info","参数有误");
    }else{
        p->calculate();
        double arg1,arg2;
        p->get(arg1,arg2);
        ui->resArg1Line->setText(QString::number(arg1));
        ui->resArg2Line2->setText(QString::number(arg2));
    }
}
