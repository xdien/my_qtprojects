#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>


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
    void on_pushButton_clicked();

    void on_MainWindow_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
