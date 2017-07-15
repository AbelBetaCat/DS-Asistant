#include "APP.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    pModel = (QSharedPointer<MODEL>) new MODEL;
    pVM = (QSharedPointer<ViewModel>) new ViewModel;
    pTest = (QSharedPointer<TEST>) new TEST;
    pGraph = (QSharedPointer<GRAPH>) new GRAPH;
    pVM->setModel(pModel);

    pVM->SetTestResultPtr(pTest->getTestResultPtr());
    pVM->SetTestSourcePtr(pTest->getTestSourcePtr());
    pVM->SetGraphChangePtr(pGraph->GetGraphChangePtr());
    pVM->SetNewGraphPtr(pGraph->GetNewGraph());

    pVM->setDrawGraphCommand(pGraph->getDrawGraphCommand());
    pVM->setDrawTestCommand(pTest->getDrawTestCommand());
    pGraph->setChangeGraphCommand(pVM->getChangeGraphCommand());
    pTest->setTestCommand(pVM->getTestCommand());

    pModel->addReceiver(pVM);
    pVM->addReceiver(pTest);
    pVM->addReceiver(pGraph);
    pTest->addReceiver(pVM);
    pGraph->addReceiver(pVM);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_1_clicked()
{
    pGraph->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    pTest->show();
}
