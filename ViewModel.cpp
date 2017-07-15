#include "ViewModel.h"

ViewModel::ViewModel()
{
    ChangeGraph_cmd = (QSharedPointer<CommandBase>) new ChangeGraphCommand(this);
    Test_cmd = (QSharedPointer<CommandBase>) new TestCommand(this);
}

void ViewModel::setModel(QSharedPointer<MODEL> &p)
{
    model = p;
}

void ViewModel::SetTestResultPtr(QSharedPointer<TestResult> &t)
{
    testresult_ptr = t;
}

void ViewModel::SetTestSourcePtr(QSharedPointer<TestSource> &t)
{
    testsource_ptr = t;
}

void ViewModel::SetGraphChangePtr(QSharedPointer<GraphChange> &p)
{
    graphchange_ptr = p;
}

void ViewModel::SetNewGraphPtr(QSharedPointer<Neuro> &p)
{
    newgraph_ptr = p;
}

QSharedPointer<CommandBase>& ViewModel::getChangeGraphCommand()
{
    return ChangeGraph_cmd;
}

void ViewModel::setDrawGraphCommand(QSharedPointer<CommandBase> &p)
{
    DrawGraph_cmd = p;
}

QSharedPointer<CommandBase>& ViewModel::getTestCommand()
{
    return Test_cmd;
}

void ViewModel::setDrawTestCommand(QSharedPointer<CommandBase> &p)
{
    DrawTest_cmd = p;
}

void ViewModel::setNotification(const QString &message)
{
    if(message == "change_graph"){
        QString DataStructure = testsource_ptr->DataStructure;
        if(DataStructure == "array"){
            this->Notify("draw_array");
        }
        else{
            this->Notify("draw_tree");
        }
    }
    else if(message == "test"){
        QString DataType = testsource_ptr->DataType;
        QString DataStructure = testsource_ptr->DataStructure;
        QString TestType = testsource_ptr->TestType;
        int testsize = testsource_ptr->TestSize;
        if(testsize == 0){
            double* result = model->testing(DataType,DataStructure,TestType,testsize);
            for(int i=0;i<100;i++){
                testresult_ptr->xValues.operator [](i) = (i+1)*testsize;
                testresult_ptr->yValues.operator [](i) = result[i];
                testresult_ptr->DataStructure = DataStructure;
                testresult_ptr->TestType = TestType;
            }
            this->Notify("draw_scatter");
        }
        else if(DataType == ""){
            testresult_ptr->DataStructure = DataStructure;
            testresult_ptr->TestSize = testsize;
            testresult_ptr->yValues.operator [](0) = model->testing("Random",DataStructure,TestType,testsize)[0];
            testresult_ptr->yValues.operator [](1) = model->testing("Increasing",DataStructure,TestType,testsize)[0];
            testresult_ptr->yValues.operator [](2) = model->testing("Decreasing",DataStructure,TestType,testsize)[0];
            this->Notify("draw_barchart");
        }
    }
    else{
        QMessageBox::warning(new QWidget,QString("Attention"),QString("Unknown Signal!"));
    }
}

void ViewModel::ifFail(bool flag)
{
    if(!flag)
        QMessageBox::warning(new QWidget,QString("Attention"),QString("Illegal Operation!"));
}
