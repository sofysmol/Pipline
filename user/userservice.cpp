#include "userservice.h"



UserService* UserService::instance = 0;
UserService * UserService::getInstance() {
    if(!UserService::instance)
        UserService::instance = new UserService();
    return UserService::instance;
}

UserService::UserService()
{
    storage = UserStorage::getInstance();
}

bool UserService::auth(QString login, QString password){
    QList<User> users = storage->list();
    bool res = false;
    for(int i=0; i<users.length(); i++){
        if(users.at(i).login == login && users.at(i).password == password)
            res = true;
    }
    return res;
}

QString UserService::getSpecialty(QString login){
    QList<User> users = storage->list();
    User user;
    for(int i=0; i<users.length(); i++){
        if(users.at(i).login == login)
            user = users.at(i);
    }
    return user.specialty;
}
