#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
#include <QDebug>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //them vao
    connect(&server, SIGNAL(newConnection()),
        this, SLOT(acceptConnection()));

    server.listen(QHostAddress::Any, 8888);
    //----------------------------------
    serial = new QSerialPort();
    this->openSerialPort();
    serial->write(QString("e").toLocal8Bit());
    serial->waitForReadyRead(500);
    value = serial->readAll();
    qDebug() << value;
    //ui->lineEdit_2->setText(value.at(0));
    /*if(value.at(1).digitValue())
    {
        ui->tinhtrang->setText("Tat");
    }
    else
    {
        ui->tinhtrang->setText("Bat");
    }*/
    connect(serial,SIGNAL(readyRead()),this,SLOT(upvalue()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openSerialPort()
{
    serial->setPortName("/dev/ttyUSB0");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if (serial->open(QIODevice::ReadWrite)) {
            ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                       .arg("/dev/ttyUSB0").arg(QSerialPort::Baud9600).arg(QSerialPort::Data8)
                                       .arg(QSerialPort::NoParity).arg(QSerialPort::OneStop).arg(QSerialPort::NoFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        ui->statusBar->showMessage(tr("Open error"));
    }
}
//refesh button
void MainWindow::on_pushButton_clicked()
{
    qDebug() << serial->write("a");
    serial->waitForReadyRead(200);
    ui->label_3->clear();
    ui->label_3->setText(value.at(0));
    if(value.at(1).digitValue())
    {
        ui->tinhtrang->setText("Tat");
    }
    else
    {
        ui->tinhtrang->setText("Bat");
    }
}
void MainWindow::acceptConnection()
{
  client = server.nextPendingConnection();
  connect(client, SIGNAL(readyRead()),
  this, SLOT(startRead()));
  client->write(value.toLatin1());
}

void MainWindow::startRead()
{
  char buffer[1024] = {0};
  client->read(buffer, client->bytesAvailable());
  cout << buffer << endl;
  if(QString(buffer[0]) == "a")
  {
      client->write(value.toLatin1());//doi Qstring sang bytearray
  }
  //client->close();
}
void MainWindow::upvalue()
{
    ui->label_3->clear();
    value = serial->readAll();//tu serial tu dong gui
    qDebug()<< value;
    ui->label_3->setText(value.at(0));
    if(value.at(1).digitValue())
    {
        ui->tinhtrang->setText("Tat");
    }
    else
    {
        ui->tinhtrang->setText("Bat");
    }
    //client->waitForBytesWritten(200);
    //client->write(value.toLocal8Bit());
}

void MainWindow::on_pushButton_2_clicked()
{
    serial->waitForBytesWritten(500);
    serial->write("s");
     serial->waitForReadyRead(200);
    serial->write("a");
    serial->waitForReadyRead(200);/*
    value = serial->readAll();
    serial->waitForReadyRead(200);
    qDebug()<<value;

    if(value.at(1).digitValue())
    {
        ui->tinhtrang->setText("Tat");
    }
    else
    {
        ui->tinhtrang->setText("Bat");
    }*/
}
