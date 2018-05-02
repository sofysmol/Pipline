#ifndef PIPELINEMAP_H
#define PIPELINEMAP_H
#include <QString>
#include <QList>
#include "pipelinecity.h"

class PipelineMap
{
public:
    PipelineMap(int id, QString name, QList<PipelineCity> cities);
    PipelineMap();
    int id;
    QString name;
    QList<PipelineCity> cities;
};

#endif // PIPELINEMAP_H
