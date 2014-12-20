/***************************************************************************
 *   App QT                                                                 *
 *         										                            *
 *                                                                          *
 *   bdienw@gmail.com                  		                                *
 *   2014                                                                 *
 ***************************************************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
