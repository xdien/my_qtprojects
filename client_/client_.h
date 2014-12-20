#ifndef CLIENT__H
#define CLIENT__H

#include <QMainWindow>
#include <QHostAddress>
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QByteArray>
namespace Ui {
class Client_;
}

class Client_ : public QMainWindow
{
    Q_OBJECT

public:

    explicit Client_(QWidget *parent = 0);
    ~Client_();
    void start(QString address, quint16 port);
private:
    QString value;
    QTcpSocket client;
    Ui::Client_ *ui;
public slots:
   void hienthi();
   void startTransfer();
private slots:
  void on_pushButton_clicked();
  void on_actionConnect_triggered();
  void on_actionDisconnection_triggered();
  void on_actionT_triggered();
};

#endif // CLIENT__H
