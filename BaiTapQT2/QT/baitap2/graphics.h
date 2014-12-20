#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    int Random(int n);
    void BaiTap1(QPainter &painter);
    void BaiTap2(QPainter &painter);
    void ChiecBanhHinhNguoi(QPainter &painter);
    void NgoiNha(QPainter &painter,int x, int y, int c, int r);
    void ThaiCuc(QPainter &painter);
    int mode = 0;
    
signals:
    
public slots:
    
};

#endif // GRAPHICS_H
