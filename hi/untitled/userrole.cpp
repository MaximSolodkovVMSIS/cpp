#include "userrole.h"

UserRole::UserRole()
{

}

QString UserRole::getLogin(){
    return login;
}


void UserRole::setLogin(QString login){
    this->login = login;
}
