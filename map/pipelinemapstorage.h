#ifndef PIPELINEMAPSTORAGE_H
#define PIPELINEMAPSTORAGE_H
#include "pipelinemap.h"

class PipelineMapStorage
{
public:
    static PipelineMapStorage * getInstance();
    void add(int id, PipelineMap v);
    void update(int id, PipelineMap v);
    void remove(int id);
    bool contains(int id);
    PipelineMap get(int id);
    QList<PipelineMap> list();
private: PipelineMapStorage();
    QMap<int, PipelineMap>* storage;
    static PipelineMapStorage * instance;
};

#endif // PIPELINEMAPSTORAGE_H
