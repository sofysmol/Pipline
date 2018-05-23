#ifndef CRITERIONSERVICE_H
#define CRITERIONSERVICE_H
#include "criterionmatrix.h"
#include "criterionstorage.h"
#include <QVector>

class CriterionService
{
public:
    static CriterionService * getInstance();
    CriterionMatrix getMatrix();
    void editMatrix(CriterionMatrix matrix);
    void addCriterion(Criterion criterion);
    void deleteCriterion(int id);
    QVector<float> getEigenvector();
    bool correctConsistencyIndex();

private:
    CriterionService();
    static CriterionService * instance;
    CriterionStorage* storage;
};

#endif // CRITERIONSERVICE_H
