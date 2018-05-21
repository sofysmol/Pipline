#ifndef CITYPARSER_H
#define CITYPARSER_H
#include <QJsonObject>
#include "city.h"

class CityParser
{
public:
    CityParser();
    City deserialize(QJsonObject json);
    QJsonObject serialize(City city);
};

#endif // CITYPARSER_H
