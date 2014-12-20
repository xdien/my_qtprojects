#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void timerEvent(QTimerEvent *e);

    double position;
    double timerId;
    void paintEvent(QPaintEvent *);
    void drawExample(QPainter & painter);
    void drawExample2(QPainter & painter);
    void DongHo(QPainter & painter);
signals:

public slots:

};

#endif // GRAPHICS_H
