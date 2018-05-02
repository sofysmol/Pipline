#include "city.h"

City::City(QString id,
           QString name,
           QString relief,
           bool isGasified,
           QString piplineMaterial,
           int strenght,
           bool hasImportantFacilities,
           bool hasDifficultObjects) {
    this->id = id;
    this->name = name;
    this->relief = relief;
    this->isGasified = isGasified;
    this->piplineMaterial = piplineMaterial;
    this->strenght = strenght;
    this->hasImportantFacilities = hasImportantFacilities;
    this->hasDifficultObjects = hasDifficultObjects;
}

City::City(){
}
