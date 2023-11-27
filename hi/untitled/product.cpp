#include "product.h"

// Реализации методов класса Product
Product::Product(const QString& name, double price) : name(name), price(price) {}
QString Product::getName() const {
    return name;
}
double Product::getPrice() const {
    return price;
}

// Реализации методов класса Additive
Additive::Additive(const QString& name, double cost) : name(name), cost(cost) {}
QString Additive::getName() const {
    return name;
}
double Additive::getCost() const {
    return cost;
}

// Реализации методов класса Pastry
Pastry::Pastry(const QString& name, double price, double weight, const Additive& additive)
    : Product(name, price), weight(weight), additive(additive) {}

double Pastry::getWeight() const {
    return weight;
}
Additive Pastry::getAdditive() const {
    return additive;
}

// Реализации методов класса Drink
Drink::Drink(const QString& name, double price, double volume, const QString& type)
    : Product(name, price), volume(volume), type(type) {}

double Drink::getVolume() const {
    return volume;
}
QString Drink::getType() const {
    return type;
}
