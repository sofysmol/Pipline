#ifndef RESULTSSTORAGE_H
#define RESULTSSTORAGE_H
#include "uogresponce.h"
#include "uogservice.h"

class ResultsStorage
{
public:
    static ResultsStorage * getInstance();
    void update(QList<UogResponce> results);
private:
    ResultsStorage();
    static ResultsStorage * instance;
    QList <UogResponce>  storage;
};

#endif // RESULTSSTORAGE_H
