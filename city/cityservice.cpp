#include "cityservice.h"
#include "citystorage.h"

CityService* CityService::instance = 0;
CityService * CityService::getInstance() {
    if(!CityService::instance)
        CityService::instance = new CityService();
    return CityService::instance;
}

CityService::CityService()
{
    storage = CityStorage::getInstance();
}

City CityService::get(int id){
    return storage->get(id);
}

void CityService::edit(int id, City city){
    storage->update(id, city);
}
void CityService::gasify(int id){
    if(storage->contains(id)){
        City c = storage->get(id);
        c.isGasified = true;
        storage->update(id, c);
    }
}
