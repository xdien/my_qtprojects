
#include <QtGui>
#include <QtSql>

// #include "../connection.h"

 void initializeModel(QSqlTableModel *model)
 {
     model->setTable("person");
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);
     model->select();

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
 }

 QTableView *createView(QSqlTableModel *model, const QString &title = "")
 {
     QTableView *view = new QTableView;
     view->setModel(model);
     view->setWindowTitle(title);
     return view;
 }
