#-------------------------------------------------
#
# Project created by QtCreator 2017-05-05T16:04:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ModelviewTest_QTableView
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mymodel.cpp \
    camerastatus.cpp

HEADERS  += mainwindow.h \
    mymodel.h \
    camerastatus.h

FORMS    += mainwindow.ui
