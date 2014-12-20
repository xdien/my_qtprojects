#include "graphics.h"
#include <math.h>
#include <QString>
#include <QList>
#include <QPainter>
graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    position = 0;
    timerId = startTimer(150);
}
void graphics::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    position +=1;
    repaint();
}
void graphics::drawExample(QPainter &painter)
{
   /* int  h = height();
     int w = width();
     painter.setBrush(QBrush("#4b4848"));
     painter.drawRect(position,h/2,50,50);*/
}

void graphics::paintEvent(QPaintEvent *)
{
QPainter painter(this);
painter.setRenderHint(QPainter::Antialiasing);
drawExample(painter);
Dongho(painter);
//Kimgiay(painter);
/*QString file1 = "D://oto.png";
painter.drawPixmap(position,50,300,100,QPixmap(file1));*/

}
void graphics::Dongho(QPainter &painter)
{
int w=width();
int h=height();
painter.setPen(Qt::NoPen);
painter.setBrush(Qt::blue);
painter.drawRoundRect(w/2-200,h/2-200,400,400);
painter.setBrush(Qt::white);
painter.drawEllipse(w/2-200,h/2-200,400,400);
for (int i=1;i<=12;i++)
{
    int x;
    int y;
    x = w/2-180*(cos(2*M_PI*i/12+M_PI/2));
    y = h/2-180*(sin(2*M_PI*i/12+M_PI/2));
    QPainterPath path1;
    QPointF a(x-8,y+8);
    QString str = QString::number(i);
    QFont font1("Arial",20);
    path1.addText(a,font1,str);
   painter.setBrush(Qt::black);
    painter.drawPath(path1);

}

}
/*void graphics::Kimgiay(QPainter &painter)
{
    int w=width();
    int h=height();
    int x;
    int y;
    x = w/2-180*(cos(2*M_PI*i/60));
    y = h/2-180*(sin(2*M_PI*i/60));
   painter.setBrush(Qt::black);
   painter.drawLines(w/2,h/2,x,y);
}*/
