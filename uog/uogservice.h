#ifndef UOGSERVICE_H
#define UOGSERVICE_H
#include "criterion/criterionstorage.h"
#include "city/citystorage.h"
#include "alternatives/alternativesmatrix.h"
#include "alternatives/alternativesservice.h"
#include "uogresponce.h"
#include "resultsstorage.h"

class UogService
{
public:
    static UogService * getInstance();
    QVector<AlternativesMatrix> listalternativematrix;
    QList<UogResponce> results;
    void createListResponse();
    //get alternative matrix
    QList<UogResponce> getResults();
    QVector<AlternativesMatrix> getListAlternativeMatrix();
private:
    UogService();
    static UogService * instance;
    CriterionStorage * criterionstorage;
    CityStorage * citystorage;
    AlternativesService * alternativeservice;
    ResultsStorage * storage;
    choosefield (City city, QString criterion);
    AlternativesMatrix createAlternativeMatrix(QString criterion, int id);
    void createListAlternativeMatrix();
    QVector<double> calcUog();

};

#endif // UOGSERVICE_H
