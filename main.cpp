#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QtDebug>
//#include "common/storage.h"
#include "city/citystorage.h"
#include "city/cityservice.h"
#include "common/jsonloader.h"
#include <QJsonArray>
#include "common/configloader.h"
#include "map/pipelinemapstorage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ConfigLoader loader = ConfigLoader();
    loader.loadCity("/Users/s.smolina/Documents/yyy/QtProjects/Pipeline/cities.json");
    loader.loadMap("/Users/s.smolina/Documents/yyy/QtProjects/Pipeline/maps.json");
    CityStorage* storage = CityStorage::getInstance();
    qDebug() << storage->list().length();
    qDebug() << PipelineMapStorage::getInstance()->list().at(0).cities.at(0).isAdded;
    return a.exec();
}
