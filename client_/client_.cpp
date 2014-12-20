#include "client_.h"
#include "ui_client_.h"
#include <iostream>
#include <QDebug>
#include <QMessageBox>
using namespace std;

Client_::Client_(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client_)
{
    ui->setupUi(this);
}

Client_::~Client_()
{
    client.close();
    delete ui;
}
void Client_::start(QString address, quint16 port)
{
  QHostAddress addr(address);
  client.connectToHost(addr, port);
  connect(&client,SIGNAL(readyRead()),this,SLOT(hienthi()));
}

void Client_::startTransfer()
{
  client.write("Hello, world", 13);
}

void Client_::on_pushButton_clicked()
{
    //gui text tu lineedit
    if(client.isOpen())
    {
        this->hienthi();
    }
    else
    {
        QMessageBox notconn;
        notconn.setText("Chua ket noi!");
        notconn.show();
    }
}

void Client_::on_actionConnect_triggered()
{
    if(client.isOpen())
    {
        QMessageBox thongbaoDakn;
        thongbaoDakn.setText("Da ket noi!");
    }
    else
    {
    this->start("127.0.0.1",8888);
    ui->statusBar->showMessage("Da ket noi den: 127.0.0.1:8888");
    }
}

void Client_::on_actionDisconnection_triggered()
{
    client.close();
    client.disconnect();
    ui->statusBar->showMessage("Disconnected!");
}

void Client_::on_actionT_triggered()
{
    this->close();
}
void Client_::hienthi()
{
    char buffer[1024] = {0};
    client.write("a");
    client.waitForReadyRead(200);
    client.read(buffer, client.bytesAvailable());
    ui->songuoi->setText(QString(buffer[0]));
    if(QString(buffer[1]).toUInt())
    {
        ui->den->setText("Tat");
    }
    else
    {
        ui->den->setText("Bat");
    }
}
