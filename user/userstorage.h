#ifndef USERSTORAGE_H
#define USERSTORAGE_H
#include "user.h"
#include <QMap>
#include <QList>

class UserStorage
{
public:
    static UserStorage * getInstance();
    void add(int id, User v);
    void update(int id, User v);
    void remove(int id);
    bool contains(int id);
    User get(int id);
    QList<User> list();
private:
    QMap<int, User>* storage;
    static UserStorage * instance;
    UserStorage();
};

#endif // USERSTORAGE_H
