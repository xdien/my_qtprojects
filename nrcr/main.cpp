#include "mainwindow.h"
#include <QApplication>
#include "ncurses.h"
#include "ncreport.h"
#include "ncreportpreviewwindow.h"
#include <QMessageBox>
#include <QtSql>

int main(int argc, char *argv[])

    {
        QApplication a(argc, argv);

        NCReport *report = new NCReport();

        report->setReportSource( NCReportSource::File ); // set report source type
        report->setReportFile("/home/xdien/ProjectsQT/qlsv_ktx/printHD.ncr"); //set the report filename fullpath or relative to dir
        report->addParameter("ten",QString::fromUtf8("Bùi xuân diễn"));
        report->addParameter("img_path","/home/xdien/ProjectsQT/qlsv_ktx/the_1.jpg");
        report->runReportToPreview(); // run to preview output
        //report->dataSource()

        // error handling
        if( report->hasError())
        {
            QMessageBox msgBox;
            msgBox.setText(QObject::tr("Report error: ") + report->lastErrorMsg());
            msgBox.exec();
        }
        else
        {
            // show preview
            NCReportPreviewWindow *pv = new NCReportPreviewWindow();    // create preview window
            pv->setOutput( (NCReportPreviewOutput*)report->output() );  // add output to the window
            pv->setReport(report);
            pv->setWindowModality(Qt::ApplicationModal );    // set modality
            pv->setAttribute( Qt::WA_DeleteOnClose );    // set attrib
            pv->exec();  // run like modal dialog
        }
        delete report;
    }
