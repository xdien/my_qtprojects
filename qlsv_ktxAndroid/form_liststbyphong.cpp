#include "form_liststbyphong.h"
#include "ui_form_liststbyphong.h"
#include <QMessageBox>
#include "config_sqlconnect.h"

Form_listSTbyPhong::Form_listSTbyPhong(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_listSTbyPhong)
{
    ui->setupUi(this);
    querymodel_room = new QSqlQueryModel();
    querymodel_room->setQuery("select ma_phong from PHONG");
    ui->treeView_phong->setModel(querymodel_room);
}

Form_listSTbyPhong::~Form_listSTbyPhong()
{
    delete ui;
}

void Form_listSTbyPhong::on_treeView_phong_clicked(const QModelIndex &index)
{
    listsv = new QSqlQueryModel();
    listsv->setQuery("select distinct SINH_VIEN.mssv, SINH_VIEN.ho_ten from PHONG "\
                     "left join HOP_DONG on PHONG.ma_phong = HOP_DONG.ma_phong "\
                     "left join SINH_VIEN on SINH_VIEN.mssv = HOP_DONG.mssv where PHONG.ma_phong = '"+ index.sibling(index.row(),0).data().toString()+"'");
    ui->treeView_sv->setModel(listsv);
}
