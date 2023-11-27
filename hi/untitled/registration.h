#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "ui_registration.h"
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QRegularExpression>

#include "confectionery.h"
#include "confectionerystoreinformationsystem.h"

class Validation{
public:
    static bool isValidName(const QString& name);
    static bool isValidSurname(const QString& surname);
    static bool isValidLogin(const QString& login);
    static bool isValidPassword(const QString& password);
};


namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);


    registration(confectioneryStoreInformationSystem *ConfectioneryStoreInformationSystem, QWidget *parent = nullptr);

    ~registration();

    bool isLoginUnique(const QString& login);

private slots:
    void on_pushButton_clicked();

private:
    Ui::registration *ui;

    confectioneryStoreInformationSystem *ConfectioneryStoreInformationSystem;

};

#endif // REGISTRATION_H
