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
    void on_DrawSimple_clicked();

    void on_pushButton_clicked();

    void on_BaiTap3_clicked();

    void on_BaiTap5_clicked();

    void on_Bai6_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
