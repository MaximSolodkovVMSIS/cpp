#ifndef USERROLE_H
#define USERROLE_H
#include <QString>

class UserRole
{
public:
    UserRole();
    QString getLogin();
    void setLogin(QString login);
private:
    QString login;
};

#endif // USERROLE_H
