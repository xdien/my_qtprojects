#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void Bai1(QPainter &painter);
    QPointF CP;
    double Direction;
    QPointF DiChuyen(QPointF P, double dist);
 void Vidu(QPainter &painter);
 void HinhVuong(QPainter &painter);
 void TamGiac(QPainter &painter);
 void ConRua1(QPainter &painter);
 void PoLy(QPainter &painter);
    int mode = 0;

    
signals:
    
public slots:
    
};

#endif // GRAPHICS_H
