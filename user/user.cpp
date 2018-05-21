#include "user.h"

User::User()
{

}
User::User(int id,
           QString login,
           QString password,
           QString specialty) {
    this->id = id;
    this->login = login;
    this->password = password;
    this->specialty = specialty;
}
