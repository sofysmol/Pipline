#ifndef MAPPARSER_H
#define MAPPARSER_H
#include "pipelinecityparser.h"
#include "pipelinemap.h"
#include <QJsonObject>

class MapParser
{
private:
    PipelineCityParser cityParser;
public:
    MapParser();
    PipelineMap deserialize(QJsonObject json);
    QJsonObject serialize(PipelineMap pipelineMap);
};

#endif // MAPPARSER_H
