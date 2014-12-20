#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void openSerialPort();
     QString value;
private slots:

     void on_pushButton_clicked();
     void on_pushButton_2_clicked();

public slots:
     void acceptConnection();
     void startRead();
     void upvalue();
private:
    Ui::MainWindow *ui;

    QSerialPort *serial;
    QTcpServer server;
    QTcpSocket *client;
};

#endif // MAINWINDOW_H
