#ifndef ORDER_H
#define ORDER_H

#include <QString>

class OrderItem{
public:
    QString name;
    QString type;
    double price;
    int quantity;
};

class Order
{
public:
    std::vector <OrderItem> items;

    int getItemCount() const;
    double getTotalPrice() const;
    void addItem(const QString& name, const QString& type, double price, int quantity);
    // Метод в классе Order
    void removeItem(const QString& name, const QString& type, double price, int quantity);
    void updateItemQuantity(const QString& name, const QString& type, double price, int quantity);

};

extern Order currentOrder;

#endif // ORDER_H
