#ifndef CITY_H
#define CITY_H
#include <QString>

class City {
public:
    QString id;
    QString name;
    QString relief;
    bool isGasified;
    QString piplineMaterial;
    int strenght;
    bool hasImportantFacilities;
    bool hasDifficultObjects;

    City(QString id,
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
