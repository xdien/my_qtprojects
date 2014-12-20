/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphics.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    graphics *GraphicsPresenter;
    QGroupBox *GraphicsControl;
    QVBoxLayout *verticalLayout;
    QPushButton *Baitap1;
    QPushButton *pushButton;
    QPushButton *Buoi3;
    QPushButton *Baitap11;
    QPushButton *Baitap2;
    QPushButton *Baitap22;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(699, 368);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        GraphicsPresenter = new graphics(centralWidget);
        GraphicsPresenter->setObjectName(QStringLiteral("GraphicsPresenter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GraphicsPresenter->sizePolicy().hasHeightForWidth());
        GraphicsPresenter->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(GraphicsPresenter);

        GraphicsControl = new QGroupBox(centralWidget);
        GraphicsControl->setObjectName(QStringLiteral("GraphicsControl"));
        verticalLayout = new QVBoxLayout(GraphicsControl);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Baitap1 = new QPushButton(GraphicsControl);
        Baitap1->setObjectName(QStringLiteral("Baitap1"));

        verticalLayout->addWidget(Baitap1);

        pushButton = new QPushButton(GraphicsControl);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        Buoi3 = new QPushButton(GraphicsControl);
        Buoi3->setObjectName(QStringLiteral("Buoi3"));

        verticalLayout->addWidget(Buoi3);

        Baitap11 = new QPushButton(GraphicsControl);
        Baitap11->setObjectName(QStringLiteral("Baitap11"));

        verticalLayout->addWidget(Baitap11);

        Baitap2 = new QPushButton(GraphicsControl);
        Baitap2->setObjectName(QStringLiteral("Baitap2"));

        verticalLayout->addWidget(Baitap2);

        Baitap22 = new QPushButton(GraphicsControl);
        Baitap22->setObjectName(QStringLiteral("Baitap22"));

        verticalLayout->addWidget(Baitap22);


        horizontalLayout->addWidget(GraphicsControl);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        GraphicsControl->setTitle(QApplication::translate("MainWindow", "GraphicsMode", 0));
        Baitap1->setText(QApplication::translate("MainWindow", "Hinhvuong", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Vidu", 0));
        Buoi3->setText(QApplication::translate("MainWindow", "Bai1", 0));
        Baitap11->setText(QApplication::translate("MainWindow", "TamGiac", 0));
        Baitap2->setText(QApplication::translate("MainWindow", "ConRua1", 0));
        Baitap22->setText(QApplication::translate("MainWindow", "PoLy", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
