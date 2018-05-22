#include "alternativesservice.h"

AlternativesService::AlternativesService()
{
    storage = QList<QString>();
}

AlternativesService* AlternativesService::instance = 0;
AlternativesService * AlternativesService::getInstance() {
    if(!AlternativesService::instance)
        AlternativesService::instance = new AlternativesService();
    return AlternativesService::instance;
}

void AlternativesService::add(QString cityId){
    if(!storage.contains(cityId))
    {
        storage.append(cityId);
    }
}

void AlternativesService::remove(QString cityId){
    storage.removeOne(cityId);
}

AlternativesMatrix AlternativesService::getMatrix(){
    return AlternativesMatrix();
}

QVector<float> AlternativesService::getEigenvector(QString cityId){
    return QVector<float>();
}

float AlternativesService::getWeight(QString cityId){
    return 0;
}
