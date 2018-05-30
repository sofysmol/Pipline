#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QList>
#include <QtDebug>
//#include "common/storage.h"
#include "city/citystorage.h"
#include "city/cityservice.h"
#include "common/jsonloader.h"
#include <QJsonArray>
#include "common/configloader.h"
#include "map/pipelinemapstorage.h"
#include "user/userstorage.h"
#include "tree/tree.h"
#include "tree/treeservice.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ConfigLoader loader = ConfigLoader();
    loader.loadCity("/Users/s.smolina/Documents/yyy/QtProjects/Pipeline/cities.json");
    loader.loadMap("/Users/s.smolina/Documents/yyy/QtProjects/Pipeline/maps.json");
    loader.loadUser("/Users/s.smolina/Documents/yyy/QtProjects/Pipeline/users.json");
    TreeService* treeService = TreeService::getInstance();
    QList<QString> alt = QList<QString>();
    alt.append("hello");
    alt.append("hello2");
    QList<QString> crt = QList<QString>();
    crt.append("buy");
    crt.append("buy2");
    treeService->createTree(alt, crt);
    return a.exec();
}
