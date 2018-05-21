#ifndef USERPARSER_H
#define USERPARSER_H
#include "user.h"
#include <QJsonObject>

class UserParser
{
public:
    UserParser();
    User deserialize(QJsonObject json);
    QJsonObject serialize(User user);
};

#endif // USERPARSER_H
