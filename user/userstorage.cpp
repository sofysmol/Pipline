#include "userstorage.h"

UserStorage* UserStorage::instance = 0;
UserStorage * UserStorage::getInstance() {
    if(!UserStorage::instance)
        UserStorage::instance = new UserStorage();
    return UserStorage::instance;
}
UserStorage::UserStorage(){
    storage = new QMap<int, User>();
}

void UserStorage::add(int id, User v) {
    storage->insert(id, v);
}

void UserStorage::update(int id, User v){
    storage->insert(id, v);
}

void UserStorage::remove(int id){
    storage->remove(id);
}

bool UserStorage::contains(int id){
    return storage->contains(id);
}

User UserStorage::get(int id){
    return storage->value(id);
}

QList<User> UserStorage:: list(){
    return storage->values();
}

