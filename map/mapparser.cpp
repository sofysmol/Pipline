#include "mapparser.h"
#include <QJsonArray>
#include <QString>

MapParser::MapParser()
{
    cityParser = PipelineCityParser();
}

PipelineMap MapParser::deserialize(QJsonObject json){
    QJsonArray citiesJson = json["cities"].toArray();
    QList<PipelineCity> cities = QList<PipelineCity>();
    for(int i = 0; i<citiesJson.count(); i++)
    {
        PipelineCity c = cityParser.deserialize(citiesJson.at(i).toObject());
        cities.append(c);
    }
    return PipelineMap(json["id"].toInt(),
                json["name"].toString(),
                cities);
}

QJsonObject MapParser::serialize(PipelineMap pipelineMap){
    QJsonArray jarray = QJsonArray();
    QList<PipelineCity> cities = pipelineMap.cities;
    for(int i = 0; i<cities.length(); i++)
    {
        QJsonObject c = cityParser.serialize(cities.at(i));
        jarray.append(c);
    }
       QJsonObject json = QJsonObject();
       json["id"] = pipelineMap.id;
       json["name"] = pipelineMap.name;
       json["cities"] = jarray;
       return json;
}
