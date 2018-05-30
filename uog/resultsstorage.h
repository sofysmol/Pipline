#ifndef RESULTSSTORAGE_H
#define RESULTSSTORAGE_H
#include "uogresponce.h"
#include "common/storage.h"
#include <QMap>
class ResultsStorage
{
public:
    static ResultsStorage * getInstance();
    void update(QList<UogResponce> results);
    QList<UogResponce> getResults();
private:
    ResultsStorage();
    static ResultsStorage * instance;
    QMap<int, UogResponce> * storage;
};

#endif // RESULTSSTORAGE_H
