#include "citystorage.h"
#include "city.h"
#include <QMap>
#include <QList>
#include "city.h"

CityStorage* CityStorage::instance = 0;
CityStorage * CityStorage::getInstance() {
    if(!CityStorage::instance)
        CityStorage::instance = new CityStorage();
    return CityStorage::instance;
}
CityStorage::CityStorage(){
    storage = new QMap<int, City>();
}

void CityStorage::add(int id, City v) {
    storage->insert(id, v);
}

void CityStorage::update(int id, City v){
    storage->insert(id, v);
}

void CityStorage::remove(int id){
    storage->remove(id);
}

bool CityStorage::contains(int id){
    return storage->contains(id);
}

City CityStorage::get(int id){
    return storage->value(id);
}

QList<City> CityStorage:: list(){
    return storage->values();
}
