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
private:
    UogService();
    static UogService * instance;
    CriterionStorage * criterionstorage;
    CityStorage * citystorage;
    AlternativesService * alternativeservice;
    ResultsStorage * storage;
    QVector<QVector<double>> createAlternativeMatrix(int idcriterion);
    void createListAlternativeMatrix();
    QVector<double> calcUog();

};

#endif // UOGSERVICE_H
