#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QtDebug>

//#include "common/storage.h"
#include "city/citystorage.h"
#include "city/cityservice.h"
#include "map/pipelinecity.h"
#include "map/pipelinemapparser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    // Read JSON file
//    QFile file ("/home/kristina/QT/Projects/Pipline-master/PiplineMap.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();
//    file.close();
//    // Parse document
//    QJsonDocument doc (QJsonDocument::fromJson(rawData));
//    // Get JSON object
//    QJsonObject json = doc.object();
//    // Access properties
//    int mapID = json["mapID"].toInt();
//    QString mapName = json["mapName"].toString();
    //PipelineMapStorage piplineMapStorage = new PipelineMapStorage();
    PipelineMapParser pipParser; //= new PipelineMapParser();
    pipParser.readFile("/home/kristina/QT/Projects/Pipline-master/cities.json");
    pipParser.parsDocument();
    pipParser.getJsOb();
    pipParser.parsJson();
    qDebug() << "HI";

    return a.exec();
}
