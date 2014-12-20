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
    QPushButton *pushButton;
    QPushButton *DrawSimple;
    QPushButton *BaiTap5;
    QPushButton *BaiTap3;
    QPushButton *Bai6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(731, 382);
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
        pushButton = new QPushButton(GraphicsControl);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        DrawSimple = new QPushButton(GraphicsControl);
        DrawSimple->setObjectName(QStringLiteral("DrawSimple"));

        verticalLayout->addWidget(DrawSimple);

        BaiTap5 = new QPushButton(GraphicsControl);
        BaiTap5->setObjectName(QStringLiteral("BaiTap5"));

        verticalLayout->addWidget(BaiTap5);

        BaiTap3 = new QPushButton(GraphicsControl);
        BaiTap3->setObjectName(QStringLiteral("BaiTap3"));

        verticalLayout->addWidget(BaiTap3);

        Bai6 = new QPushButton(GraphicsControl);
        Bai6->setObjectName(QStringLiteral("Bai6"));

        verticalLayout->addWidget(Bai6);


        horizontalLayout->addWidget(GraphicsControl);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        GraphicsControl->setTitle(QApplication::translate("MainWindow", "GraphicsMode", 0));
        pushButton->setText(QApplication::translate("MainWindow", "BaiTap2", 0));
        DrawSimple->setText(QApplication::translate("MainWindow", "BaiTap1", 0));
        BaiTap5->setText(QApplication::translate("MainWindow", "NgoiNha", 0));
        BaiTap3->setText(QApplication::translate("MainWindow", "ChiecBanhHinhNguoi", 0));
        Bai6->setText(QApplication::translate("MainWindow", "ThaiCuc", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
