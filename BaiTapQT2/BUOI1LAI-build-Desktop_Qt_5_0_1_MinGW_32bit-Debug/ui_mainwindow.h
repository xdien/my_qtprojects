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
    QPushButton *BtnDrawSimple;
    QPushButton *pushButton_3;
    QPushButton *NgoiNha1;
    QPushButton *pushButton_2;
    QPushButton *ThaiCuc2;
    QPushButton *pushButton;
    QPushButton *TamGiac;
    QPushButton *NgoiNhaRua;
    QPushButton *RuaNguoc;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(795, 473);
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
        BtnDrawSimple = new QPushButton(GraphicsControl);
        BtnDrawSimple->setObjectName(QStringLiteral("BtnDrawSimple"));

        verticalLayout->addWidget(BtnDrawSimple);

        pushButton_3 = new QPushButton(GraphicsControl);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        NgoiNha1 = new QPushButton(GraphicsControl);
        NgoiNha1->setObjectName(QStringLiteral("NgoiNha1"));

        verticalLayout->addWidget(NgoiNha1);

        pushButton_2 = new QPushButton(GraphicsControl);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        ThaiCuc2 = new QPushButton(GraphicsControl);
        ThaiCuc2->setObjectName(QStringLiteral("ThaiCuc2"));

        verticalLayout->addWidget(ThaiCuc2);

        pushButton = new QPushButton(GraphicsControl);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        TamGiac = new QPushButton(GraphicsControl);
        TamGiac->setObjectName(QStringLiteral("TamGiac"));

        verticalLayout->addWidget(TamGiac);

        NgoiNhaRua = new QPushButton(GraphicsControl);
        NgoiNhaRua->setObjectName(QStringLiteral("NgoiNhaRua"));

        verticalLayout->addWidget(NgoiNhaRua);

        RuaNguoc = new QPushButton(GraphicsControl);
        RuaNguoc->setObjectName(QStringLiteral("RuaNguoc"));

        verticalLayout->addWidget(RuaNguoc);


        horizontalLayout->addWidget(GraphicsControl);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        GraphicsControl->setTitle(QApplication::translate("MainWindow", "GraphicsMode", 0));
        BtnDrawSimple->setText(QApplication::translate("MainWindow", "HinhTronVaVuong", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "ThaiCucQuyen", 0));
        NgoiNha1->setText(QApplication::translate("MainWindow", "NgoiNhaTiHon", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "CoVua", 0));
        ThaiCuc2->setText(QApplication::translate("MainWindow", "ThaiCuc2", 0));
        pushButton->setText(QApplication::translate("MainWindow", "NgoiLang", 0));
        TamGiac->setText(QApplication::translate("MainWindow", "TamGiacConrua", 0));
        NgoiNhaRua->setText(QApplication::translate("MainWindow", "NgoiNhaRua", 0));
        RuaNguoc->setText(QApplication::translate("MainWindow", "RuaNguoc", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
