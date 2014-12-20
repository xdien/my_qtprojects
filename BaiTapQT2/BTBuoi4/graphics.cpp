#include "graphics.h"
#include "math.h"
#include "QString"
#include "QList"
#include <QPainter>

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    position=0;
    timerId=startTimer(50);
}
void graphics::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
     position  +=1;
     repaint();
}
void graphics::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
   // drawExample(painter);
  //  drawExample2(painter);
   // DongHo(painter);

}
void graphics::drawExample(QPainter & painter)
{
    int w=width();
    int h=height();
    QString file1="D://oto.png";
    painter.drawPixmap(position,50,300,100,QPixmap(file1));



}
void graphics::drawExample2(QPainter & painter)
{
    int w=width();
    int h=height();
    QString file2="D://oto.png";
    painter.drawPixmap(w-300,50,300,100,QPixmap(file2));
}
void graphics::DongHo(QPainter & painter)
{
    int w=width();
    int h=height();
    QPoint A(w/2,h/2);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::blue);
    painter.drawRoundRect(w/2-130,h/2-165,300,300);
    painter.setBrush(Qt::white);
    painter.drawEllipse(w/2-130,h/2-165,300,300);

    for(int i=1;i<=12;i++)
    {

        int x;
        int y;
         painter.setBrush(Qt::green);
         x=130*cos(2*M_PI*i/12+M_PI/2);
         y=130*sin(2*M_PI*i/12+M_PI/2);
        QPainterPath path1;
        QPointF a(x,y);
        QString str=QString::number(i);
        QFont font1("Arial",30);
        path1.addText(a,font1,str);
        painter.drawPath(path1);
    }
    for(int i=0;i<=60-1;i++)
    {
         QPoint A1(w/2+10,h/2-50);
    int x;
    int y;
    x=w/2+130*cos(2*M_PI*i/position-M_PI/2);
    y=h/2+130*sin(2*M_PI*i/position-M_PI/2);
    QPointF b(w/2+x,h/2+y);
    painter.setPen(QPen(Qt::red,2,Qt::SolidLine));
    painter.drawLine(A1,b);
    }



}
