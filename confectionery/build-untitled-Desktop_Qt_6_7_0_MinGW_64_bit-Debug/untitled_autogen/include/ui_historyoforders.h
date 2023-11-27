/********************************************************************************
** Form generated from reading UI file 'historyoforders.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYOFORDERS_H
#define UI_HISTORYOFORDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_HistoryOfOrders
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *HistoryOfOrders)
    {
        if (HistoryOfOrders->objectName().isEmpty())
            HistoryOfOrders->setObjectName("HistoryOfOrders");
        HistoryOfOrders->resize(400, 300);
        textBrowser = new QTextBrowser(HistoryOfOrders);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(40, 40, 300, 200));

        retranslateUi(HistoryOfOrders);

        QMetaObject::connectSlotsByName(HistoryOfOrders);
    } // setupUi

    void retranslateUi(QDialog *HistoryOfOrders)
    {
        HistoryOfOrders->setWindowTitle(QCoreApplication::translate("HistoryOfOrders", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryOfOrders: public Ui_HistoryOfOrders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYOFORDERS_H
