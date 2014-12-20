#-------------------------------------------------
#
# Project created by QtCreator 2014-02-13T02:35:04
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mysql_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
#LIBS    += -L/usr/local/mysql/lib
INCLUDEPATH += /usr/local/mysql/include
