#ifndef JsonLoader_H
#define JsonLoader_H
#include<QJsonObject>
#include <QString>
#include <exceptions/filenotfoundexception.h>

class JsonLoader
{
public:
    JsonLoader();
    QJsonArray load(QString filename);
    void save(QString filename, QJsonArray json);
};

#endif // JsonLoader_H
