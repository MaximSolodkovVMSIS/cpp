#include "order.h"

int Order::getItemCount() const {
    return items.size();
}

double Order::getTotalPrice() const {
    double totalPrice = 0.0;

    for (const auto& item : items) {
        totalPrice += item.price * item.quantity;
    }

    return totalPrice;
}

void Order::addItem(const QString& name, const QString& type, double price, int quantity) {
    // Проверяем, есть ли уже такой товар в заказе
    for (auto& item : items) {
        if (item.name == name && item.type == type) {
            // Товар уже есть в заказе, просто обновляем количество
            item.quantity += quantity;
            return;
        }
    }
    // Если товар не найден в заказе, добавляем новый
    OrderItem newItem;
    newItem.name = name;
    newItem.type = type;
    newItem.price = price;
    newItem.quantity = quantity;
    items.push_back(newItem);
}
// Метод в классе Order
void Order::removeItem(const QString& name, const QString& type, double price, int quantity) {
    // Ищем соответствующий товар в заказе
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == name && it->type == type && it->price == price && it->quantity == quantity) {
            // Удаляем товар из заказа
            items.erase(it);
            return;
        }
    }
}
void Order::updateItemQuantity(const QString& name, const QString& type, double price, int quantity) {
    auto it = std::find_if(items.begin(), items.end(),
                           [&name, &type, &price](const OrderItem& item) {
                               return item.name == name && item.type == type && item.price == price;
                           });

    if (it != items.end()) {
        it->quantity = quantity;

        // Если количество стало 0 или меньше, удаляем объект
        if (it->quantity <= 0) {
            items.erase(it);
        }
    }
}

