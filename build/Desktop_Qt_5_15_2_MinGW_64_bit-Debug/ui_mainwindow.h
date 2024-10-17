/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *btnEqual;
    QPushButton *btnNum5;
    QPushButton *btnClear;
    QPushButton *btnNum1;
    QPushButton *btnPoint;
    QPushButton *btnNum9;
    QPushButton *btnNum4;
    QLineEdit *display;
    QPushButton *btnNum6;
    QPushButton *btnClearE;
    QPushButton *btnNum0;
    QPushButton *btnSquare;
    QPushButton *btnDivide;
    QPushButton *btnPlus;
    QPushButton *btnDelete;
    QPushButton *btnNum3;
    QPushButton *btnPeriod;
    QPushButton *btnMutiple;
    QPushButton *btnPlusOrSur;
    QPushButton *btnNum2;
    QPushButton *btnNum8;
    QPushButton *btnSqart;
    QPushButton *btnSub;
    QPushButton *btnPercentage;
    QPushButton *btnNum7;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(543, 324);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(255,255,255);\n"
"	font: 20pt \"Microsoft YaHei UI\";\n"
"	color:black;\n"
"	border-radius:5px;\n"
"	margin:2px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:#faeeef;\n"
"	color:black;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color:#e9bbc0;\n"
"	color:black;\n"
"}\n"
"QLineEdit{\n"
"	font-size: 30pt ;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnEqual = new QPushButton(centralwidget);
        btnEqual->setObjectName(QString::fromUtf8("btnEqual"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnEqual->sizePolicy().hasHeightForWidth());
        btnEqual->setSizePolicy(sizePolicy);
        btnEqual->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnEqual, 6, 3, 1, 1);

        btnNum5 = new QPushButton(centralwidget);
        btnNum5->setObjectName(QString::fromUtf8("btnNum5"));
        sizePolicy.setHeightForWidth(btnNum5->sizePolicy().hasHeightForWidth());
        btnNum5->setSizePolicy(sizePolicy);
        btnNum5->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnNum5, 4, 1, 1, 1);

        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        sizePolicy.setHeightForWidth(btnClear->sizePolicy().hasHeightForWidth());
        btnClear->setSizePolicy(sizePolicy);
        btnClear->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnClear, 1, 2, 1, 1);

        btnNum1 = new QPushButton(centralwidget);
        btnNum1->setObjectName(QString::fromUtf8("btnNum1"));
        sizePolicy.setHeightForWidth(btnNum1->sizePolicy().hasHeightForWidth());
        btnNum1->setSizePolicy(sizePolicy);
        btnNum1->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnNum1, 5, 0, 1, 1);

        btnPoint = new QPushButton(centralwidget);
        btnPoint->setObjectName(QString::fromUtf8("btnPoint"));
        sizePolicy.setHeightForWidth(btnPoint->sizePolicy().hasHeightForWidth());
        btnPoint->setSizePolicy(sizePolicy);
        btnPoint->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnPoint, 6, 2, 1, 1);

        btnNum9 = new QPushButton(centralwidget);
        btnNum9->setObjectName(QString::fromUtf8("btnNum9"));
        sizePolicy.setHeightForWidth(btnNum9->sizePolicy().hasHeightForWidth());
        btnNum9->setSizePolicy(sizePolicy);
        btnNum9->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnNum9, 3, 2, 1, 1);

        btnNum4 = new QPushButton(centralwidget);
        btnNum4->setObjectName(QString::fromUtf8("btnNum4"));
        sizePolicy.setHeightForWidth(btnNum4->sizePolicy().hasHeightForWidth());
        btnNum4->setSizePolicy(sizePolicy);
        btnNum4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnNum4, 4, 0, 1, 1);

        display = new QLineEdit(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(display->sizePolicy().hasHeightForWidth());
        display->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        display->setFont(font);
        display->setCursor(QCursor(Qt::BlankCursor));
        display->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(display, 0, 0, 1, 4);

        btnNum6 = new QPushButton(centralwidget);
        btnNum6->setObjectName(QString::fromUtf8("btnNum6"));
        sizePolicy.setHeightForWidth(btnNum6->sizePolicy().hasHeightForWidth());
        btnNum6->setSizePolicy(sizePolicy);
        btnNum6->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnNum6, 4, 2, 1, 1);

        btnClearE = new QPushButton(centralwidget);
        btnClearE->setObjectName(QString::fromUtf8("btnClearE"));
        sizePolicy.setHeightForWidth(btnClearE->sizePolicy().hasHeightForWidth());
        btnClearE->setSizePolicy(sizePolicy);
        btnClearE->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnClearE, 1, 1, 1, 1);

        btnNum0 = new QPushButton(centralwidget);
        btnNum0->setObjectName(QString::fromUtf8("btnNum0"));
        sizePolicy.setHeightForWidth(btnNum0->sizePolicy().hasHeightForWidth());
        btnNum0->setSizePolicy(sizePolicy);
        btnNum0->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnNum0, 6, 1, 1, 1);

        btnSquare = new QPushButton(centralwidget);
        btnSquare->setObjectName(QString::fromUtf8("btnSquare"));
        sizePolicy.setHeightForWidth(btnSquare->sizePolicy().hasHeightForWidth());
        btnSquare->setSizePolicy(sizePolicy);
        btnSquare->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnSquare, 2, 1, 1, 1);

        btnDivide = new QPushButton(centralwidget);
        btnDivide->setObjectName(QString::fromUtf8("btnDivide"));
        sizePolicy.setHeightForWidth(btnDivide->sizePolicy().hasHeightForWidth());
        btnDivide->setSizePolicy(sizePolicy);
        btnDivide->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnDivide, 2, 3, 1, 1);

        btnPlus = new QPushButton(centralwidget);
        btnPlus->setObjectName(QString::fromUtf8("btnPlus"));
        sizePolicy.setHeightForWidth(btnPlus->sizePolicy().hasHeightForWidth());
        btnPlus->setSizePolicy(sizePolicy);
        btnPlus->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnPlus, 5, 3, 1, 1);

        btnDelete = new QPushButton(centralwidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        sizePolicy.setHeightForWidth(btnDelete->sizePolicy().hasHeightForWidth());
        btnDelete->setSizePolicy(sizePolicy);
        btnDelete->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnDelete, 1, 3, 1, 1);

        btnNum3 = new QPushButton(centralwidget);
        btnNum3->setObjectName(QString::fromUtf8("btnNum3"));
        sizePolicy.setHeightForWidth(btnNum3->sizePolicy().hasHeightForWidth());
        btnNum3->setSizePolicy(sizePolicy);
        btnNum3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnNum3, 5, 2, 1, 1);

        btnPeriod = new QPushButton(centralwidget);
        btnPeriod->setObjectName(QString::fromUtf8("btnPeriod"));
        sizePolicy.setHeightForWidth(btnPeriod->sizePolicy().hasHeightForWidth());
        btnPeriod->setSizePolicy(sizePolicy);
        btnPeriod->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnPeriod, 2, 0, 1, 1);

        btnMutiple = new QPushButton(centralwidget);
        btnMutiple->setObjectName(QString::fromUtf8("btnMutiple"));
        sizePolicy.setHeightForWidth(btnMutiple->sizePolicy().hasHeightForWidth());
        btnMutiple->setSizePolicy(sizePolicy);
        btnMutiple->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnMutiple, 3, 3, 1, 1);

        btnPlusOrSur = new QPushButton(centralwidget);
        btnPlusOrSur->setObjectName(QString::fromUtf8("btnPlusOrSur"));
        sizePolicy.setHeightForWidth(btnPlusOrSur->sizePolicy().hasHeightForWidth());
        btnPlusOrSur->setSizePolicy(sizePolicy);
        btnPlusOrSur->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnPlusOrSur, 6, 0, 1, 1);

        btnNum2 = new QPushButton(centralwidget);
        btnNum2->setObjectName(QString::fromUtf8("btnNum2"));
        sizePolicy.setHeightForWidth(btnNum2->sizePolicy().hasHeightForWidth());
        btnNum2->setSizePolicy(sizePolicy);
        btnNum2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnNum2, 5, 1, 1, 1);

        btnNum8 = new QPushButton(centralwidget);
        btnNum8->setObjectName(QString::fromUtf8("btnNum8"));
        sizePolicy.setHeightForWidth(btnNum8->sizePolicy().hasHeightForWidth());
        btnNum8->setSizePolicy(sizePolicy);
        btnNum8->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnNum8, 3, 1, 1, 1);

        btnSqart = new QPushButton(centralwidget);
        btnSqart->setObjectName(QString::fromUtf8("btnSqart"));
        sizePolicy.setHeightForWidth(btnSqart->sizePolicy().hasHeightForWidth());
        btnSqart->setSizePolicy(sizePolicy);
        btnSqart->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnSqart, 2, 2, 1, 1);

        btnSub = new QPushButton(centralwidget);
        btnSub->setObjectName(QString::fromUtf8("btnSub"));
        sizePolicy.setHeightForWidth(btnSub->sizePolicy().hasHeightForWidth());
        btnSub->setSizePolicy(sizePolicy);
        btnSub->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnSub, 4, 3, 1, 1);

        btnPercentage = new QPushButton(centralwidget);
        btnPercentage->setObjectName(QString::fromUtf8("btnPercentage"));
        sizePolicy.setHeightForWidth(btnPercentage->sizePolicy().hasHeightForWidth());
        btnPercentage->setSizePolicy(sizePolicy);
        btnPercentage->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnPercentage, 1, 0, 1, 1);

        btnNum7 = new QPushButton(centralwidget);
        btnNum7->setObjectName(QString::fromUtf8("btnNum7"));
        sizePolicy.setHeightForWidth(btnNum7->sizePolicy().hasHeightForWidth());
        btnNum7->setSizePolicy(sizePolicy);
        btnNum7->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout->addWidget(btnNum7, 3, 0, 1, 1);

        gridLayout->setRowStretch(0, 2);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setRowStretch(5, 1);
        gridLayout->setRowStretch(6, 1);

        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnEqual->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        btnNum5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        btnNum1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btnPoint->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        btnNum9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btnNum4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        display->setText(QString());
        display->setPlaceholderText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnNum6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btnClearE->setText(QCoreApplication::translate("MainWindow", "CE", nullptr));
        btnNum0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnSquare->setText(QCoreApplication::translate("MainWindow", "x^2", nullptr));
        btnDivide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        btnPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        btnNum3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btnPeriod->setText(QCoreApplication::translate("MainWindow", "1/x", nullptr));
        btnMutiple->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        btnPlusOrSur->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        btnNum2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btnNum8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btnSqart->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        btnSub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btnPercentage->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        btnNum7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
