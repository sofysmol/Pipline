#include "resultsstorage.h"

ResultsStorage::ResultsStorage()
{

}
ResultsStorage* ResultsStorage::instance = 0;
ResultsStorage * ResultsStorage::getInstance() {
    if(!ResultsStorage::instance)
        ResultsStorage::instance = new ResultsStorage();
    return ResultsStorage::instance;
}

void ResultsStorage::update(QList<UogResponce> results)
{
    if (storage.isEmpty() == false)
    {
        storage.clear();
    }
    for(int i=0; i< results.size(); i++)
    {
        storage.push_back(UogResponce);
    }
}
