#ifndef PIPELINEMAPSERVICE_H
#define PIPELINEMAPSERVICE_H
#include "pipelinemapstorage.h"
#include "pipelinemapresponse.h"
#include "city/citystorage.h"
#include <QList>

class PipelineMapService
{
public:
    static PipelineMapStorage * getInstance();
    PipelineMapResponse get(int id);
    QList<PipelineMapResponse> list();
    void addCity(int mapId, int cityId);
    void removeCity(int mapId, int cityId);
    QList<PipelineCityResponse> listFreeCities(int mapId);
    QList<PipelineCityResponse> listAllCities(int mapId);
private:
    PipelineMapService();

    PipelineMapStorage* storage;
    CityStorage* cityStorage;

    PipelineCityResponse toPipelineCityRespinse(PipelineCity c);
    PipelineMapResponse toPipelineMapRespinse(PipelineMap m);
    int indexCityById(QList<PipelineCity> cities, int cityId);
};

#endif // PIPELINEMAPSERVICE_H
