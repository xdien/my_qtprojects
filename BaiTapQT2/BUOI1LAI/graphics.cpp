#include "graphics.h"
#include <QPainter>
#include "math.h"

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
}
void graphics::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(mode==1)VeHinhTron(painter);
    if(mode==2)ThaiCucQuyen(painter);
    if(mode==3)NgoiNhaTiHon(painter);
    if(mode==4)CoVua(painter);
    if(mode==5)NgoiLang(painter,700,200,400,300);
    if(mode==6)ThaiCucQuyen2(painter);
    if(mode==7)TamGiacConRua(painter);
    if(mode==8)NgoiNhaRua(painter);
    if(mode==9)NgoiNhaRuaNguoc(painter);
}
void graphics::VeHinhTron(QPainter &painter)
{
    int w=width();
    int h=height();
    QPoint a(w/2,h/2);
    painter.drawEllipse(a,200,200);
    painter.drawRect(w/2-100*1.41,h/2-100*1.41,200*1.41,200*1.41);
}
void graphics::ThaiCucQuyen(QPainter& painter)
{
    int w=width();
    int h=height();
    QPoint a(w/2,h/2);
    painter.drawEllipse(a,200,200);
// 2 Hinh Tron Nho
    painter.drawEllipse(w/2-120,h/2,30,30);
    painter.drawEllipse(w/2+100,h/2,30,30);
// 2 Can Moc
    painter.drawArc(w/2-200,h/2-100,200,200,0,16*-180);
    painter.drawArc(w/2,h/2-100,200,200,0,16*180);
}
void graphics::NgoiNhaTiHon(QPainter& painter)
{
    QPoint A(150,450);
    QPoint B(350,450);
    QPoint C(350,200);
    QPoint D(250,100);
    QPoint E(150,200);

    QPolygon poly1;
    poly1 << A << B << C << D << E;
    painter.drawPolygon(poly1);
 // cai cua
    QPoint A1(250,450);
    QPoint B1(250,300);
    QPoint C1(200,300);
    QPoint D1(200,450);


    QPolygon poly11;
    poly11 << A1 << B1 << C1 << D1;
    painter.drawPolygon(poly11);
    painter.drawRect(300,250,30,30);
// ong khoi
    QPoint A12(200,150);
    QPoint B12(200,90);
    QPoint C12(175,90);
    QPoint D12(175,175);


    QPolygon poly12;
    poly12 << A12 << B12 << C12 << D12;
    painter.drawPolyline(poly12);

}
void graphics::CoVua(QPainter& painter)
{
    int k=50;
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
        {
            if((i+j)%2==1)
            {
                painter.setBrush(Qt::yellow);
                painter.drawRect(k*i,k*j,k,k);
            }
            else
            {
                painter.setBrush(Qt::red);
                painter.drawRect(k*i,k*j,k,k);
            }
        }

}
void graphics::NgoiLang(QPainter& painter,int x,int y,int c,int r)
{
    QPoint A(x-r/2,y+c);
    QPoint B(x+r/2,y+c);
    QPoint C(x+r/2,y+c/3);
    QPoint D(x,y);
    QPoint E(x-r/2,y+c/3);
    QPolygon poly1;
    poly1 << D << E << A << B << C;
    painter.drawPolygon(poly1);
// ve cai cua
    QPoint A1(x,y+c);
    QPoint B1(x,y+2*c/3);
    QPoint C1(x-r/4,y+2*c/3);
    QPoint D1(x-r/4,y+c);
    QPolygon poly2;
    poly2 << A1 << B1 << C1 << D1;
    painter.drawPolyline(poly2);
 // ve cua so
   QPoint A11(x-r/4,y+c/6);
    QPoint B11(x-r/4,y);
   QPoint C11(x-r/8,y);
    QPoint D11(x-r/8,y+c/12);
   QPolygon poly21;
    poly21 << A11 << B11 << C11 << D11;
    painter.drawPolygon(poly21);
    painter.drawRect(x+r/4,y+c/2.5,c/10,r/10);

}
void graphics::ThaiCucQuyen2(QPainter& painter)
{
      painter.setPen(Qt::NoPen);
    int w=width();
    int h=height();
    QPoint a(w/2,h/2);
   painter.setBrush(QBrush(Qt::black));
    painter.drawChord(w/2-100,h/2-200,400,400,0,16*180);
    painter.setBrush(QBrush(Qt::white));
    painter.drawChord(w/2-100,h/2-200,400,400,0,16*-180);
    // vong thai cuc
    painter.setBrush(QBrush(Qt::black));
    painter.drawChord(w/2-100,h/2-100,200,200,0,16*-180);
     painter.setBrush(QBrush(Qt::white));
    painter.drawChord(w/2+100,h/2-100,200,200,0,16*180);
    painter.setBrush(QBrush(Qt::white));
     painter.drawEllipse(w/2-25,h/2-10,30,30);
   painter.setBrush(QBrush(Qt::black));
     painter.drawEllipse(w/2+200,h/2-10,30,30);

}
// con rua
QPointF graphics::DiChuyen(QPointF P, double dist)
{
    QPointF New_P(P.x()+dist*cos((M_PI*Direction)/180),P.y()+dist*sin((M_PI*Direction)/180));
    return New_P;
}
void graphics::TamGiacConRua(QPainter& painter)
{
    Direction=0;
    painter.setPen(QPen(Qt::red,2,Qt::SolidLine));
    QPointF A(500,500);
    int dist=50;

    CP=A;
    A=DiChuyen(A,6*dist);
    painter.drawLine(CP,A);
     Direction+=-120;
     for(int i=1;i<=2;i++)
     {
         CP=A;
         A=DiChuyen(A,6*dist);
         painter.drawLine(CP,A);
          Direction+=-120;
     }

     CP=A;
     A=DiChuyen(A,3*dist);
     painter.drawLine(CP,A);
//
       Direction+=-60;

       for(int i=1;i<=3;i++)
       {
           CP=A;
           A=DiChuyen(A,3*dist);
           painter.drawLine(CP,A);
           Direction+=-120;
       }
}
 // Ngoi Nha rua

void graphics::NgoiNhaRua(QPainter& painter)
{
    Direction+=-120;
    painter.setPen(QPen(Qt::red,2,Qt::SolidLine));
    QPointF A(700,300);
    int dist=50;
// noc nha
    for(int i=1;i<=2;i++)
    {
        CP=A;
        A=DiChuyen(A,2*dist);
        painter.drawLine(CP,A);
        Direction+=-120;
    }
// khung nha
     Direction+=90;
     CP=A;
     A=DiChuyen(A,3*dist);
     painter.drawLine(CP,A);

     Direction+=-90;
     CP=A;
     A=DiChuyen(A,2*dist);
     painter.drawLine(CP,A);

     Direction+=-90;
     CP=A;
     A=DiChuyen(A,3*dist);
     painter.drawLine(CP,A);
// di chuyen nhung khong hien ra
     Direction+=-90;
     CP=A;
     A=DiChuyen(A,2*dist);
 // quay xuong goc nha
     Direction+=-90;
     CP=A;
     A=DiChuyen(A,3*dist);
     painter.drawLine(CP,A);

     Direction+=-90;
     CP=A;
     A=DiChuyen(A,dist);
     painter.drawLine(CP,A);
// Bat dau ve cua
     Direction+=-90;
     CP=A;
     A=DiChuyen(A,1.5*dist);
     painter.drawLine(CP,A);

     Direction+=-90;
     CP=A;
     A=DiChuyen(A,dist/2);
     painter.drawLine(CP,A);

     Direction+=-90;
     CP=A;
     A=DiChuyen(A,1.5*dist);
     painter.drawLine(CP,A);
  // quay len dau canh cua
     Direction+=-90;
     CP=A;
     A=DiChuyen(A,dist/2);
     painter.drawLine(CP,A);

     Direction+=-90;
     CP=A;
     A=DiChuyen(A,1.5*dist);
     painter.drawLine(CP,A);
 // Bat dau ve cua so

     Direction+=45;
     CP=A;
     A=DiChuyen(A,dist);


      Direction+=-45;
      for(int i=1;i<=6;i++)
      {
      CP=A;
      A=DiChuyen(A,dist/3);
      painter.drawLine(CP,A);
       Direction+=-90;
      }
 // ve ong khoi
      Direction+=140;
      CP=A;
      A=DiChuyen(A,1.5*dist);


       Direction+=40;
       CP=A;
       A=DiChuyen(A,dist);
       painter.drawLine(CP,A);

        Direction+=90;
        CP=A;
        A=DiChuyen(A,dist/3-4);
        painter.drawLine(CP,A);

        Direction+=90;
        CP=A;
        A=DiChuyen(A,dist/3+7);
        painter.drawLine(CP,A);


}
void graphics::NgoiNhaRuaNguoc(QPainter& painter)
{
    Direction+=-120;
    painter.setPen(QPen(Qt::red,2,Qt::SolidLine));
    QPointF A(700,300);
    int dist=50;
// noc nha
    for(int i=1;i<=2;i++)
    {
        CP=A;
        A=DiChuyen(A,2*dist);
        painter.drawLine(CP,A);
        Direction+=-120;
    }
// khung nha
     Direction+=90;
     CP=A;
     A=DiChuyen(A,3*dist);
     painter.drawLine(CP,A);

     Direction+=-90;
     CP=A;
     A=DiChuyen(A,2*dist);
     painter.drawLine(CP,A);

     Direction+=-90;
     CP=A;
     A=DiChuyen(A,3*dist);
     painter.drawLine(CP,A);
// di chuyen nhung khong hien ra
     Direction+=-90;
     CP=A;
     A=DiChuyen(A,2*dist);
 // quay xuong goc nha
     Direction+=-90;
     CP=A;
     A=DiChuyen(A,3*dist);
     painter.drawLine(CP,A);

     Direction+=-90;
     CP=A;
     A=DiChuyen(A,dist);
     painter.drawLine(CP,A);
// Bat dau ve cua
     Direction+=-90;
     CP=A;
     A=DiChuyen(A,1.5*dist);
     painter.drawLine(CP,A);

     Direction+=90;
     CP=A;
     A=DiChuyen(A,dist/2);
     painter.drawLine(CP,A);

     Direction+=90;
     CP=A;
     A=DiChuyen(A,1.5*dist);
     painter.drawLine(CP,A);

     Direction+=90;
     CP=A;
     A=DiChuyen(A,dist/2);
     painter.drawLine(CP,A);

     Direction+=90;
     CP=A;
     A=DiChuyen(A,1.5*dist);
     painter.drawLine(CP,A);
// chuyen de ve cua so
     Direction+=-45;
     CP=A;
     A=DiChuyen(A,dist);

// ve cua so
     Direction+=45;
     for(int i=1;i<=6;i++)
     {
     CP=A;
     A=DiChuyen(A,dist/3);
     painter.drawLine(CP,A);
      Direction+=90;
     }
// di chuyen de ve ong khoi
     Direction+=-140;
     CP=A;
     A=DiChuyen(A,1.5*dist);
// ve ong khoi
       Direction+=-40;
       CP=A;
       A=DiChuyen(A,dist);
       painter.drawLine(CP,A);

        Direction+=-90;
        CP=A;
        A=DiChuyen(A,dist/3-4);
        painter.drawLine(CP,A);

        Direction+=-90;
        CP=A;
        A=DiChuyen(A,dist/3+7);
        painter.drawLine(CP,A);

}







