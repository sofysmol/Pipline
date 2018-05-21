#include "pipelinemapservice.h"
#include "pipelinemapstorage.h"
#include "pipelinemap.h"
#include "city/citystorage.h"

PipelineMapService* PipelineMapService::instance = 0;
PipelineMapService * PipelineMapService::getInstance() {
    if(!PipelineMapService::instance)
        PipelineMapService::instance = new PipelineMapService();
    return PipelineMapService::instance;
}

PipelineMapService::PipelineMapService()
{
    storage = PipelineMapStorage::getInstance();
    cityStorage = CityStorage::getInstance();
}

PipelineMapResponse PipelineMapService::get(int id){
    return toPipelineMapRespinse(storage->get(id));
}

QList<PipelineMapResponse> PipelineMapService::list(){
    QList<PipelineMapResponse> res = QList<PipelineMapResponse>();
    QList<PipelineMap> list = storage->list();
    for(int i=0; i<list.length(); i++)
    {
        res.append(toPipelineMapRespinse(list[i]));
    }
    return res;
}
void PipelineMapService::addCity(int mapId, int cityId){
    if(storage->contains(mapId)){
        PipelineMap m = storage->get(mapId);
        int index = indexCityById(m.cities, cityId);
        if (index >= 0){
            PipelineCity c = m.cities[index];
            c.isAdded = true;
            m.cities.removeAt(index);
            m.cities.append(c);
            storage->update(mapId, m);
        }
    }
}

int PipelineMapService::indexCityById(QList<PipelineCity> cities, int cityId) {
    for(int i = 0; i<cities.length(); i++){
        if(cities[i].id == cityId)
            return i;
    }
    return -1;
}

void PipelineMapService::removeCity(int mapId, int cityId){
    if(storage->contains(mapId)){
        PipelineMap m = storage->get(mapId);
        int index = indexCityById(m.cities, cityId);
        if (index >= 0){
            PipelineCity c = m.cities[index];
            c.isAdded = false;
            m.cities.removeAt(index);
            m.cities.append(c);
            storage->update(mapId, m);
        }
    }
}

QList<PipelineCityResponse> PipelineMapService::listFreeCities(int mapId) {
    QList<PipelineCityResponse> res = QList<PipelineCityResponse>();
    PipelineMap m = storage->get(mapId);
    for(int i = 0; i< m.cities.length(); i++){
        PipelineCity c = m.cities[i];
        if(!c.isAdded)
            res.append(toPipelineCityRespinse(c));
    }
    return res;
}


QList<PipelineCityResponse> PipelineMapService::listAllCities(int mapId){
    QList<PipelineCityResponse> res = QList<PipelineCityResponse>();
    PipelineMap m = storage->get(mapId);
    for(int i = 0; i< m.cities.length(); i++){
        PipelineCity c = m.cities[i];
        res.append(toPipelineCityRespinse(c));
    }
    return res;
}

PipelineCityResponse PipelineMapService::toPipelineCityRespinse(PipelineCity c){
    if(cityStorage->contains(c.id)){
        City city = cityStorage->get(c.id);
        return PipelineCityResponse(c.id, c.isAdded, city.name, city.isGasified);
    }
    return PipelineCityResponse(c.id, c.isAdded, "", false);
}

PipelineMapResponse PipelineMapService::toPipelineMapRespinse(PipelineMap m){
    QList<PipelineCityResponse> cities = listAllCities(m.id);
    return PipelineMapResponse(m.id, m.name, cities);
}
