#include "pipelinecityparser.h"
#include "pipelinecity.h"

PipelineCityParser::PipelineCityParser()
{

}

PipelineCity PipelineCityParser::deserialize(QJsonObject json){
    return PipelineCity(json["id"].toInt(), json["isAdded"].toBool());
}
QJsonObject PipelineCityParser::serialize(PipelineCity city){
       QJsonObject json = QJsonObject();
       json["id"] = city.id;
       json["isAdded"] = city.isAdded;
       return json;
}

