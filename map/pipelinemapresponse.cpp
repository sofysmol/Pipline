#include "pipelinemapresponse.h"
#include "pipelinecityresponse.h"
#include <QList>
#include <QString>

PipelineMapResponse::PipelineMapResponse(int id, QString name, QList<PipelineCityResponse> cities)
{
    this->id = id;
    this->name = name;
    this->cities = cities;
}
