#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

signals:
    void display(int number);


private slots:
    void on_ScatterButton_clicked();

    void on_BarChartButton_clicked();

private:
    Ui::Menu *ui;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // MENU_H
