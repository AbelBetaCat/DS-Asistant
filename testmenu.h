#ifndef TESTMENU_H
#define TESTMENU_H

#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QLabel>
#include "common.h"
#include "scatter.h"
#include "barchart.h"

namespace Ui {
class TestMenu;
}

class TestMenu : public QWidget
{
    Q_OBJECT

public:
    explicit TestMenu(QWidget *parent = 0);
    ~TestMenu();
    void GetScatterPtr(QSharedPointer<QWidget> scatter);
    void GetBarChartPtr(QSharedPointer<QWidget> barchart);
    QMenuBar *mMenuBar;
    QAction *mAction1[3], *mAction2[3], *mAction3[3], *mAction4[3];
    QMenu *mMenu1, *mMenu2, *mMenu3, *mMenu4;
    QLabel *mLabel1, *mLabel2, *mLabel3, *mLabel4;
    //TestSource *testsource;
    //TestResult *testresult;
    //QSharedPointer<TestResult> testresult_ptr;
    void SetTestSourcePtr(QSharedPointer<TestSource> &t);
    QSharedPointer<TestSource> &GetTestSourcePtr();
    void timerEvent(QTimerEvent *event);
    void SetTestSourceDataStructure(QSharedPointer<TestSource> &testsource_ptr, QString s);
    void SetTestSourceTestSize(QSharedPointer<TestSource> &testsource_ptr, int i);
    void SetTestSourceChange(QSharedPointer<TestSource> &testsource_ptr, int i);
    void SetTestSourceDataType(QSharedPointer<TestSource> &testsource_ptr, QString s);
    void SetTestSourceTestType(QSharedPointer<TestSource> &testsource_ptr, QString s);
    void ResetLabels();

public slots:
    void OnClick10(void);
    void OnClick11(void);
    void OnClick12(void);
    void OnClick20(void);
    void OnClick21(void);
    void OnClick22(void);
    void OnClick30(void);
    void OnClick31(void);
    void OnClick32(void);
    void OnClick40(void);
    void OnClick41(void);
    void OnClick42(void);
    void on_TestButton_clicked();

private:
    Ui::TestMenu *ui;
    QSharedPointer<QWidget> testmenu_ptr1;
    QSharedPointer<QWidget> testmenu_ptr2;
    QSharedPointer<TestSource> testsource_ptr;
    int id;
    //QSharedPointer<TestSource> testsource_ptr1;
    //QSharedPointer<TestResult> testresult_ptr;

protected:
    void resizeEvent(QResizeEvent *);


};

#endif // TESTMENU_H
