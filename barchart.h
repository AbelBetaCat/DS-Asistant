#ifndef BARCHART_H
#define BARCHART_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class BarChart;
}

class BarChart : public QWidget
{
    Q_OBJECT

public:
    explicit BarChart(QWidget *parent = 0);
    ~BarChart();

    void setupDemo(int DemoIndex);
    void setupBarChartDemo(QCustomPlot *customPlot, QString s1, QString s2, double maxY);

signals:
    void display(int number);

private slots:
    void on_returnMenuButton_clicked();

private:
    Ui::BarChart *ui;
    QString demoName;
};

#endif // ONE_H
