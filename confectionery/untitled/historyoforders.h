#ifndef HISTORYOFORDERS_H
#define HISTORYOFORDERS_H

#include <QDialog>

namespace Ui {
class HistoryOfOrders;
}

class HistoryOfOrders : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryOfOrders(QWidget *parent = nullptr);
    ~HistoryOfOrders();

private:
    Ui::HistoryOfOrders *ui;
};

#endif // HISTORYOFORDERS_H
