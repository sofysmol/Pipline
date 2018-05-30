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
    storage->getMatrix();
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

QVector<double> CriterionService::getEigenvector(){
    return storage->getMatrix().getEigenvector();//QVector<float>();
}

bool CriterionService::correctConsistencyIndex(){
    return storage->getMatrix().checkConsistency();//false;
}
