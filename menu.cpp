#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    setFixedSize(1100, 700);

}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_ScatterButton_clicked()
{
    emit display(1);
}

void Menu::on_BarChartButton_clicked()
{
    emit display(2);
}

void Scatter::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

