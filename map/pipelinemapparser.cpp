#include "pipelinemapparser.h"
//#include "pipelinemapstorage.h"

PipelineMapParser::PipelineMapParser(){
    piplineMapStorage = PipelineMapStorage::getInstance();
}

void PipelineMapParser::readFile(QString filename){

    file.setFileName(filename);
    file.open(QIODevice::ReadOnly);
    dataFile = file.readAll();
    file.close();
     //= rawData;
}

void PipelineMapParser::parsDocument(){
    QJsonDocument doc (QJsonDocument::fromJson(dataFile));
    docJS = doc;
}

void PipelineMapParser::getJsOb(){
    QJsonObject json = docJS.object();
    jsonOb = json;
}

void PipelineMapParser::parsJson(){
    // Access properties
    QJsonValue value = jsonOb.value("Mapes");
    QJsonArray arrayMap = value.toArray();

    //piplineMapStorage.getInstance();
    foreach (const QJsonValue & v, arrayMap) {
        int mapId = v.toObject().value("mapID").toInt();
        QString mapName =  v.toObject().value("mapName").toString();
        QJsonValue pipcities = v.toObject().value("PipelineCeties");
        QJsonArray arrayCities = pipcities.toArray();
        QList<PipelineCity> pipCity;
        foreach (const QJsonValue & val, arrayCities) {
            int id = val.toObject().value("id").toInt();
            bool isAdded = val.toObject().value("isAdded").toBool();
            PipelineCity tmp_pipCyti (id, isAdded);
            pipCity.append(tmp_pipCyti);
        }
        PipelineMap piplineMap (mapId, mapName, pipCity);
        piplineMapStorage->add(mapId,piplineMap);
    }

}
