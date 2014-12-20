#include "graphics.h"
#include <QPainter>
#include <math.h>
graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
}

void graphics::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (mode==1)Bai1(painter);
     if (mode==2)Vidu(painter);
     if (mode==3)HinhVuong(painter);
     if (mode==4)TamGiac(painter);
     if (mode==5)ConRua1(painter);
     if (mode==6)PoLy(painter);
}
QPointF graphics::DiChuyen(QPointF P, double dist)
{
    QPointF New_P(P.x()+dist*cos( (M_PI*Direction)/180) , P.y()+ dist*sin(( M_PI*Direction)/180) );
    return New_P;
}
void graphics::Bai1(QPainter &painter)
{

    Direction=0;
    painter.setPen(QPen(Qt::blue,2,Qt::SolidLine));
    QPointF A(200,200);
    int dist = 50;

    for(int i=1;i<=4;i++)
    {
    CP = A;
    A = DiChuyen(A,3*dist);
    painter.drawLine(CP,A);
    Direction +=-90;

    CP = A;
    A = DiChuyen(A,dist);
    painter.drawLine(CP,A);
    Direction += -90;

    CP = A;
    A = DiChuyen(A,dist);
    painter.drawLine(CP,A);
    Direction += -90;
    }

}

void graphics::Vidu(QPainter &painter)
{

    Direction=30;
    painter.setPen(QPen(Qt::blue,2,Qt::SolidLine));
    QPointF A(200,200);
    int dist = 50;

    for(int i=1;i<=4;i++)
    {
    CP = A;
    A = DiChuyen(A,3*dist);
    painter.drawLine(CP,A);
    Direction +=-90;

    CP = A;
    A = DiChuyen(A,dist);
    painter.drawLine(CP,A);
    Direction += -90;

    CP = A;
    A = DiChuyen(A,dist);
    painter.drawLine(CP,A);
    Direction += -90;
    }

}
void graphics::HinhVuong(QPainter &painter)
{
    Direction=0;
    painter.setPen(QPen(Qt::blue,2,Qt::SolidLine));
    QPointF A(200,200);
    int dist = 50;
    for(int i=0;i<5;i++)
    {
        dist=i*50;
    CP = A;
    A = DiChuyen(A,dist);
    painter.drawLine(CP,A);
    Direction +=-90;
    CP = A;
    A = DiChuyen(A,dist);
    painter.drawLine(CP,A);
    Direction += -90;
     CP = A;
    A = DiChuyen(A,dist);
    painter.drawLine(CP,A);
    Direction += -90;
     CP = A;
    A = DiChuyen(A,dist);
    painter.drawLine(CP,A);
    Direction += -90;
}
}

void graphics::TamGiac(QPainter &painter)
{
    Direction=0;
    painter.setPen(QPen(Qt::blue,2,Qt::SolidLine));
    QPointF A(400,200);
    int dist = 100;
for(int i=0;i<=2;i++)
{
    CP = A;
    A = DiChuyen(A,2*dist);
    painter.drawLine(CP,A);
    Direction +=-120;

    CP = A;
    A = DiChuyen(A,dist);
    painter.drawLine(CP,A);
    Direction +=-120;

    CP = A;
    A = DiChuyen(A,dist);
    painter.drawLine(CP,A);
    Direction +=-120;
    CP = A;
    A = DiChuyen(A,dist);
    painter.drawLine(CP,A);
    Direction +=-120;
}
}
void graphics::ConRua1(QPainter &painter)
{
    int w=width();
    int h=height();
    double angle = 60;
    Direction = 0;
    double dist = 5;
    double incr = 1;
    QPointF A(w/2, h/2);
    for (int i=0;i<200;i++)
    {
 CP = A;
A = DiChuyen(A,dist);
 painter.drawLine(CP,A);
Direction +=angle;
dist+=incr;
    }
}
void graphics::PoLy(QPainter &painter)
{ Direction=0;
    painter.setPen(QPen(Qt::red,2,Qt::SolidLine));
    int w=width();
    int h=height();
    double angle = 170;
    Direction = 0;
    double dist = 5;
    double incr = 4;
    QPointF A(w/2, h/2);
    for (int i=0;i<200;i++)
    {
 CP = A;
A = DiChuyen(A,dist);
 painter.drawLine(CP,A);
Direction +=angle;
dist+=incr;
    }
}
