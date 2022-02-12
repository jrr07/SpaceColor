/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *nothingButton;
    QPushButton *lineButton;
    QPushButton *circleButton;
    QPushButton *rectangleButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        nothingButton = new QPushButton(centralwidget);
        nothingButton->setObjectName(QString::fromUtf8("nothingButton"));
        nothingButton->setGeometry(QRect(10, 10, 75, 23));
        lineButton = new QPushButton(centralwidget);
        lineButton->setObjectName(QString::fromUtf8("lineButton"));
        lineButton->setGeometry(QRect(90, 10, 75, 23));
        circleButton = new QPushButton(centralwidget);
        circleButton->setObjectName(QString::fromUtf8("circleButton"));
        circleButton->setGeometry(QRect(170, 10, 75, 23));
        rectangleButton = new QPushButton(centralwidget);
        rectangleButton->setObjectName(QString::fromUtf8("rectangleButton"));
        rectangleButton->setGeometry(QRect(250, 10, 75, 23));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        nothingButton->setText(QApplication::translate("MainWindow", "nothing", nullptr));
        lineButton->setText(QApplication::translate("MainWindow", "line", nullptr));
        circleButton->setText(QApplication::translate("MainWindow", "circle", nullptr));
        rectangleButton->setText(QApplication::translate("MainWindow", "rectangle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
