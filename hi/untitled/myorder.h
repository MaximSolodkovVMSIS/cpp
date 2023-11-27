#ifndef MYORDER_H
#define MYORDER_H

#include <QDialog>
#include <QFile>
#include <QDateTime>
#include <QMessageBox>
#include <QTextStream>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QHeaderView>

#include "user.h"


namespace Ui {
class MyOrder;
}

class MyOrder : public QDialog
{
    Q_OBJECT

public:
    bool readProdutsFromFile();
    void saveOrderToLogFile(const QString& login);
    void removeRowFromFile(const QStringList &rowData);
    explicit MyOrder(const QString& login, QWidget *parent = nullptr);
    ~MyOrder();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MyOrder *ui;
    User user;
};

#endif // MYORDER_H
