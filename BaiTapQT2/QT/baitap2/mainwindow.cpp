#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_DrawSimple_clicked()
{
    ui->GraphicsPresenter->mode = 1;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode = 0;
}

void MainWindow::on_pushButton_clicked()
{
    ui->GraphicsPresenter->mode = 2;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode = 0;
}

void MainWindow::on_BaiTap3_clicked()
{
    ui->GraphicsPresenter->mode = 3;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode = 0;
}


void MainWindow::on_BaiTap5_clicked()
{
    ui->GraphicsPresenter->mode = 4;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode = 0;
}

void MainWindow::on_Bai6_clicked()
{
    ui->GraphicsPresenter->mode = 5;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode = 0;
}
