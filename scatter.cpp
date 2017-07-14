#include "scatter.h"
#include "ui_scatter.h"
#include <qmath.h>
#include <QVector>
#include <QPoint>

Scatter::Scatter(QWidget *parent) : QWidget(parent),
    ui(new Ui::Scatter)
{
    ui->setupUi(this);

    setFixedSize(1100, 700);

    setupDemo(1);
}

Scatter::~Scatter()
{
    delete ui;
}

void Scatter::on_returnMenuButton_clicked()
{
    emit display(0);
}

void Scatter::setupDemo(int demoIndex)
{
  qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
  QVector<double> xValues(200),yValues(200),newyValues(200);
  double maxX = xValues[0],maxY = yValues[0],newmaxY = yValues[0];
  for (int i = 0; i < xValues.size(); ++i)
  {
    xValues[i] = i+1;
    yValues[i] = 3.6*qLn(i+1)+34+rand()%5;
    maxX = (xValues[i] > maxX) ? xValues[i] : maxX;
    maxY = (yValues[i] > maxY) ? yValues[i] : maxY;
  }
  //拟合方案选优
  Fitting fitting = curveFitting(xValues, yValues);
  //根据拟合方程计算新的y值
  if(fitting.type == 1)
      for(int i = 0; i < xValues.size(); ++i)
      {
          newyValues[i] = fitting.a + fitting.b * xValues[i];
          newmaxY = (newyValues[i] > newmaxY) ? newyValues[i] : newmaxY;
      }
  else if(fitting.type == 2)
      for(int i = 0; i < xValues.size(); ++i)
      {
          newyValues[i] = fitting.a + fitting.b * qLn(xValues[i]);
          newmaxY = (newyValues[i] > newmaxY) ? newyValues[i] : newmaxY;
      }
  else
      for(int i = 0; i < xValues.size(); ++i)
      {
          newyValues[i] = fitting.a + fitting.b * xValues[i] + fitting.c * qPow(xValues[i], 2);
          newmaxY = (newyValues[i] > newmaxY) ? newyValues[i] : newmaxY;
      }
  //绘制曲线
  setupScatterDemo(ui->customPlot, xValues, yValues, maxX, maxY);
  setupScatterDemo(ui->customPlot, xValues, newyValues, maxX, newmaxY);
  setWindowTitle("QCustomPlot: "+demoName);
  ui->customPlot->replot();
}

//散点折线图
void Scatter::setupScatterDemo(QCustomPlot *customPlot, QVector<double> &xValues, QVector<double> &yValues, double maxX, double maxY)
{
  demoName = "Data Source";
  QLinearGradient gradient(0, 0, 0, 400);
  gradient.setColorAt(0, QColor(90, 90, 90));
  gradient.setColorAt(0.38, QColor(105, 105, 105));
  gradient.setColorAt(1, QColor(70, 70, 70));
  customPlot->setBackground(QBrush(gradient));
  //生成图表，插入散点
  QCPGraph *graph = customPlot->addGraph();
  graph->setPen(QPen(QColor(255, 99, 71)));
  //graph->setBrush(QColor(250, 170, 20));
  graph->setData(xValues, yValues);
  //设置横纵坐标
  customPlot->xAxis->setLabel("x");
  customPlot->xAxis->setLabelColor(Qt::white);
  customPlot->yAxis->setLabel("y");
  customPlot->yAxis->setLabelColor(Qt::white);
  //设置坐标范围
  customPlot->xAxis->setRange(0, maxX * 1.1);
  //设置坐标轴颜色
  customPlot->xAxis->setBasePen(QPen(Qt::white));
  customPlot->xAxis->setTickPen(QPen(Qt::white));
  customPlot->xAxis->setTickLabelColor(Qt::white);
  //同x轴
  customPlot->yAxis->setRange(0, maxY * 1.1);
  customPlot->yAxis->setBasePen(QPen(Qt::white));
  customPlot->yAxis->setTickPen(QPen(Qt::white));
  customPlot->yAxis->setTickLabelColor(Qt::white);

  //设置可移动
  customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

//1为线性，2为对数，3为二次
//线性：a+bx=y
//对数：a+blnx=y
//二次：a+bx+cx^2=y
Fitting Scatter::curveFitting(QVector<double> &xValues, QVector<double> &yValues)
{
    Fitting fitting;
    //计算x，y各种组合的和
    double x = 0, y = 0, xx = 0, xy = 0, yy = 0, xxx = 0, xxy = 0, xxxx = 0, lnx = 0, lnxx = 0, lnxy = 0, lnyy = 0;
    //三种拟合对应的系数
    double a1,b1,a2,b2,a3,b3,c3;
    //行列式，便于运用克莱姆法则
    double D1,D2,D3;
    for(int i = 0; i < xValues.size(); ++i)
    {
        x += xValues[i];
        y += yValues[i];
        xx += qPow(xValues[i], 2);
        xy += xValues[i] * yValues[i];
        yy += qPow(yValues[i], 2);
        xxx += qPow(xValues[i], 3);
        xxy += qPow(xValues[i], 2) * yValues[i];
        xxxx += qPow(xValues[i], 4);
        lnx += qLn(xValues[i]);
        lnxx += qPow(qLn(xValues[i]*1.0), 2);
        lnxy += qLn(xValues[i]) * yValues[i];
        lnyy += qPow(yValues[i], 2);
//qDebug("%lf",xxxx);
    }
    /*Matrix3d A;
    A << xValues.size(),x,xx,
         x,xx,xxx,
         xx,xxx,xxxx;
    Vector3d B(y, xy, xxy);
    Vector3d solution = A.colPivHouseholderQr().solve(B);
    a3 = A(0);
    b3 = A(1);
    c3 = A(2);*/
    //qDebug("%lf %lf %d %lf",x,y,xValues.size(),xx);
    //克莱姆法则计算系数
    D1 = xValues.size() * xx - x * x;
    a1 = (y * xx - x * xy) / D1;
    b1 = (xValues.size() * xy - x * y) / D1;
    D2 = xValues.size() * lnxx - lnx * lnx;
    a2 = (y * lnxx - lnx * lnxy) / D2;
    b2 = (xValues.size() * lnxy - lnx * y) / D2;
    D3 = xValues.size() * xx * xxxx + 2 * x * xx * xxx - qPow(xx, 3) - qPow(x, 2) * xxxx - xValues.size() * qPow(xxx, 2);
    a3 = (y * xx * xxxx + xy * xxx * xx + xxy * x * xxx - qPow(xx, 2) * xxy - x * xy * xxxx - qPow(xxx, 2) * y) / D3;
    b3 = (xValues.size() * xy * xxxx + x * xx * xxy + y * xx * xxx - qPow(xx, 2) * xy - x * y * xxxx - xValues.size() * xxy * xxx) / D3;
    c3 = (xValues.size() * xx * xxy + x * y * xxx + x * xx * xy - qPow(xx, 2) * y - qPow(x, 2) * xxy - xValues.size() * xy * xxx) / D3;

qDebug("%lf %lf %lf",a3,b3,c3);
    //计算方差选优
    double v1 = 0, v2 = 0, v3 = 0;
    for(int i = 0; i < xValues.size(); ++i)
    {
        v1 += qPow(a1 + b1 * xValues[i] - yValues[i], 2);
        v2 += qPow(a2 + b2 * qLn(xValues[i]) - yValues[i], 2);
        v3 += qPow(a3 + b3 * xValues[i] + c3 * qPow(xValues[i], 2) - yValues[i], 2);//qDebug("%lf %lf %lf",v1,qLn(xValues[i]),v3);
    }
qDebug("%lf %lf %lf",v1,v2,v3);
    //选取方差最小的方案，并给Fitting类赋值
    if((v1 < v2) && (v1 < v3))
    {
        fitting.a = a1;
        fitting.b = b1;
        fitting.c = 0;
        fitting.type = 1;
    }
    else if((v2 < v1) && (v2 < v3))
    {
        fitting.a = a2;
        fitting.b = b2;
        fitting.c = 0;
        fitting.type = 2;
    }
    else
    {
        fitting.a = a3;
        fitting.b = b3;
        fitting.c = c3;
        fitting.type = 3;
    }
    return fitting;
}

void Menu::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
