// users.cpp
#include "users.h"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>


Users::Users(const QString& name, const QString& surname, const QString& login, const QString& password)
    : name(name), surname(surname), login(login), password(password) {}

QString Users::getName() const {
    return name;
}

QString Users::getSurname() const {
    return surname;
}

QString Users::getLogin() const {
    return login;
}

QString Users::getPassword() const {
    return password;
}

void Users::setName(QString name){
    this->name = name;
}

void Users::setSurname(QString surname){
    this->login = surname;
}

void Users::setLogin(QString login){
    this->login = login;
}

void Users::setPassword(QString password){
    this->password = password;
}

