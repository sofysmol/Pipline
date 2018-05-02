#ifndef CITYSTORAGE_H
#define CITYSTORAGE_H
#include "common/storage.h"
#include "city.h"

class CityStorage
{
public:
    static CityStorage * getInstance();
    void add(int id, City v);
    void update(int id, City v);
    void remove(int id);
    bool contains(int id);
    City get(int id);
    QList<City> list();
private:
    QMap<int, City>* storage;
    static CityStorage * instance;
    CityStorage();
};

#endif // CITYSTORAGE_H
