#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_Buoi3_clicked();

    void on_pushButton_clicked();

    void on_Baitap1_clicked();

    void on_Baitap11_clicked();

    void on_Baitap2_clicked();

    void on_Baitap22_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
