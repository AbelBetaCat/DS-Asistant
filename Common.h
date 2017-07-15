#ifndef COMMON
#define COMMON

//#include <QtGui>
#include <QApplication>
#include <QGroupBox>
#include <QString>
#include <QLineEdit>
#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QMenu>
#include <QListWidget>
#include <QMessageBox>
#include <QComboBox>
#include <QPushButton>
#include <QLayout>
#include <QPainter>
#include <QFont>
#include <math.h>
#include <QSharedPointer>

class Receiver
{
public:
    virtual void setNotification(const QString& message) = 0;
    virtual void ifFail(bool flag) = 0;
    virtual ~Receiver(){}
};

class Messager
{
private:
    QVector<QSharedPointer<Receiver> >NewsBoard;

public:
    void addReceiver(QSharedPointer<Receiver> receiver) {NewsBoard.append(receiver);}

    void Notify(const QString& message){
        QSharedPointer<Receiver> *pr = NewsBoard.begin();
        QSharedPointer<Receiver> *pend = NewsBoard.end();
        for (; pr<=pend; pr++) (*pr)->setNotification(message);
    }

    void Notify(bool flag){
        QSharedPointer<Receiver> *pr = NewsBoard.begin();
        QSharedPointer<Receiver> *pend = NewsBoard.end();
        for (; pr<=pend; pr++) (*pr)->ifFail(flag);
    }
};

class MessageBase
{
public:
    virtual ~MessageBase(){}
};

class CommandBase
{
private:
    QSharedPointer<MessageBase> pMessage;
public:
    virtual void setMessage(const QSharedPointer<MessageBase> &pM){ pMessage = pM; }
    virtual void exec() = 0;
    virtual ~CommandBase(){}
};

class TestResult : public MessageBase
{
public:
    QString DataStructure;
    QString TestType;
    QVector<double> xValues;
    QVector<double> yValues;
    int TestSize;
};

class TestSource : public MessageBase
{
public:
    int TestSize;
    int change;
    QString DataStructure;
    QString DataType;
    QString TestType;

    TestSource()
    {
       change = 0;
       TestSize = 0;
       DataStructure = "";
       DataType = "";
       TestType = "";
       qDebug("success!");
    }
    virtual ~TestSource(){}
};

class GraphChange : public MessageBase
{
public:
    QString type;
    QString operation;
};

class Tree_Node : public MessageBase
{
public:
    QString value;
    int color;
    int leader; // -1 means no parent
};
class Neuro
{
public:
    QVector<Tree_Node> T;
};

#endif // COMMON
