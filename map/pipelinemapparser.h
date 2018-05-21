#ifndef PIPELINEMAPPARSER_H
#define PIPELINEMAPPARSER_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QJsonArray>
#include <QFile>
#include "pipelinemap.h"
#include "pipelinemapstorage.h"

class PipelineMapParser
{
public:
    QFile file;
    QByteArray dataFile;
    QJsonDocument docJS;
    QJsonObject jsonOb;
    PipelineMapParser();
    void readFile(QString filename);
    void parsDocument();
    void getJsOb();
    void parsJson();
private:
    PipelineMapStorage * piplineMapStorage;


};

#endif // PIPELINEMAPPARSER_H

