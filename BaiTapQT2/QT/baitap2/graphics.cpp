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
    if(mode==1)BaiTap1(painter);
    if(mode==2)BaiTap2(painter);
    if(mode==3)ChiecBanhHinhNguoi(painter);
    if(mode==4)NgoiNha(painter, 100, 100, 400, 200);
    if(mode==5)ThaiCuc(painter);
}
int graphics::Random(int n)
{
return(rand()%n);
}
void graphics::BaiTap1(QPainter &painter)
{
    int w=width();
    int h=height();
    for (int i=1;i<10000;i++)
    {
    int x=Random(w);
    int y=Random(h);
    painter.setPen(QPen(Qt::red,4,Qt::SolidLine));
    painter.drawPoint(x,y);
}
}

void graphics::BaiTap2(QPainter &painter)
{
    int w=width();
    int h=height();

    QPoint P[3];
    P[0].setX(w/2);
    P[0].setY(0);
    P[1].setX(0);
    P[1].setY(h);
    P[2].setX(w);
    P[2].setY(h);
    int k = Random(3);
    QPoint point = P[k];
    painter.drawPoint(P[k]);
    for (int i=0;i<100000;i++)
    {
        int r = Random(3);
        point.setX((point.x()+P[r].x())/2);
        point.setY((point.y()+P[r].y())/2);
         painter.setPen(QPen(Qt::black,2,Qt::SolidLine));
        painter.drawPoint(point);
    }

}
 void graphics::ChiecBanhHinhNguoi(QPainter &painter)
 {
     QPoint P(115,121);
     for (int i=0;i<100000;i++)
     {
     QPoint Q;
     Q.setX(40*(1+2*3)-P.y()+ abs(P.x()-40*3));
     Q.setY(P.x());
     painter.setPen(QPen(Qt::black,2,Qt::SolidLine));
    painter.drawPoint(Q);
    P=Q;
     }
 }
 void graphics::NgoiNha(QPainter &painter,int x, int y, int c, int r)
 {
     QPoint A(x,y);
     QPoint B(x+(r/2), y+(c/3));
     QPoint C(x+(r/2), y+c);
     QPoint D(x-(r/2), y+c);
     QPoint E(x-(r/2), y+(c/3));
     QPolygon poly1;
     poly1 << A << B << C << D << E;
     painter.drawPolygon(poly1);
     QPoint A1(x,y+c);
     QPoint B1(x-(r/4), y+c);
     QPoint C1(x-(r/4), y+(2*c)/3);
     QPoint D1(x, y+(2*c/3));
     QPolygon poly2;
     poly2 << A1 << B1 << C1 << D1;
     painter.drawPolygon(poly2);

     QPoint A2(x+(r/4), y+c/3);
     QPoint B2(x+(r/4), y+c/2);
     QPoint C2(x+(r/32), y+c/2);
     QPoint D2(x+(r/32), y+c/3);
     QPolygon poly3;
     poly3 << A2 << B2 << C2 << D2;
     painter.drawPolygon(poly3);
      painter.setBrush(QBrush(Qt::black));
     QPoint A3(x-(r/8), y+c/12);

     QPoint B3(x-(r/8), y);
     QPoint C3(x-(r/4), y);
     QPoint D3(x-(r/4), y+c/6);

     QPolygon poly4;
     poly4 << A3 << B3 << C3 << D3;
     painter.drawPolyline(poly4);
     //chua xong
 }
void graphics::ThaiCuc(QPainter &painter)
{
    int h = height();
    int w = width();
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::white));
    painter.drawChord(w/2, h/2, 200, 200, 0, -180*16);

        painter.setBrush(QBrush(Qt::black));
    painter.drawChord(w/2, h/2, 200, 200, 0, 180*16);
      painter.setBrush(QBrush(Qt::black));
    painter.drawChord(w/2, h/2+50, 100, 100, 0, -180*16);
    painter.setBrush(QBrush(Qt::white));
     painter.drawChord(w/2+100, h/2+50, 100, 100, 0, 180*16);
     painter.setBrush(QBrush(Qt::black));
     painter.drawEllipse(w/2+140,h/2+90,20,20);
      painter.setBrush(QBrush(Qt::white));
          painter.drawEllipse(w/2+40,h/2+90,20,20);


    painter.setBrush(QBrush(Qt::black));

}
