#ifndef ALTERNATIVESSERVICE_H
#define ALTERNATIVESSERVICE_H
#include <QString>
#include "alternativesmatrix.h"

class AlternativesService
{
private:
    AlternativesService();
    static AlternativesService * instance;
    QList<QString> storage;
public:
    static AlternativesService * getInstance();
    void add(QString cityId);
    void remove(QString cityId);
    AlternativesMatrix getMatrix();
    QVector<double> getEigenvector(QString cityId);
    float getWeight(QString cityId);
};

#endif // ALTERNATIVESSERVICE_H
