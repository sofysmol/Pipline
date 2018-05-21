#ifndef CITY_H
#define CITY_H
#include <QString>

class City {
public:
    int id;
    QString name;
    QString relief;
    bool isGasified;
    QString piplineMaterial;
    int strenght;
    bool hasImportantFacilities;
    bool hasDifficultObjects;

    City(int id,
        QString name,
        QString relief,
        bool isGasified,
        QString piplineMaterial,
        int strenght,
        bool hasImportantFacilities,
        bool hasDifficultObjects);
    City();
};

#endif // CITY_H
