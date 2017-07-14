#include "testmenu.h"
#include "ui_testmenu.h"
#include <QMenu>
#include <QMenuBar>
#include <QDebug>

TestMenu::TestMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestMenu)
{
    ui->setupUi(this);
    id = startTimer(1);
    mMenu1 = new QMenu("TestSize");
    mMenu2 = new QMenu("DataStructure");
    mMenu3 = new QMenu("DataType");
    mMenu4 = new QMenu("TestType");
    mMenuBar = new QMenuBar(this);
    mLabel1 = new QLabel(this);
    mLabel2 = new QLabel(this);
    mLabel3 = new QLabel(this);
    mLabel4 = new QLabel(this);
    mLabel1->setGeometry(100, 290, 120, 40);
    mLabel2->setGeometry(325, 290, 120, 40);
    mLabel3->setGeometry(550, 290, 120, 40);
    mLabel4->setGeometry(775, 290, 120, 40);
    mAction1[0] = new QAction("100",this);
    mAction1[1] = new QAction("1000",this);
    mAction1[2] = new QAction("10000",this);
    mAction2[0] = new QAction("AVL Tree",this);
    mAction2[1] = new QAction("Binary Search Tree",this);
    mAction2[2] = new QAction("Heap",this);
    mAction3[0] = new QAction("Random",this);
    mAction3[1] = new QAction("Increasing",this);
    mAction3[2] = new QAction("Decreasing",this);
    mAction4[0] = new QAction("Delete",this);
    mAction4[1] = new QAction("Insert",this);
    mAction4[2] = new QAction("Search",this);
    mMenuBar->addMenu(mMenu1);
    mMenuBar->addMenu(mMenu2);
    mMenuBar->addMenu(mMenu3);
    mMenuBar->addMenu(mMenu4);
    mMenu1->addAction(mAction1[0]);
    mMenu1->addAction(mAction1[1]);
    mMenu1->addAction(mAction1[2]);
    mMenu2->addAction(mAction2[0]);
    mMenu2->addAction(mAction2[1]);
    mMenu2->addAction(mAction2[2]);
    mMenu3->addAction(mAction3[0]);
    mMenu3->addAction(mAction3[1]);
    mMenu3->addAction(mAction3[2]);
    mMenu4->addAction(mAction4[0]);
    mMenu4->addAction(mAction4[1]);
    mMenu4->addAction(mAction4[2]);
    QObject::connect(mAction1[0], SIGNAL(triggered()),
            this, SLOT(OnClick10()));
    QObject::connect(mAction1[1], SIGNAL(triggered()),
            this, SLOT(OnClick11()));
    QObject::connect(mAction1[2], SIGNAL(triggered()),
            this, SLOT(OnClick12()));
    QObject::connect(mAction2[0], SIGNAL(triggered()),
            this, SLOT(OnClick20()));
    QObject::connect(mAction2[1], SIGNAL(triggered()),
            this, SLOT(OnClick21()));
    QObject::connect(mAction2[2], SIGNAL(triggered()),
            this, SLOT(OnClick22()));
    QObject::connect(mAction3[0], SIGNAL(triggered()),
            this, SLOT(OnClick30()));
    QObject::connect(mAction3[1], SIGNAL(triggered()),
            this, SLOT(OnClick31()));
    QObject::connect(mAction3[2], SIGNAL(triggered()),
            this, SLOT(OnClick32()));
    QObject::connect(mAction4[0], SIGNAL(triggered()),
            this, SLOT(OnClick40()));
    QObject::connect(mAction4[1], SIGNAL(triggered()),
            this, SLOT(OnClick41()));
    QObject::connect(mAction4[2], SIGNAL(triggered()),
            this, SLOT(OnClick42()));
}

TestMenu::~TestMenu()
{
    delete ui;
    delete mMenuBar;
    delete mMenu1;
    delete mMenu2;
    delete mMenu3;
    delete mMenu4;
    delete *mAction1;
    delete *mAction2;
    delete *mAction3;
    delete *mAction4;
}

void TestMenu::resizeEvent(QResizeEvent *e)
{
    mMenuBar->setGeometry(0,0,width(), 50);
}


void TestMenu::OnClick10(void)
{
    mLabel1->setText("100");
    SetTestSourceTestSize(testsource_ptr, 100);
    SetTestSourceChange(testsource_ptr, 1);
}

void TestMenu::OnClick11(void)
{
    mLabel1->setText("1000");
    SetTestSourceTestSize(testsource_ptr, 1000);
    SetTestSourceChange(testsource_ptr, 1);
}

void TestMenu::OnClick12(void)
{
    mLabel1->setText("10000");
    SetTestSourceTestSize(testsource_ptr, 10000);
    SetTestSourceChange(testsource_ptr, 1);
}
void TestMenu::OnClick20(void)
{
    mLabel2->setText("AVL Tree");
    SetTestSourceDataStructure(testsource_ptr, "AVL Tree");
    SetTestSourceChange(testsource_ptr, 1);
}

void TestMenu::OnClick21(void)
{
    mLabel2->setText("Binary Search Tree");
    SetTestSourceDataStructure(testsource_ptr, "Binary Search Tree");
    SetTestSourceChange(testsource_ptr, 1);
}

void TestMenu::OnClick22(void)
{
    mLabel2->setText("Heap");
    SetTestSourceDataStructure(testsource_ptr, "Heap");
    SetTestSourceChange(testsource_ptr, 1);
}

void TestMenu::OnClick30(void)
{
    mLabel3->setText("Random");
    SetTestSourceDataType(testsource_ptr, "Random");
}

void TestMenu::OnClick31(void)
{
    mLabel3->setText("Increasing");
    SetTestSourceDataType(testsource_ptr, "Increasing");
    SetTestSourceChange(testsource_ptr, 1);
}

void TestMenu::OnClick32(void)
{
    mLabel3->setText("Decreasing");
    SetTestSourceDataType(testsource_ptr, "Decreasing");
    SetTestSourceChange(testsource_ptr, 1);
}

void TestMenu::OnClick40(void)
{
    mLabel4->setText("Delete");
    SetTestSourceTestType(testsource_ptr, "Delete");
    SetTestSourceChange(testsource_ptr, 1);
}

void TestMenu::OnClick41(void)
{
    mLabel4->setText("Insert");
    SetTestSourceTestType(testsource_ptr, "Insert");
    SetTestSourceChange(testsource_ptr, 1);
}

void TestMenu::OnClick42(void)
{
    mLabel4->setText("Search");
    SetTestSourceTestType(testsource_ptr, "Search");
    SetTestSourceChange(testsource_ptr, 1);
}

void TestMenu::GetScatterPtr(QSharedPointer<QWidget> scatter_ptr)
{
    testmenu_ptr1 = scatter_ptr;
}

void TestMenu::GetBarChartPtr(QSharedPointer<QWidget> barchart_ptr)
{
    testmenu_ptr2 = barchart_ptr;
}

void TestMenu::on_TestButton_clicked()
{
    this->close();
    ResetLabels();
    if(testsource_ptr->TestSize)
    testmenu_ptr1->show();
    else
    testmenu_ptr2->show();
    qDebug("%d",testsource_ptr->TestSize);
}

void TestMenu::SetTestSourceDataStructure(QSharedPointer<TestSource> &t, QString s)
{
    t->DataStructure = s;
}

void TestMenu::SetTestSourceTestSize(QSharedPointer<TestSource> &t, int i)
{
    t->TestSize = i;
}

void TestMenu::SetTestSourceChange(QSharedPointer<TestSource> &t, int i)
{
    t->change = i;
}

void TestMenu::SetTestSourceDataType(QSharedPointer<TestSource> &t, QString s)
{
    t->DataType = s;
}

void TestMenu::SetTestSourceTestType(QSharedPointer<TestSource> &t, QString s)
{
    t->TestType = s;
}

void TestMenu::SetTestSourcePtr(QSharedPointer<TestSource> &t)
{
    testsource_ptr = t;
}

void TestMenu::timerEvent(QTimerEvent *event)
{
    //if(testsource_ptr->TestSize == 0)
    //ResetLabels();
}

void TestMenu::ResetLabels()
{
    mLabel1->clear();
    mLabel2->clear();
    mLabel3->clear();
    mLabel4->clear();
}

QSharedPointer<TestSource> &TestMenu::GetTestSourcePtr()
{
    return testsource_ptr;
}
