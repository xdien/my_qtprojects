#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    int mode=0;
    void VeHinhTron(QPainter& painter);
    void ThaiCucQuyen(QPainter& painter);
    void NgoiNhaTiHon(QPainter& painter);
    void CoVua(QPainter& painter);
     void NgoiLang(QPainter& painter,int x,int y,int c,int r);
     void ThaiCucQuyen2(QPainter& painter);
     QPointF CP;
     double Direction=0;
     QPointF DiChuyen(QPointF P,double dist);
     void TamGiacConRua(QPainter& painter);
     void NgoiNhaRua(QPainter& painter);
     void NgoiNhaRuaNguoc(QPainter& painter);

    
signals:
    
public slots:
    
};

#endif // GRAPHICS_H
