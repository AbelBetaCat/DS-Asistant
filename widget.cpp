#include <QStackedLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include "widget.h"
#include "menu.h"
#include "scatter.h"
#include "barchart.h"
#include "menu.cpp"
#include "scatter.cpp"
#include "barchart.cpp"

Widget::Widget(QWidget *parent) :
  QWidget(parent)
{
  //setFixedSize(1200,900);
  Menu *menu = new Menu;
  Scatter *scatter = new Scatter;
  BarChart *barchart = new BarChart;
  stackLayout = new QStackedLayout;
  stackLayout->addWidget(menu);
  stackLayout->addWidget(scatter);
  stackLayout->addWidget(barchart);
  //0
  QObject::connect(menu, &Menu::display, stackLayout, &QStackedLayout::setCurrentIndex);
  //1
  QObject::connect(scatter, &Scatter::display, stackLayout, &QStackedLayout::setCurrentIndex);
  //2
  QObject::connect(barchart, &BarChart::display, stackLayout, &QStackedLayout::setCurrentIndex);

  mainLayout = new QVBoxLayout;
  mainLayout->addLayout(stackLayout);
  setLayout(mainLayout);

}

Widget::~Widget()
{
}









































