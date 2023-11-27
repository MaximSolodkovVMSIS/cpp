// users.h
#ifndef USERS_H
#define USERS_H
#include <Qstring>
#include <QTextStream>
#include <QVector>

enum Role{

};

class Users {
public:
    Users(const QString& name, const QString& surname, const QString& login, const QString& password);

    QString getName() const;
    QString getSurname() const;
    QString getLogin() const;
    QString getPassword() const;
    void setName(QString name);
    void setSurname(QString surname);
    void setLogin(QString login);
    void setPassword(QString password);

private:
    QString name;
    QString surname;
    QString login;
    QString password;
};

#endif // USERS_H
