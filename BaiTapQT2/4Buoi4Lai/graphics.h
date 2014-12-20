#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *event);
    double position;
    double timerId;
    void XeDua(QPainter & painter);
    void DongHoCo(QPainter & painter);
    void ThaiDuongHe(QPainter & painter);
signals:
    
public slots:
    
};

#endif // GRAPHICS_H
