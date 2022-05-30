#ifndef GRAPHFORM_H
#define GRAPHFORM_H

#include <QWidget>
#include "graphic.h"
namespace Ui {
class GraphForm;
}

class GraphForm : public QWidget
{
    Q_OBJECT

public:
    explicit GraphForm(QWidget *parent = nullptr);
    ~GraphForm();
private slots:
    void showOut();
    void on_TwoOrThreeComb_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_calBtn_clicked();

private:
    Ui::GraphForm *ui;
    circle c;
    triangle t;
    rectangle r;
    sphere s;
    cylinder cd;
    cubic cb;
};

#endif // GRAPHFORM_H
