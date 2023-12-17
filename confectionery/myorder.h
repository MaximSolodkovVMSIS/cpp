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
#include <QTextBrowser>

#include "user.h"
#include "order.h"

namespace Ui {
class MyOrder;
}

class MyOrder : public QDialog
{
    Q_OBJECT

public:
    void updatePrice();
    void saveOrderToLogFile(const QString& login);
    void updateOrderTable();
    explicit MyOrder(const QString& login, QWidget *parent = nullptr);
    ~MyOrder();

private slots:
    void on_pushButton_clicked();
    void on_pushBut_Buy_clicked();


private:
    QTextBrowser *priceTextBrowser;
    Ui::MyOrder *ui;
    User user;
};

#endif // MYORDER_H
