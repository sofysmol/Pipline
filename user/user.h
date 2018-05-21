#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User();
    User(int id,
        QString login,
        QString password,
        QString specialty);
    int id;
    QString login;
    QString password;
    QString specialty;
};

#endif // USER_H
