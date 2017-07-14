#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedLayout>
#include <QTimer>
#include "qcustomplot.h" // the header file of QCustomPlot. Don't forget to add it to your project, if you use an IDE, so it gets compiled.

class Menu;
class Scatter;
class BarChart;
class QStackedLayout;
class QVBoxLayout;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Menu *menu;
    Scatter *scatter;
    BarChart *barchart;
    QStackedLayout *stackLayout;
    QVBoxLayout *mainLayout;
    Ui::Widget *ui;
};

#endif // WIDGET_H
