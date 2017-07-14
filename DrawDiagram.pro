#
#  QCustomPlot Plot Examples
#

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = plot-examples
TEMPLATE = app

SOURCES += main.cpp\
         qcustomplot.cpp \
    scatter.cpp \
    menu.cpp \
    barchart.cpp \
    widget.cpp

HEADERS  += \
         qcustomplot.h \
    scatter.h \
    menu.h \
    barchart.h \
    widget.h

FORMS    += \
    scatter.ui \
    menu.ui \
    widget.ui \
    barchart.ui

INCLUDEPATH += C:\Users\SRC\Documents\DrawDiagram\Eigen

RESOURCES += \
    image.qrc
