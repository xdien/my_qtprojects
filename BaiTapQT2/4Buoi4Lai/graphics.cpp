#include "graphics.h"
#include <QPainter>
#include "math.h"
#include "QString"
#include "QList"

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    position=0;
    timerId=startTimer(50);
}
void graphics::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
   // XeDua(painter);
   // DongHoCo(painter);
    ThaiDuongHe(painter);
}
void graphics::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    position+= 1;
    repaint();
}
void graphics::XeDua(QPainter & painter)
{
    int w=width();
    int height();
    QString file1="D://oto.png";
    painter.drawPixmap(position,100,300,100,QPixmap(file1));
}
// ve dong ho
void graphics::DongHoCo(QPainter & painter)
{
    int w=width();
    int h=height();
    QPoint A(w/2,h/2);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::blue);
    painter.drawRoundRect(w/2-150,h/2-150,300,300);
    painter.setBrush(Qt::white);
    painter.drawEllipse(w/2-150,h/2-150,300,300);

    for(int i=1;i<=12;i++)
    {

        int x;
        int y;
         painter.setBrush(Qt::green);
         x=w/2-130*cos(2*M_PI*i/12+M_PI/2);
         y=h/2-130*sin(2*M_PI*i/12+M_PI/2);
        QPainterPath path1;
        QPointF a(x-13,y+10);
        QString str=QString::number(i);
        QFont font1("Arial",30);
        path1.addText(a,font1,str);
        painter.drawPath(path1);
    }
 // kim giay
    painter.setPen(Qt::red);
   int x=130*cos(2*M_PI*position/60-(M_PI/2))+w/2;
   int y=130*sin(2*M_PI*position/60-(M_PI/2))+h/2;
   QPointF A1(x,y);
   painter.drawLine(A,A1);
 // kim phut
   painter.setPen(Qt::black);
  int x1=110*cos(2*M_PI*position/3600-(4*M_PI/3))+w/2;
  int y1=110*sin(2*M_PI*position/3600-(4*M_PI/3))+h/2;
  QPointF K1(x1,y1);
  painter.drawLine(A,K1);
// kim gio
   painter.setPen(Qt::blue);
  int x11=90*cos(2*M_PI*position/86400-(M_PI/-3))+w/2;
  int y11=90*sin(2*M_PI*position/86400-(M_PI/-3))+h/2;
  QPointF K11(x11,y11);
  painter.drawLine(A,K11);
}
void graphics::ThaiDuongHe(QPainter & painter)
{
// Mat Troi
    int w=width();
    int h=height();
    QPoint A(w/2,h/2);
    QString file2="D://sun.png";
    painter.drawPixmap(w/2-150,h/2-150,300,300,QPixmap(file2));
// Trai Dat

    int x111=300*cos(2*M_PI*position/60-(M_PI/2))+w/2;
    int y111=300*sin(2*M_PI*position/60-(M_PI/2))+h/2;
    QString file3="D://earth.png";
    painter.drawPixmap(x111-80,y111-50,100,100,QPixmap(file3));
// Mat Trang Quay Quanh Trai Dat

    int e111=80*cos(2*M_PI*position*2/60-(M_PI/2))+x111;
    int t111=80*sin(2*M_PI*position*2/60-(M_PI/2))+y111;
    QString file4="D://moon.png";
    painter.drawPixmap(e111-25,t111-25,50,50,QPixmap(file4));

}
