#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

// Базовый класс "Продукт"
class Product {
public:
    Product(const QString& name, double price);
    QString getName() const;
    double getPrice() const;

private:
    QString name;
    double price;
};

// Класс "Добавка"
class Additive {
public:
    Additive(const QString& name, double cost);
    QString getName() const;
    double getCost() const;

private:
    QString name;
    double cost;
};

// Класс "Выпечка"
class Pastry : public Product {
public:
    Pastry(const QString& name, double price, double weight, const Additive& additive);
    double getWeight() const;
    Additive getAdditive() const;

private:
    double weight;
    Additive additive;
};

// Класс "Напиток"
class Drink : public Product {
public:
    Drink(const QString& name, double price, double volume, const QString& type);
    double getVolume() const;
    QString getType() const;

private:
    double volume;
    QString type;
};

#endif // PRODUCT_H
