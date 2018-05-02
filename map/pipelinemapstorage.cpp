#include "pipelinemapstorage.h"
#include "pipelinemap.h"
#include <QMap>
#include <QList>

PipelineMapStorage::PipelineMapStorage()
{
    storage = new QMap<int, PipelineMap>();
}

PipelineMapStorage* PipelineMapStorage::instance = 0;
PipelineMapStorage * PipelineMapStorage::getInstance() {
    if(!PipelineMapStorage::instance)
        PipelineMapStorage::instance = new PipelineMapStorage();
    return PipelineMapStorage::instance;
}

void PipelineMapStorage::add(int id, PipelineMap v) {
    storage->insert(id, v);
}

void PipelineMapStorage::update(int id, PipelineMap v){
    storage->insert(id, v);
}

void PipelineMapStorage::remove(int id){
    storage->remove(id);
}

bool PipelineMapStorage::contains(int id){
    return storage->contains(id);
}

PipelineMap PipelineMapStorage::get(int id){
    return storage->value(id);
}

QList<PipelineMap> PipelineMapStorage:: list(){
    return storage->values();
}
