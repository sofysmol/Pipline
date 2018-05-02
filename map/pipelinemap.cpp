#include "pipelinemap.h"

PipelineMap::PipelineMap(int id, QString name, QList<PipelineCity> cities)
{
    this->id = id;
    this->name = name;
    this->cities = cities;
}

PipelineMap::PipelineMap(){}
