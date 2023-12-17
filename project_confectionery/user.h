#ifndef USER_H
#define USER_H
#include <QString>


class User{
public:
    void setLogin(QString login);
    QString getLogin();
private:
    QString login;
};

#endif // USER_H
