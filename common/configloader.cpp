#include "configloader.h"
#include "city/citystorage.h"
#include <QJsonArray>
#include "city/citystorage.h"
ConfigLoader::ConfigLoader()
{
    cityStorage = CityStorage::getInstance();
    cityParser = CityParser();
    pipelineMapStorage = PipelineMapStorage::getInstance();
    mapParser = MapParser();
    userStorage = UserStorage::getInstance();
    userParser = UserParser();
    jsonLoader = JsonLoader();
}
void ConfigLoader::loadCity(QString filename){
    QJsonArray jarray = jsonLoader.load(filename);
    for(int i = 0; i<jarray.count(); i++)
    {
        City c = cityParser.deserialize(jarray.at(i).toObject());
        cityStorage->add(c.id, c);
    }

}
void ConfigLoader::saveCity(QString filename){
    QJsonArray jarray = QJsonArray();
    QList<City> cities = cityStorage->list();
    for(int i = 0; i<cities.length(); i++)
    {
        QJsonObject c = cityParser.serialize(cities.at(i));
        jarray.append(c);
    }
    jsonLoader.save(filename, jarray);
}

void ConfigLoader::loadMap(QString filename){
    QJsonArray jarray = jsonLoader.load(filename);
    for(int i = 0; i<jarray.count(); i++)
    {
        PipelineMap c = mapParser.deserialize(jarray.at(i).toObject());
        pipelineMapStorage->add(c.id, c);
    }

}
void ConfigLoader::saveMap(QString filename){
    QJsonArray jarray = QJsonArray();
    QList<PipelineMap> maps = pipelineMapStorage->list();
    for(int i = 0; i<maps.length(); i++)
    {
        QJsonObject c = mapParser.serialize(maps.at(i));
        jarray.append(c);
    }
    jsonLoader.save(filename, jarray);
}

void ConfigLoader::loadUser(QString filename){
    QJsonArray jarray = jsonLoader.load(filename);
    for(int i = 0; i<jarray.count(); i++)
    {
        User c = userParser.deserialize(jarray.at(i).toObject());
        userStorage->add(c.id, c);
    }

}
void ConfigLoader::saveUser(QString filename){
    QJsonArray jarray = QJsonArray();
    QList<User> users = userStorage->list();
    for(int i = 0; i<users.length(); i++)
    {
        QJsonObject c = userParser.serialize(users.at(i));
        jarray.append(c);
    }
    jsonLoader.save(filename, jarray);
}
