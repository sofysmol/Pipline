#ifndef USERSERVICE_H
#define USERSERVICE_H
#include <QString>
#include "userstorage.h"

class UserService
{
private:
    UserStorage* storage;
    UserService();
    static UserService * instance;
public:
    static UserService * getInstance();
    bool auth(QString login, QString password);
    QString getSpecialty(QString login);
};

#endif // USERSERVICE_H
