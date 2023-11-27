/********************************************************************************
** Form generated from reading UI file 'authorization.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATION_H
#define UI_AUTHORIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_authorization
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *password;

    void setupUi(QDialog *authorization)
    {
        if (authorization->objectName().isEmpty())
            authorization->setObjectName("authorization");
        authorization->resize(400, 300);
        groupBox = new QGroupBox(authorization);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 30, 300, 200));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 130, 141, 24));
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(12, 31, 271, 71));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        login = new QLineEdit(widget);
        login->setObjectName("login");

        horizontalLayout->addWidget(login);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        password = new QLineEdit(widget);
        password->setObjectName("password");
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(authorization);

        QMetaObject::connectSlotsByName(authorization);
    } // setupUi

    void retranslateUi(QDialog *authorization)
    {
        authorization->setWindowTitle(QCoreApplication::translate("authorization", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("authorization", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("authorization", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        label->setText(QCoreApplication::translate("authorization", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("authorization", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class authorization: public Ui_authorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATION_H
