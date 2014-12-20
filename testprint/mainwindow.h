/***************************************************************************
 *   App QT                                                                 *
 *         										                            *
 *                                                                          *
 *   bdienw@gmail.com                  		                                *
 *   2014                                                                 *
 ***************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QPrintPreviewDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPainter painter;

private slots:
    void on_pushButton_clicked();
    void print(QPrinter *printer);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
