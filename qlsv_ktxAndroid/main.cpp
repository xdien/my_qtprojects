#include "mainwindow.h"
#include <QApplication>
#include <config_sqlconnect.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    config_sqlconnect n;
    n.connectsql();//init connection
    MainWindow w;
    w.show();
    return a.exec();
}
