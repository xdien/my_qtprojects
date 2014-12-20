#-------------------------------------------------
#
# Project created by QtCreator 2014-04-26T18:09:09
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = nrcr
TEMPLATE = app

DEFINES += NCREPORT_IMPORT
SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
INCLUDEPATH += /home/xdien/NCReport2/include
LIBS += -L/home/xdien/NCReport2/lib -lNCReport
