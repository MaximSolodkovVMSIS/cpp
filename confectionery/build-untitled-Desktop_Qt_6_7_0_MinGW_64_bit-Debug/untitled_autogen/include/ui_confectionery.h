/********************************************************************************
** Form generated from reading UI file 'confectionery.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFECTIONERY_H
#define UI_CONFECTIONERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_confectionery
{
public:
    QTableView *tableView;
    QPushButton *addProduct;
    QPushButton *removeProduct;
    QPushButton *addToOrder;
    QPushButton *myOrder;
    QPushButton *historyOfOrders;

    void setupUi(QDialog *confectionery)
    {
        if (confectionery->objectName().isEmpty())
            confectionery->setObjectName("confectionery");
        confectionery->resize(800, 500);
        tableView = new QTableView(confectionery);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(50, 100, 511, 321));
        addProduct = new QPushButton(confectionery);
        addProduct->setObjectName("addProduct");
        addProduct->setGeometry(QRect(550, 450, 80, 24));
        removeProduct = new QPushButton(confectionery);
        removeProduct->setObjectName("removeProduct");
        removeProduct->setGeometry(QRect(660, 450, 80, 24));
        addToOrder = new QPushButton(confectionery);
        addToOrder->setObjectName("addToOrder");
        addToOrder->setGeometry(QRect(600, 120, 161, 24));
        myOrder = new QPushButton(confectionery);
        myOrder->setObjectName("myOrder");
        myOrder->setGeometry(QRect(600, 160, 161, 24));
        historyOfOrders = new QPushButton(confectionery);
        historyOfOrders->setObjectName("historyOfOrders");
        historyOfOrders->setGeometry(QRect(40, 440, 111, 24));

        retranslateUi(confectionery);

        QMetaObject::connectSlotsByName(confectionery);
    } // setupUi

    void retranslateUi(QDialog *confectionery)
    {
        confectionery->setWindowTitle(QCoreApplication::translate("confectionery", "Dialog", nullptr));
        addProduct->setText(QCoreApplication::translate("confectionery", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        removeProduct->setText(QCoreApplication::translate("confectionery", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        addToOrder->setText(QCoreApplication::translate("confectionery", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \320\267\320\260\320\272\320\260\320\267", nullptr));
        myOrder->setText(QCoreApplication::translate("confectionery", "\320\234\320\276\320\271 \320\267\320\260\320\272\320\260\320\267", nullptr));
        historyOfOrders->setText(QCoreApplication::translate("confectionery", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class confectionery: public Ui_confectionery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFECTIONERY_H
