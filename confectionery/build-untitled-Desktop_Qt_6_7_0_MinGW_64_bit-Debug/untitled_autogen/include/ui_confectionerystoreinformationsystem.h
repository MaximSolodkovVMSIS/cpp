/********************************************************************************
** Form generated from reading UI file 'confectionerystoreinformationsystem.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFECTIONERYSTOREINFORMATIONSYSTEM_H
#define UI_CONFECTIONERYSTOREINFORMATIONSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_confectioneryStoreInformationSystem
{
public:
    QWidget *centralwidget;
    QPushButton *logButton;
    QPushButton *regButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *confectioneryStoreInformationSystem)
    {
        if (confectioneryStoreInformationSystem->objectName().isEmpty())
            confectioneryStoreInformationSystem->setObjectName("confectioneryStoreInformationSystem");
        confectioneryStoreInformationSystem->resize(800, 400);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(confectioneryStoreInformationSystem->sizePolicy().hasHeightForWidth());
        confectioneryStoreInformationSystem->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(confectioneryStoreInformationSystem);
        centralwidget->setObjectName("centralwidget");
        logButton = new QPushButton(centralwidget);
        logButton->setObjectName("logButton");
        logButton->setGeometry(QRect(230, 160, 340, 60));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        logButton->setFont(font);
        regButton = new QPushButton(centralwidget);
        regButton->setObjectName("regButton");
        regButton->setGeometry(QRect(230, 240, 340, 60));
        regButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 50, 400, 100));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 100));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        confectioneryStoreInformationSystem->setCentralWidget(centralwidget);
        menubar = new QMenuBar(confectioneryStoreInformationSystem);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        confectioneryStoreInformationSystem->setMenuBar(menubar);
        statusbar = new QStatusBar(confectioneryStoreInformationSystem);
        statusbar->setObjectName("statusbar");
        confectioneryStoreInformationSystem->setStatusBar(statusbar);

        retranslateUi(confectioneryStoreInformationSystem);

        QMetaObject::connectSlotsByName(confectioneryStoreInformationSystem);
    } // setupUi

    void retranslateUi(QMainWindow *confectioneryStoreInformationSystem)
    {
        confectioneryStoreInformationSystem->setWindowTitle(QCoreApplication::translate("confectioneryStoreInformationSystem", "confectioneryStoreInformationSystem", nullptr));
        logButton->setText(QCoreApplication::translate("confectioneryStoreInformationSystem", "Login", nullptr));
        regButton->setText(QCoreApplication::translate("confectioneryStoreInformationSystem", "Registration", nullptr));
        label->setText(QCoreApplication::translate("confectioneryStoreInformationSystem", "Select the authorization method", nullptr));
    } // retranslateUi

};

namespace Ui {
    class confectioneryStoreInformationSystem: public Ui_confectioneryStoreInformationSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFECTIONERYSTOREINFORMATIONSYSTEM_H
