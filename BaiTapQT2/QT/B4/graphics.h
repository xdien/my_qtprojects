#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void timerEvent(QTimerEvent *event);
    double position;
    double timerId;
    void drawExample(QPainter &painter);
    void paintEvent(QPaintEvent *);
    void Dongho(QPainter &painter);
    void Kimgiay(QPainter &painter);
signals:
    
public slots:
    
};

#endif // GRAPHICS_H
