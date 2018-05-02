#ifndef PIPELINEMAPRESPONSE_H
#define PIPELINEMAPRESPONSE_H
#include <QList>
#include <QString>
#include "pipelinecityresponse.h"

class PipelineMapResponse
{
public:
    PipelineMapResponse(int id,
                        QString name,
                        QList<PipelineCityResponse> cities);
    int id;
    QString name;
    QList<PipelineCityResponse> cities;
};

#endif // PIPELINEMAPRESPONSE_H
