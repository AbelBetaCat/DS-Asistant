#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "Common.h"
#include "DS/Model.h"
#include "DS/DSCommand.h"
#include "DrawDiagram/TestCommand.h"
#include "MicroImageDisplay/GraphCommand.h"
#include "MicroImageDisplay/Transcripton.h"

class ViewModel : public Messager, public Receiver
{
public:
    explicit ViewModel();
    virtual ~ViewModel(){}
    void setModel(QSharedPointer<MODEL> &p);
    void SetTestResultPtr(QSharedPointer<TestResult> &t);
    void SetTestSourcePtr(QSharedPointer<TestSource> &t);
    void SetGraphChangePtr(QSharedPointer<GraphChange> &p);
    void SetNewGraphPtr(QSharedPointer<Neuro> &p);
    QSharedPointer<CommandBase> &getChangeGraphCommand();
    void setDrawGraphCommand(QSharedPointer<CommandBase> &p);
    QSharedPointer<CommandBase> &getTestCommand();
    void setDrawTestCommand(QSharedPointer<CommandBase> &p);

private:
    QSharedPointer<MODEL> model;
    QSharedPointer<TestSource> testsource_ptr;
    QSharedPointer<TestResult> testresult_ptr;
    QSharedPointer<GraphChange> graphchange_ptr;
    QSharedPointer<Neuro> newgraph_ptr;
    QSharedPointer<CommandBase> Test_cmd;
    QSharedPointer<CommandBase> ChangeGraph_cmd;
    QSharedPointer<CommandBase> DrawTest_cmd;
    QSharedPointer<CommandBase> DrawGraph_cmd;
    virtual void setNotification(const QString &message);
    virtual void ifFail(bool flag);
};

#endif // VIEWMODEL_H
