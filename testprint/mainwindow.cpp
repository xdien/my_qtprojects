/***************************************************************************
 *   App QT                                                                 *
 *         										                            *
 *                                                                          *
 *   bdienw@gmail.com                  		                                *
 *   2014                                                                 *
 ***************************************************************************/

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

void MainWindow::on_pushButton_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
       printer.setPaperSize(QPrinter::A4);
       printer.setOrientation(QPrinter::Portrait);
       printer.setFullPage(true);

       QPrintPreviewDialog *printPreview = new QPrintPreviewDialog(&printer);
       connect(printPreview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));

       printPreview->setWindowTitle("Preview Dialog");
       Qt::WindowFlags flags(Qt::WindowTitleHint);
       printPreview->setWindowFlags(flags);
       printPreview->exec();
}
void MainWindow::print(QPrinter *printer)
{
    QPainter painter(printer);
     painter.drawText(1500,5007,"asdas sda d asd ad asd sad asd as dsad");
}
