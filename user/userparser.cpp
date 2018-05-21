#include "userparser.h"

UserParser::UserParser()
{

}

User UserParser::deserialize(QJsonObject json)
{
    return User(json["id"].toInt(),
                json["login"].toString(),
                json["password"].toString(),
                json["specialty"].toString());
}

QJsonObject UserParser::serialize(User user)
{
    QJsonObject json = QJsonObject();
    json["id"] = user.id;
    json["login"] = user.login;
    json["password"] = user.password,
    json["specialty"] = user.specialty;
    return json;
}
