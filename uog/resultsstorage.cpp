#include "resultsstorage.h"

ResultsStorage::ResultsStorage()
{
    storage = new QMap<int, UogResponce>();
}
ResultsStorage* ResultsStorage::instance = 0;
ResultsStorage * ResultsStorage::getInstance() {
    if(!ResultsStorage::instance)
        ResultsStorage::instance = new ResultsStorage();
    return ResultsStorage::instance;
}

void ResultsStorage::update(QList<UogResponce> results)
{
    if (storage->isEmpty() == false)
    {
        storage->clear();
    }
    for(int i=0; i< results.size(); i++)
    {
        storage->insert(i,results[i]);
    }
}

QList<UogResponce> ResultsStorage::getResults()
{
    return storage->values();
}
