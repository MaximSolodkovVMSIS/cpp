#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "confectionerystoreinformationsystem.h"
#include "ui_authorization.h"
#include "confectionery.h"

namespace Ui {
class authorization;
}

class authorization : public QDialog
{
    Q_OBJECT

public:
    explicit authorization(QWidget *parent = nullptr);

    authorization(confectioneryStoreInformationSystem *ConfectioneryStoreInformationSystem, QWidget *parent = nullptr);

    ~authorization();

private slots:
    void on_pushButton_clicked();

private:
    Ui::authorization *ui;

    confectioneryStoreInformationSystem *ConfectioneryStoreInformationSystem;
};

#endif // AUTHORIZATION_H
