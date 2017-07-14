#ifndef COMMON_H
#define COMMON_H
#pragma once
#include <QSharedPointer>
#include <QVector>
#include <QPainter>

class TestResult
{
public:
    TestResult()
    {

    }

    ~TestResult()
    {

    }

    double time;
    QString DataStructure;
    QString TestType;
    QVector<double> xValues;
    QVector<double> yValues;
    int TestSize;

private:
    QSharedPointer<TestResult> testresult_ptr;

};

class TestSource
{
public:
    TestSource()
    {
       change = 0;
       TestSize = 0;
       DataStructure = "";
       DataType = "";
       TestType = "";
       qDebug("success!");
    }

    ~TestSource()
    {

    }

    int TestSize;
    int change;
    QString DataStructure;
    QString DataType;
    QString TestType;

};
#endif // COMMON_H
