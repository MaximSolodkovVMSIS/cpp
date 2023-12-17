#ifndef HISTORYOFORDERS_H
#define HISTORYOFORDERS_H

#include <QDialog>
#include "user.h"

namespace Ui {
class HistoryOfOrders;
}

class HistoryOfOrders : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryOfOrders(const QString& login, const QString& Role, QWidget *parent = nullptr);
    ~HistoryOfOrders();

private:
    Ui::HistoryOfOrders *ui;
    User user;
    QString Role;
};

#endif // HISTORYOFORDERS_H
