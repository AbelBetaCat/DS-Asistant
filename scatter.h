#ifndef SCATTER_H
#define SCATTER_H

#include <QWidget>
#include "qcustomplot.h"
#include <Eigen/Eigen>
#include <QStyleOption>
#include <QPainter>

using namespace Eigen;

typedef struct {
    int type;
    double a;
    double b;
    double c;
} Fitting;

namespace Ui {
class Scatter;
}

class Scatter : public QWidget
{
    Q_OBJECT

public:
    explicit Scatter(QWidget *parent = 0);
    ~Scatter();

    void setupDemo(int DemoIndex);
    void setupScatterDemo(QCustomPlot *customPlot, QVector<double> &xValues, QVector<double> &yValues, double maxX, double maxY);
    Fitting Scatter::curveFitting(QVector<double> &xValues, QVector<double> &yValues);

signals:
    void display(int number);

private slots:
    void on_returnMenuButton_clicked();

private:
    Ui::Scatter *ui;
    QString demoName;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // SCATTER_H
