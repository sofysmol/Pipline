#ifndef CITYSERVICE_H
#define CITYSERVICE_H

#include "citystorage.h"
#include "city.h"

class CityService
{
public:
    static CityService * getInstance();
    City get(int id);
    void edit(int id, City city);
    void gasify(int id);
private:
    CityService();
    CityStorage* storage;
    static CityService * instance;
};

#endif // CITYSERVICE_H
