#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>
#include "user.h"

namespace Ui {
class Description;
}

class Description : public QDialog
{
    Q_OBJECT

public:
    int getID();
    void setID(int id);
    explicit Description(const QString& login, const QString& Role,QSqlTableModel* model, int productId, QWidget *parent = nullptr);
    ~Description();

private slots:
    void on_saveBut_clicked();

private:
    int productId;
    User user;
    QString Role;
    Ui::Description *ui;
};

#endif // DESCRIPTION_H
