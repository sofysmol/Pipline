#ifndef PIPELINECITYPARSER_H
#define PIPELINECITYPARSER_H
#include "pipelinecity.h"
#include <QJsonObject>
class PipelineCityParser
{
public:
    PipelineCityParser();
    PipelineCity deserialize(QJsonObject json);
    QJsonObject serialize(PipelineCity pipelineCity);
};

#endif // PIPELINECITYPARSER_H
