#include "criterionstorage.h"

CriterionStorage::CriterionStorage()
{
    storage = new QMap<int, Criterion>();
    matrix = CriterionMatrix::getInstance();
}

CriterionStorage* CriterionStorage::instance = 0;
CriterionStorage * CriterionStorage::getInstance() {
    if(!CriterionStorage::instance)
        CriterionStorage::instance = new CriterionStorage();
    return CriterionStorage::instance;
}

void CriterionStorage::add(int id, Criterion v) {
    storage->insert(id, v);
}

void CriterionStorage::update(int id, Criterion v){
    storage->insert(id, v);
}

void CriterionStorage::remove(int id){
    storage->remove(id);
}

bool CriterionStorage::contains(int id){
    return storage->contains(id);
}

Criterion CriterionStorage::get(int id){
    return storage->value(id);
}

QList<Criterion> CriterionStorage::list(){
    return storage->values();
}



CriterionMatrix CriterionStorage::getMatrix(){
    return *matrix;
}

void CriterionStorage::editMatrix(CriterionMatrix matrix){
   this->matrix = &matrix;
}
