#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H
#include "city/citystorage.h"
#include "jsonloader.h"
#include "city/cityparser.h"
#include "map/pipelinemapstorage.h"
#include "map/mapparser.h"

class ConfigLoader
{
public:
    ConfigLoader();
    void loadCity(QString filename);
    void saveCity(QString filename);
    void loadMap(QString filename);
    void saveMap(QString filename);
private:
    CityStorage* cityStorage;
    PipelineMapStorage* pipelineMapStorage;
    JsonLoader jsonLoader;
    CityParser cityParser;
    MapParser mapParser;
};

#endif // CONFIGLOADER_H
