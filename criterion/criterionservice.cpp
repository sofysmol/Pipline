#include "criterionservice.h"

CriterionService* CriterionService::instance = 0;
CriterionService * CriterionService::getInstance() {
    if(!CriterionService::instance)
        CriterionService::instance = new CriterionService();
    return CriterionService::instance;
}

CriterionService::CriterionService()
{
    storage = CriterionStorage::getInstance();
}

CriterionMatrix CriterionService::getMatrix(){
    return storage->getMatrix();
}

void CriterionService::editMatrix(CriterionMatrix matrix){
    storage->editMatrix(matrix);
}

void CriterionService::addCriterion(Criterion criterion){
    storage->add(criterion.id, criterion);
}

void CriterionService::deleteCriterion(int id){
    storage->remove(id);
}

QVector<float> CriterionService::getEigenvector(){
    return QVector<float>();
}

bool CriterionService::correctConsistencyIndex(){
    return false;
}
