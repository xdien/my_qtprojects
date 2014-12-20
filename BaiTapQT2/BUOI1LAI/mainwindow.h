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
    void on_BtnDrawSimple_clicked();

    void on_pushButton_3_clicked();

    void on_NgoiNha1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_ThaiCuc2_clicked();

    void on_TamGiac_clicked();

    void on_NgoiNhaRua_clicked();

    void on_RuaNguoc_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
