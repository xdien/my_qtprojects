#include "client_.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client_ w;
    w.show();

    return a.exec();
}
