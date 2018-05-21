#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H
#include "city/citystorage.h"
#include "jsonloader.h"
#include "city/cityparser.h"
#include "map/pipelinemapstorage.h"
#include "map/mapparser.h"
#include "user/userparser.h"
#include "user/userstorage.h"

class ConfigLoader
{
public:
    ConfigLoader();
    void loadCity(QString filename);
    void saveCity(QString filename);
    void loadMap(QString filename);
    void saveMap(QString filename);
    void loadUser(QString filename);
    void saveUser(QString filename);
private:
    CityStorage* cityStorage;
    PipelineMapStorage* pipelineMapStorage;
    UserStorage* userStorage;
    JsonLoader jsonLoader;
    CityParser cityParser;
    MapParser mapParser;
    UserParser userParser;
};

#endif // CONFIGLOADER_H
