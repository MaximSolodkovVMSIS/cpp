/********************************************************************************
** Form generated from reading UI file 'userdatabase.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDATABASE_H
#define UI_USERDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDatabase
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButtonSave;

    void setupUi(QDialog *UserDatabase)
    {
        if (UserDatabase->objectName().isEmpty())
            UserDatabase->setObjectName("UserDatabase");
        UserDatabase->resize(497, 300);
        tableWidget = new QTableWidget(UserDatabase);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(40, 40, 417, 200));
        pushButtonSave = new QPushButton(UserDatabase);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setGeometry(QRect(360, 260, 80, 24));

        retranslateUi(UserDatabase);

        QMetaObject::connectSlotsByName(UserDatabase);
    } // setupUi

    void retranslateUi(QDialog *UserDatabase)
    {
        UserDatabase->setWindowTitle(QCoreApplication::translate("UserDatabase", "Dialog", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("UserDatabase", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDatabase: public Ui_UserDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDATABASE_H
