#include "cityparser.h"
#include <QJsonObject>
#include "city.h"

CityParser::CityParser()
{

}

City CityParser::deserialize(QJsonObject json){
    return City(json["id"].toInt(),
                json["name"].toString(),
                json["relief"].toString(),
                json["isGasified"].toBool(),
                json["piplineMaterial"].toString(),
                json["strenght"].toInt(),
                json["hasImportantFacilities"].toBool(),
                json["hasDifficultObjects"].toBool());
}
QJsonObject CityParser::serialize(City city){
       QJsonObject json = QJsonObject();
       json["id"] = city.id;
       json["name"] = city.name;
       json["relief"] = city.relief,
       json["isGasified"] = city.isGasified;
       json["piplineMaterial"] = city.piplineMaterial;
       json["strenght"] = city.strenght;
       json["hasImportantFacilities"] = city.hasImportantFacilities;
       json["hasDifficultObjects"] = city.hasDifficultObjects;
       return json;
}
