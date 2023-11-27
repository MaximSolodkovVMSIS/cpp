/********************************************************************************
** Form generated from reading UI file 'myorder.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYORDER_H
#define UI_MYORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_MyOrder
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;

    void setupUi(QDialog *MyOrder)
    {
        if (MyOrder->objectName().isEmpty())
            MyOrder->setObjectName("MyOrder");
        MyOrder->resize(500, 350);
        pushButton = new QPushButton(MyOrder);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 290, 80, 24));
        pushButton_2 = new QPushButton(MyOrder);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(380, 290, 80, 24));
        tableWidget = new QTableWidget(MyOrder);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(50, 50, 400, 200));

        retranslateUi(MyOrder);

        QMetaObject::connectSlotsByName(MyOrder);
    } // setupUi

    void retranslateUi(QDialog *MyOrder)
    {
        MyOrder->setWindowTitle(QCoreApplication::translate("MyOrder", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("MyOrder", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MyOrder", "\320\232\321\203\320\277\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyOrder: public Ui_MyOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYORDER_H
