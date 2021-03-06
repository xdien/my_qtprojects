#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "dialog_setting.h"
#include <QMessageBox>
#include "dialog_chitietsv.h"
#include <dialogform.h>
#include "editdatatable.h"
#include "form_liststbyphong.h"
#include "dialog_suadt.h"
#include "dialog_chontp.h"
#include "dialog_chonkhoa.h"
#include "dialogchonnganh.h"
#include "dialog_chonquy.h"
#include <QRegExp>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->loadpage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit_mssvSV->text() == "" || ui->lineEdit_hotenSV->text() == "")
    {
        QMessageBox thongbaorong;
        thongbaorong.setText(QString::fromUtf8("Ban phai dien day du thong tin, xin kiem tra lai!"));
        thongbaorong.exec();
    }
    else {
        QSqlQuery truyvanmoi;
        if(ui->checkBox_gt->isChecked())
            tempint = 1;
        else
           tempint = 0;
        tempst = ui->lineEdit_mssvSV->text();
        truyvanmoi.exec("select * from SINH_VIEN where mssv= '"+tempst+"'");
        if(truyvanmoi.next())
        {
            //tao button moi voi 2 nut
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Da ton tai", "Sinh vien nay ton tai, ban muon cap nhat?",
                                            QMessageBox::Yes|QMessageBox::No);
            if(reply == QMessageBox::Yes)
            {
                tempst1 = "update SINH_VIEN set ten_lop = '"+ui->comboBox_lopSv->itemData(ui->comboBox_lopSv->currentIndex()).toString()+"',ho_ten = '"+ui->lineEdit_hotenSV->text()+"', sdt='" \
                        +ui->lineEdit_sdtSV->text()+"', gioi_tinh = '"+QString::number(tempint)+"', ngay_sinh='"+ui->dateEdit_ngaysinh->date().toString("yyyy-MM-dd")+"', img_path ='"+linkimg+"' where " \
                        "mssv='"+tempst+"'";
                if(!truyvanmoi.exec(tempst1))
                    qDebug()<<truyvanmoi.lastError().text();
                //cap nhat lai dia chi
                newq.exec("delete from DC_CUASV where mssv = '"+tempst+"'");
                //neu ward rong
                if(ui->comboBox_xp->itemData(ui->comboBox_xp->currentIndex()).toString().isEmpty())
                {
                    //neu province rong
                    if(!ui->comboBox_qh->itemData(ui->comboBox_qh->currentIndex()).toString().isEmpty())
                    newq.exec("insert into DC_CUASV(`mssv`,`chitiet`,`wardid`,`districtid`,`provinceid`) values('"+tempst+"','"+ui->lineEdit_diachi->text()+"',NULL,'"\
                              +ui->comboBox_qh->itemData(ui->comboBox_qh->currentIndex()).toString()+"','"+ui->comboBox_tp->itemData(ui->comboBox_tp->currentIndex()).toString()+"')");
                    else
                        newq.exec("insert into DC_CUASV(`mssv`,`chitiet`,`wardid`,`districtid`,`provinceid`) values('"+tempst+"','"+ui->lineEdit_diachi->text()+"',NULL,NULL"\
                                 ",'"+ui->comboBox_tp->itemData(ui->comboBox_tp->currentIndex()).toString()+"')");
                }
                else
                    newq.exec("insert into DC_CUASV(`mssv`,`chitiet`,`wardid`,`districtid`,`provinceid`) values('"+tempst+"','"+ui->lineEdit_diachi->text()+"','"+ui->comboBox_xp->itemData(ui->comboBox_xp->currentIndex()).toString()+"','"\
                          +ui->comboBox_qh->itemData(ui->comboBox_qh->currentIndex()).toString()+"','"+ui->comboBox_tp->itemData(ui->comboBox_tp->currentIndex()).toString()+"')");
                ui->lineEdit_sdtSV->clear();
                ui->lineEdit_mssvSV->clear();
                ui->lineEdit_hotenSV->clear();
            }
        }
        else{
            tempst1 = "insert into SINH_VIEN values ('" +ui->lineEdit_mssvSV->text()+"','"+ui->comboBox_lopSv->itemData(ui->comboBox_lopSv->currentIndex()).toString()+"','"+ui->lineEdit_hotenSV->text()+"','" \
                    +ui->lineEdit_sdtSV->text()+"', '"+QString::number(tempint)+"','"+ui->dateEdit_ngaysinh->date().toString("yyyy-MM-dd")+"','"+linkimg+"')";
            truyvanmoi.exec(tempst1);
            //set dia chi moi
            if(ui->comboBox_xp->itemData(ui->comboBox_xp->currentIndex()).toString().isEmpty())
            {
                //neu province rong
                if(!ui->comboBox_qh->itemData(ui->comboBox_qh->currentIndex()).toString().isEmpty())
                newq.exec("insert into DC_CUASV(`mssv`,`chitiet`,`wardid`,`districtid`,`provinceid`) values('"+tempst+"','"+ui->lineEdit_diachi->text()+"',NULL,'"\
                          +ui->comboBox_qh->itemData(ui->comboBox_qh->currentIndex()).toString()+"','"+ui->comboBox_tp->itemData(ui->comboBox_tp->currentIndex()).toString()+"')");
                else
                    newq.exec("insert into DC_CUASV(`mssv`,`chitiet`,`wardid`,`districtid`,`provinceid`) values('"+tempst+"','"+ui->lineEdit_diachi->text()+"',NULL,NULL"\
                             ",'"+ui->comboBox_tp->itemData(ui->comboBox_tp->currentIndex()).toString()+"')");
            }
            else
                newq.exec("insert into DC_CUASV(`mssv`,`chitiet`,`wardid`,`districtid`,`provinceid`) values('"+tempst+"','"+ui->lineEdit_diachi->text()+"','"+ui->comboBox_xp->itemData(ui->comboBox_xp->currentIndex()).toString()+"','"\
                      +ui->comboBox_qh->itemData(ui->comboBox_qh->currentIndex()).toString()+"','"+ui->comboBox_tp->itemData(ui->comboBox_tp->currentIndex()).toString()+"')");
            p_display(ui->spinBox->value(),4,"SINH_VIEN");
            ui->lineEdit_sdtSV->clear();
            ui->lineEdit_mssvSV->clear();
            ui->lineEdit_hotenSV->clear();
        }
    }

}

void MainWindow::on_actionThoat_triggered()
{
    this->close();
}



void MainWindow::on_comboxLop_tabHopdong_activated(int index)
{
    //query lop roi dua vao combox
    ui->comboBoxSV_tabHD->clear();
    newq.exec("select mssv,ho_ten from SINH_VIEN where ten_lop='"+ui->comboBox_lopSv->itemData(index).toString()+"'");
    qDebug()<< newq.lastQuery();
    while (newq.next()) {
        ui->comboBoxSV_tabHD->addItem(newq.value(1).toString(),newq.value(0));
    }
}


void MainWindow::on_actionCai_dat_triggered()
{
    //hien thi form cai dat
    Dialog_setting mois;
    mois.exec();
}

void MainWindow::on_actionTim_kiem_triggered()
{
    //tao new dialog moi
    DialogForm formseach;
    formseach.exec();
}


//tao ham loadpage
void MainWindow::loadpage()
{   
    QRegExp rx("[0][1,9][0,1,2,3,4,6,7.9]\\d{1,8}");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_sdtSV->setValidator(validator);
    QRegExp rxdk("^[A-Za-z]{0,2}[0-9]{0,4}[A-Za-z][0-9]{1,3}");
    QRegExpValidator *validators = new QRegExpValidator(rxdk,this);
    ui->lineEdit_mssvSV->setValidator(validators);
    //loaf gia tri spinbox cho display so dong cua ket qua
    QSettings giatr("connect.conf",QSettings::IniFormat);
    giatr.beginGroup("Settings");
    ui->spinBox->setValue(giatr.value("p_display").toInt());
    //hien thi danh sach sinh vien
    modelInfosv.setQuery("select * from SINH_VIEN limit "+QString::number(giatrispibox)+","+QString::number(ui->spinBox->value()));
    ui->listView_sv->setModel(&modelInfosv);
    //
    QSqlQuery query;
    query.exec("select * from LOP");
    while (query.next()) {
        //ui->comboBox->addItem(val1);
        ui->comboBox_lopSv->addItem(query.value(2).toString(),query.value(0).toString());
    }
    /*day nha va phong*/
    query.clear();
    query.exec("select * from province");
    while(query.next())
    {
        ui->comboBox_tp->addItem(query.value(1).toString(),query.value(0).toString());
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    //neu ngay di khong nhap thi thi them moi, neu co thi tim kiem hon dong moi nhat cua sinh vien va cap nhat hop dong do
    tm = true;
    if(ui->comboBoxSV_tabHD->currentText().isEmpty())
    {
        QMessageBox tb;
        tb.setText(QString::fromUtf8("Hãy chọn lớp sau đó chọn tên một sinh viên"));
        tb.exec();
    }
    else
    {
        if(ui->lineEdit_Ngaydi->text().isEmpty())
        {
            if(ui->dateEdit_ngadk->date() >= ui->dateEdit_thoihan->date())
            {
                QMessageBox sai;
                sai.setText(QString::fromUtf8("Ngày vào ở mơi hơn thời hạn? Bạn hãy kiểm tra lại"));
                sai.exec();
            }
            else
            {
                newq.exec("select * from HOP_DONG where mssv = '"+ui->comboBoxSV_tabHD->itemData(ui->comboBoxSV_tabHD->currentIndex()).toString()+"' order by ngay_di asc");
                qDebug()<<newq.lastQuery();
                if(newq.next())
                {
                    if(newq.value(4).toString().isEmpty())
                    {
                        QMessageBox tbmoi;
                        tbmoi.setText(QString::fromUtf8("Bạn hãy cập nhật lại hợp đồng trước khi thêm mới hợp đồng cho sinh viên này!"));
                        tbmoi.exec();
                        tm = false;
                    }
                }
                qDebug() << tm;
                if(tm)
                {
                    newq.exec("INSERT INTO `HOP_DONG`(`stt_hd`, `ma_phong`, `mssv`, `ngay_den`, `ngay_di`, `tg_toi_da`) VALUES "\
                              "('','"+ui->comboBoxPhong_tabHD->currentText()+"','"+ui->comboBoxSV_tabHD->itemData(ui->comboBoxSV_tabHD->currentIndex()).toString()+"','"+ui->dateEdit_ngadk->date().toString("yyyy-MM-dd")+"','"\
                              "','"+ui->dateEdit_thoihan->date().toString("yyyy-MM-dd")+"')");
                    modelHopdong.setQuery("select SINH_VIEN.ho_ten as '"+QString::fromUtf8("Ho ten")+"',HOP_DONG.tg_toi_da as '"+QString::fromUtf8("Thoi hang")+"' from SINH_VIEN, HOP_DONG where SINH_VIEN.mssv = HOP_DONG.mssv");
                }
            }
        }
        else
        {
            newq.exec("select * from HOP_DONG where mssv like '%"+ui->comboBoxSV_tabHD->itemData(ui->comboBoxSV_tabHD->currentIndex()).toString()+"%' order by ngay_den desc");
            if(newq.next())
            {
                if(QDate::fromString(ui->lineEdit_Ngaydi->text(),"dd/MM/yyyy") <= newq.value(3).toDate())
                {
                    QMessageBox tb;
                    tb.setText(QString::fromUtf8("Ngày đi không được củ hơn ngày đến của sinh viên ")+newq.value(3).toString());
                    tb.exec();
                }
                newq.exec("update HOP_DONG set ngay_di = STR_TO_DATE('"+ui->lineEdit_Ngaydi->text()+"','%d/%m/%Y') where mssv = '"+newq.value(2).toString()+"' and ngay_den = '"+newq.value(3).toString()+"'");
                qDebug()<<newq.lastQuery();
            }
            else
            {
                QMessageBox inval;
                inval.setText("Sinh viên này chưa đăng ký vào ở KTX!\nNếu bạn muốn đăng ký mới cho sinh viên này thi hãy để trống 'Ngày đi'");
                inval.exec();
            }
        }
    }
}


void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Down || e->key() == Qt::Key_Up)
    {
        this->loadtabSV(ui->listView_sv->currentIndex());
    }
}

void MainWindow::on_comboBox_tp_currentIndexChanged(int index)
{
    newq.clear();
    ui->comboBox_qh->clear();
    newq.exec("select * from district where provinceid = '"+ui->comboBox_tp->itemData(index).toString()+"'");
    while (newq.next()) {
        ui->comboBox_qh->addItem(newq.value(1).toString(),newq.value(0).toString());
    }
    //them gia tri rong
    ui->comboBox_qh->addItem("");
}

void MainWindow::on_comboBox_qh_currentIndexChanged(int index)
{
    QSqlQuery xaphuong;
    ui->comboBox_xp->clear();
    xaphuong.exec("SELECT * FROM `ward` where districtid = '"+ui->comboBox_qh->itemData(index).toString()+"'");
    while(xaphuong.next())
    {
        ui->comboBox_xp->addItem(xaphuong.value(1).toString(),xaphuong.value(0).toString());
    }
    //them fia tri rong
    ui->comboBox_xp->addItem("");
}

void MainWindow::on_listView_sv_clicked(const QModelIndex &index)
{
    this->loadtabSV(index);
}


QString MainWindow::thuocdiachi(QString nhapvao)
{
    int len_address;
    len_address = nhapvao.length();
    switch (len_address) {
    case 2:
        return "province";
        break;
    case 3:
        return "district";
        break;
    case 5:
        return "ward";
        break;
    default:
        return "provice";
        break;
    }
}


void MainWindow::on_action_i_t_ng_triggered()
{
    Dialog_suaDT suadt;
    suadt.exec();
}

void MainWindow::on_pushButton_dlsv_clicked()
{
    //Ham xoa 1 sinh vien
    if(newq.exec("delete from SINH_VIEN where mssv = '"+ui->listView_sv->model()->data(ui->listView_sv->currentIndex()).toString()+"'"))
    {
        QMessageBox thanhconga;
        thanhconga.setText(QString::fromUtf8("Da xoa thanh cong"));
        thanhconga.exec();
        modelInfosv.setQuery("select * from SINH_VIEN limit "+QString::number(giatrispibox)+","+QString::number(ui->spinBox->value()));
    }
}
void MainWindow::setcombobox(QString madc)
{
    int lent;
    lent = madc.length();
    QString luu, disid;
    switch (lent) {
    case 2:
    {
        ui->comboBox_tp->setCurrentIndex(ui->comboBox_tp->findData(madc));
        ui->comboBox_qh->setCurrentIndex(-1);
        ui->comboBox_xp->setCurrentIndex(-1);
        break;
    }
    case 3:
    {
        newq.exec("SELECT * FROM `district` where districtid = '"+madc+"'");
        while(newq.next())
        {
            ui->comboBox_qh->addItem(newq.value(1).toString(), newq.value(0).toString());
            luu = newq.value(4).toString();//luu gia ma tinh thanh
        }

        newq.exec("select * from provice where provinceid = '"+luu+"'");
        ui->comboBox_tp->setCurrentIndex(ui->comboBox_tp->findData(luu));
        ui->comboBox_qh->setCurrentIndex(ui->comboBox_qh->findData(madc));
        ui->comboBox_xp->setCurrentIndex(-1);
        break;
    }
    default:
    {
        newq.exec("SELECT * FROM `ward` where wardid = '"+madc+"'");
        while(newq.next())
        {
            ui->comboBox_xp->addItem(newq.value(1).toString(), newq.value(0).toString());
            disid = newq.value(4).toString();
        }
        //set gia tri cho qh
        newq.exec("select * from district where districtid = '"+disid+"'");
        if(newq.next())
        {
            luu = newq.value(4).toString();//luu gia ma tinh thanh
        }
        ui->comboBox_tp->setCurrentIndex(ui->comboBox_tp->findData(luu));
        ui->comboBox_qh->setCurrentIndex(ui->comboBox_qh->findData(disid));
        ui->comboBox_xp->setCurrentIndex(ui->comboBox_xp->findData(madc));
        break;
    }
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    //neu index thay doi bang = 1 thi chon load lop + ten sv vao combobx
    if(index ==1 )
    {
        //cac ham tinh date
        date = QDate::currentDate();
        ui->dateEdit_ngadk->setDate(date);
        ui->dateEdit_thoihan->setDate(date.addYears(1));//thoi han ddang ky hop dong la 1 nam
        QRegExp rxdk("[0,1,2,3][0-9]/[0,1][0-9]/[2][0]\\d{1,2}");
        QRegExpValidator *validator = new QRegExpValidator(rxdk,this);
        ui->lineEdit_Ngaydi->setValidator(validator);
        ui->spinBox_2->setValue(ui->spinBox->value());
        modelHopdong.setQuery("select distinct SINH_VIEN.ho_ten as '"+QString::fromUtf8("Ho ten")+"',HOP_DONG.tg_toi_da as '"+QString::fromUtf8("Thoi hang")+"' from SINH_VIEN, HOP_DONG where SINH_VIEN.mssv = HOP_DONG.mssv");

        ui->treeView->setModel(&modelHopdong);
        ui->comboxLop_tabHopdong->clear();
        newq.exec("select * from LOP");
        while(newq.next())
        {
            ui->comboxLop_tabHopdong->addItem(newq.value(2).toString(),newq.value(0).toString());
        }
        //lay thong tin phong
        ui->comboBoxPhong_tabHD->clear();
        newq.exec("select * from PHONG");
        while (newq.next()) {
            ui->comboBoxPhong_tabHD->addItem(newq.value(0).toString());
        }
    }
    //load tab xl thanh toan
    if(index == 2)
    {
        ui->spinBox_3->setValue(ui->spinBox->value());
        modelTT.setQuery("select distinct HOP_DONG.mssv,PT_TIEN_TRO.ngay from PT_TIEN_TRO left join HOP_DONG on PT_TIEN_TRO.stt_hd = HOP_DONG.stt_hd limit 0,"+QString::number(ui->spinBox_3->value()));
        ui->treeView_thanhtoan->setModel(&modelTT);
    }
}


void MainWindow::loadtabSV(const QModelIndex &index)
{
    newq.exec("select * from SINH_VIEN where mssv = '"+ui->listView_sv->currentIndex().sibling(index.row(),0).data().toString()+"'");
    if(newq.next())
    {
        tempst = newq.value(1).toString();
        ui->lineEdit_sdtSV->setText(newq.value(3).toString());
        ui->lineEdit_hotenSV->setText(newq.value(2).toString());
        ui->lineEdit_mssvSV->setText(newq.value(0).toString());
        ui->checkBox_gt->setChecked(newq.value(4).toBool());
        ui->dateEdit_ngaysinh->setDate(QDate::fromString(newq.value(5).toString(),"yyyy-MM-dd"));
        if(newq.value(6).toString().isEmpty() || newq.value(6).toString().isNull())
        {
            ui->label_pic->setText("Khong co");
        }
        else
        {
        pix.load(newq.value(6).toString());
        ui->label_pic->setPixmap(pix.scaled(120,140,Qt::KeepAspectRatio));
        }
        //truy van lop va set no thanh active
        newq.exec("SELECT * FROM `LOP`");
        ui->comboBox_lopSv->clear();
        while(newq.next())
        {
            ui->comboBox_lopSv->addItem(newq.value(2).toString(),newq.value(0).toString());
        }
        ui->comboBox_lopSv->setCurrentIndex(ui->comboBox_lopSv->findData(tempst));
        //truy van dia chi
        ui->comboBox_xp->clear();
        newq.exec("select * from DC_CUASV where mssv = '"+ui->listView_sv->currentIndex().sibling(index.row(),0).data().toString()+"'");
        if(newq.next())
        {
            ui->lineEdit_diachi->clear();
            ui->lineEdit_diachi->setText(newq.value(1).toString());
            if(newq.value(3).isNull())
            {
                setcombobox(newq.value(4).toString());
            }
            else
            {
                if(newq.value(2).isNull())
                {
                    setcombobox(newq.value(3).toString());
                }
                else
                {
                    setcombobox(newq.value(2).toString());
                }
            }
        }
    }
    clickidxSV = index;
}


void MainWindow::on_toolButton_clicked()
{
    linkimg = QFileDialog::getOpenFileName(this,tr("Open jpg file"),"/home/xdien/ProjectsQT/qlsv_ktx/hinhThe/",tr("IMG file (*.jpg *.png)"));
    if(!linkimg.isNull())
    {
        pix.load(linkimg);
        ui->label_pic->setPixmap(pix.scaled(120,140,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_actionXemtheophong_triggered()
{
    Form_listSTbyPhong *xemmoi = new Form_listSTbyPhong();
    xemmoi->show();
}

void MainWindow::on_action_i_t_ng_m_i_triggered()
{
    editDatatable dtmoi(this,"DOI_TUONG");
    dtmoi.exec();
}

void MainWindow::on_actionPh_ng_m_i_triggered()
{
    editDatatable phongmoi(this,"PHONG");
    phongmoi.exec();
}

void MainWindow::on_actionL_p_triggered()
{
    editDatatable lop(this,"LOP");
    lop.exec();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    modelTT.setQuery("select HOP_DONG.mssv,ngay from PT_TIEN_TRO left join HOP_DONG on HOP_DONG.stt_hd = PT_TIEN_TRO.stt_hd " \
                    "where HOP_DONG.mssv like '%"+arg1+"%' order by ngay desc");
    qDebug()<<modelTT.lastError().text();
}


void MainWindow::on_treeView_thanhtoan_clicked(const QModelIndex &index)
{

    newq.exec("select SINH_VIEN.mssv,SINH_VIEN.ho_ten,HOP_DONG.ma_phong,HOP_DONG.stt_hd,PT_TIEN_TRO.stt_pttro,PT_TIEN_TRO.ngay,PT_TIEN_TRO.tong_tien from PT_TIEN_TRO "\
              "left join HOP_DONG "\
              "on PT_TIEN_TRO.stt_hd = HOP_DONG.stt_hd "\
              "left join SINH_VIEN "\
              "on SINH_VIEN.mssv = HOP_DONG.mssv where HOP_DONG.mssv= '"+index.sibling(index.row(),0).data().toString()+"' "\
               "and PT_TIEN_TRO.ngay = '"+index.sibling(index.row(),1).data().toString()+"'");
    if(newq.next())
    {
        ui->label_ten->setText(newq.value(1).toString());
        ui->spinBox_PHONG->setValue(newq.value(2).toInt());
        //ui->spinBox_DIEN->setValue(newq.value(3).toInt());
        //ui->spinBox_NUOC->setValue(newq.value(4).toInt());
        ui->dateEdit_quy->setDate(newq.value(5).toDate());
        ui->label_tien->setText(newq.value(6).toString());
        ui->label_mssvTT->setText(newq.value(0).toString());
        ui->label_sttpt->setText(newq.value(4).toString());
        ui->label_stthd->setText(newq.value(3).toString());
        //set quy
        int thang = ui->dateEdit_quy->date().month();
        if(thang <= 3)
        {
             ui->label_quy->setText("1");
        }
        else
        {
            if(thang<=6)
                ui->label_quy->setText("2");
            else
            {
                if(thang<=9)
                    ui->label_quy->setText("3");
                else
                    ui->label_quy->setText("4");
            }
        }
    }
}

void MainWindow::on_actionT_i_s_n_triggered()
{
    editDatatable tsmoi(this,"TAI_SAN");
    tsmoi.exec();
}

void MainWindow::on_actionTh_ng_k_theo_ti_nh_tha_nh_triggered()
{
    dialog_chonTP tinhtp(this);
    tinhtp.exec();
}

void MainWindow::on_actionKhoa_triggered()
{
    dialog_chonKhoa chonkhoa(this);
    chonkhoa.exec();
}

void MainWindow::on_actionTheo_nga_nh_triggered()
{
    dialogChonNganh nganhmoi(this);
    nganhmoi.exec();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    QSettings p_display("connect.conf",QSettings::IniFormat);
    p_display.beginGroup("Settings");
    p_display.setValue("p_display",arg1);
}

void MainWindow::on_pushButton_7_clicked()
{
    p_display(ui->spinBox->value(),1,"SINH_VIEN");
}

void MainWindow::on_pushButton_6_clicked()
{
    if(giatrispibox >= 0)
    {
        qDebug()<<giatrispibox;
        p_display(ui->spinBox->value(),2,"SINH_VIEN");
    }
}
void MainWindow::p_display(const int donghienthi, int toantu, const QString tablename)
{
    switch (toantu) {
    case 1://gia tri tang len
    {
        giatrispibox = giatrispibox + donghienthi;
        modelInfosv.setQuery("select * from "+tablename+" limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
    }
        break;
    case 2://giam gia tri
    {
        giatrispibox = giatrispibox - donghienthi;
        modelInfosv.setQuery("select * from "+tablename+" limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
    }
        break;
    case 3://end
    {
        newq.exec("select count(*) from "+tablename+"");
        if(newq.next())
        {
            giatrispibox =  newq.value(0).toInt() - (newq.value(0).toInt() % donghienthi);
            qDebug()<<giatrispibox;
            modelInfosv.setQuery("select * from "+tablename+" limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
        }
    }
        break;
    case 4://start
    {
        giatrispibox = 0;
        modelInfosv.setQuery("select * from "+tablename+" limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
    }
    default:
        break;
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    p_display(ui->spinBox->value(),3,"SINH_VIEN");
}

void MainWindow::on_pushButton_2_clicked()
{
    p_display(ui->spinBox->value(),4,"SINH_VIEN");
}
//p_displayHD
void MainWindow::p_displayHD(const int donghienthi, int toantu)
{
    switch (toantu) {
    case 1://gia tri tang len
    {
        giatrispibox = giatrispibox + donghienthi;
        modelHopdong.setQuery("select SINH_VIEN.ho_ten as '"+QString::fromUtf8("Ho ten")+"',HOP_DONG.tg_toi_da as '"+QString::fromUtf8("Thoi hang")+"' from SINH_VIEN, HOP_DONG where SINH_VIEN.mssv = HOP_DONG.mssv limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
    }
        break;
    case 2://giam gia tri
    {
        giatrispibox = giatrispibox - donghienthi;
        modelHopdong.setQuery("select SINH_VIEN.ho_ten as '"+QString::fromUtf8("Ho ten")+"',HOP_DONG.tg_toi_da as '"+QString::fromUtf8("Thoi hang")+"' from SINH_VIEN, HOP_DONG where SINH_VIEN.mssv = HOP_DONG.mssv limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
    }
        break;
    case 3://end
    {
        newq.exec("select count(*) from SINH_VIEN, HOP_DONG where SINH_VIEN.mssv = HOP_DONG.mssv");
        if(newq.next())
        {
            giatrispibox =  newq.value(0).toInt() - (newq.value(0).toInt() % donghienthi);
            qDebug()<<giatrispibox;
            modelHopdong.setQuery("select SINH_VIEN.ho_ten as '"+QString::fromUtf8("Ho ten")+"',HOP_DONG.tg_toi_da as '"+QString::fromUtf8("Thoi hang")+"' from SINH_VIEN, HOP_DONG where SINH_VIEN.mssv = HOP_DONG.mssv limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
        }
    }
        break;
    case 4://start
    {
        giatrispibox = 0;
        modelHopdong.setQuery("select SINH_VIEN.ho_ten as '"+QString::fromUtf8("Ho ten")+"',HOP_DONG.tg_toi_da as '"+QString::fromUtf8("Thoi hang")+"' from SINH_VIEN, HOP_DONG where SINH_VIEN.mssv = HOP_DONG.mssv limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
    }
    default:
        break;
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    p_displayHD(ui->spinBox_2->value(),4);
}


void MainWindow::on_pushButton_12_clicked()
{
    p_displayHD(ui->spinBox_2->value(),2);
}



void MainWindow::on_pushButton_9_clicked()
{
    p_displayHD(ui->spinBox_2->value(),1);
}



void MainWindow::on_pushButton_10_clicked()
{
    p_displayHD(ui->spinBox_2->value(),3);
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    QSettings p_display("connect.conf",QSettings::IniFormat);
    p_display.beginGroup("Settings");
    p_display.setValue("p_display",arg1);
}

void MainWindow::p_displayTT(const int donghienthi, int toantu)
{
    switch (toantu) {
    case 1://gia tri tang len
    {
        giatrispibox = giatrispibox + donghienthi;
        modelTT.setQuery("select * from PT_TIEN_TRO left join HOP_DONG on PT_TIEN_TRO.stt_hd = HOP_DONG.stt_hd " \
                              " limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
    }
        break;
    case 2://giam gia tri
    {
        giatrispibox = giatrispibox - donghienthi;
        modelTT.setQuery("select * from PT_TIEN_TRO left join HOP_DONG on PT_TIEN_TRO.stt_hd = HOP_DONG.stt_hd " \
                              " limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
    }
        break;
    case 3://end
    {
        newq.exec("select count(*) from PT_TIEN_TRO left join HOP_DONG on PT_TIEN_TRO.stt_hd = HOP_DONG.stt_hd");
        if(newq.next())
        {
            giatrispibox =  newq.value(0).toInt() - (newq.value(0).toInt() % donghienthi);
            qDebug()<<giatrispibox;
            modelTT.setQuery("select * from PT_TIEN_TRO left join HOP_DONG on PT_TIEN_TRO.stt_hd = HOP_DONG.stt_hd " \
                                  " limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
        }
    }
        break;
    case 4://start
    {
        giatrispibox = 0;
        modelTT.setQuery("select * from PT_TIEN_TRO left join HOP_DONG on PT_TIEN_TRO.stt_hd = HOP_DONG.stt_hd " \
                              " limit "+QString::number(giatrispibox)+","+QString::number(donghienthi));
    }
    default:
        break;
    }
}


void MainWindow::on_pushButton_14_clicked()
{
    p_displayTT(ui->spinBox_3->value(),1);
}

void MainWindow::on_pushButton_13_clicked()
{
    p_displayTT(ui->spinBox_3->value(),3);
}

void MainWindow::on_pushButton_15_clicked()
{
    p_displayTT(ui->spinBox_3->value(),2);
}

void MainWindow::on_pushButton_16_clicked()
{
    p_displayTT(ui->spinBox_3->value(),4);
}

void MainWindow::on_actionQuy_triggered()
{
    dialog_chonquy chonquy(this);
    chonquy.exec();
}

void MainWindow::on_dateEdit_ngadk_dateChanged(const QDate &date)
{
    ui->dateEdit_thoihan->setDate(date.addYears(1));
}
