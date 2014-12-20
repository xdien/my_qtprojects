#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QMYSQLDriver>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include <QSqlTableModel>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    //connect(tableView,SIGNAL(customContextMenuRequested(QPoint)));
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPassword("123456");
    db.setUserName("xdien");
    db.setDatabaseName("db_thuvien");
    db.open();
    model = new QSqlTableModel(this);
    model->setTable("thongtin");
    model->select();
    //model->endInsertColumns();
    qDebug()<< model->lastError().text();
    ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    /*QSqlTableModel *model = new QSqlTableModel(NULL, db);
    model->setTable("thongtin");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Name"));*/
    //model->setHeaderData(1, Qt::Horizontal, tr("Salary"));
    //QSqlTableModel *model = new QSqlTableModel(parentObject, database);
    QSqlTableModel *model = new QSqlTableModel(NULL, db);
    model->insertRow();

}

void MainWindow::on_MainWindow_customContextMenuRequested(const QPoint &pos)
{
    QModelIndex index= ui->tableView->indexAt(pos);

        QMenu *menu=new QMenu(this);
        menu->addAction(new QAction("Action 1", this));
        menu->addAction(new QAction("Action 2", this));
        menu->addAction(new QAction("Action 3", this));
        //menu->popup(table->viewport()->mapToGlobal(pos));
        menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}
