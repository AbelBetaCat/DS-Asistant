#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "DrawDiagram/TestAsistant.h"
#include "MicroImageDisplay/Graph.h"
#include "DS/Model.h"
#include "ViewModel.h"
#include "Common.h"
#include "src/ViewerWindow.h"
#include "src/TreeManager.h"
#include "src/TreeView.h"
#include "src/TreeScene.h"
#include "src/Node.h"
#include "src/Edge.h"
#include "src/AddValuesDialog.h"
#include "src/AddValuesWidget.h"
#include "src/ValueByIndexDialog.h"
#include <cmath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    QSharedPointer<MODEL> pModel;
    QSharedPointer<ViewModel> pVM;
    QSharedPointer<TEST> pTest;
    QSharedPointer<GRAPH> pGraph;

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    //ViewerWindow *viewwindow;
};

#endif // MAINWINDOW_H
