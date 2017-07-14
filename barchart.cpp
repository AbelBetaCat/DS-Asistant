#include "barchart.h"
#include "ui_barchart.h"

BarChart::BarChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BarChart)
{
    ui->setupUi(this);

    setFixedSize(1100, 700);

    setupDemo(2);
}

BarChart::~BarChart()
{
    delete ui;
}

void BarChart::on_returnMenuButton_clicked()
{
    emit display(0);
}

void BarChart::setupDemo(int demoIndex)
{
  qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
  QVector<double> xValues(200),yValues(200);
  QString structure1 = "AVL Tree", structure2 = "Binary Search Tree";
  double y1 = 100, y2 = 155;
  double maxyy = (y1 > y2) ? y1 : y2;
  setupBarChartDemo(ui->customPlot, structure1, structure2, maxyy);
  setWindowTitle("QCustomPlot: "+demoName);
  ui->customPlot->replot();
}

//s1,s2分别为比较的数据结构
void BarChart::setupBarChartDemo(QCustomPlot *customPlot, QString s1, QString s2, double maxY)
{
  demoName = "Comparison";
  //设置背景
  QLinearGradient gradient(0, 0, 0, 400);
  gradient.setColorAt(0, QColor(90, 90, 90));
  gradient.setColorAt(0.38, QColor(105, 105, 105));
  gradient.setColorAt(1, QColor(70, 70, 70));
  customPlot->setBackground(QBrush(gradient));

  //柱状图
  QCPBars *time = new QCPBars(customPlot->xAxis, customPlot->yAxis);
  time->setAntialiased(false);
  time->setStackingGap(1);
  //设置标题和颜色
  time->setName("Delete Time");
  time->setPen(QPen(QColor(250, 170, 20).lighter(150)));
  time->setBrush(QColor(250, 170, 20));
  //设置横坐标
  QVector<double> ticks;
  QVector<QString> labels;
  ticks << 1 << 2;
  labels << s1 << s2;
  //设置横坐标轴的各种属性
  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
  textTicker->addTicks(ticks, labels);
  customPlot->xAxis->setTicker(textTicker);
  customPlot->xAxis->setTickLabelRotation(60);
  customPlot->xAxis->setSubTicks(false);
  customPlot->xAxis->setTickLength(0, 4);
  customPlot->xAxis->setRange(0, 8);
  customPlot->xAxis->setBasePen(QPen(Qt::white));
  customPlot->xAxis->setTickPen(QPen(Qt::white));
  customPlot->xAxis->grid()->setVisible(true);
  customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
  customPlot->xAxis->setTickLabelColor(Qt::white);
  customPlot->xAxis->setLabelColor(Qt::white);

  //设置纵坐标轴的各种属性
  customPlot->yAxis->setRange(0, maxY*1.1);
  customPlot->yAxis->setPadding(5);
  customPlot->yAxis->setLabel("Compare Different Data Structures");
  customPlot->yAxis->setBasePen(QPen(Qt::white));
  customPlot->yAxis->setTickPen(QPen(Qt::white));
  customPlot->yAxis->setSubTickPen(QPen(Qt::white));
  customPlot->yAxis->grid()->setSubGridVisible(true);
  customPlot->yAxis->setTickLabelColor(Qt::white);
  customPlot->yAxis->setLabelColor(Qt::white);
  customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
  customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

  //输入数据
  QVector<double> timeData;
  timeData  << 100 << 155;
  time->setData(ticks, timeData);

  //设置图例
  customPlot->legend->setVisible(true);
  customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
  customPlot->legend->setBrush(QColor(255, 255, 255, 100));
  customPlot->legend->setBorderPen(Qt::NoPen);
  QFont legendFont = font();
  legendFont.setPointSize(10);
  customPlot->legend->setFont(legendFont);
  customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

