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

void MainWindow::on_BtnDrawSimple_clicked()
{
    ui->GraphicsPresenter->mode=1;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode=0;

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->GraphicsPresenter->mode=2;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode=0;
}

void MainWindow::on_NgoiNha1_clicked()
{
    ui->GraphicsPresenter->mode=3;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode=0;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->GraphicsPresenter->mode=4;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode=0;
}

void MainWindow::on_pushButton_clicked()
{
    ui->GraphicsPresenter->mode=5;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode=0;
}

void MainWindow::on_ThaiCuc2_clicked()
{
    ui->GraphicsPresenter->mode=6;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode=0;
}

void MainWindow::on_TamGiac_clicked()
{
    ui->GraphicsPresenter->mode=7;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode=0;
}

void MainWindow::on_NgoiNhaRua_clicked()
{
    ui->GraphicsPresenter->mode=8;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode=0;
}

void MainWindow::on_RuaNguoc_clicked()
{
    ui->GraphicsPresenter->mode=9;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode=0;
}
