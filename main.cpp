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
#include "user/userstorage.h"
#include "tree/tree.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ConfigLoader loader = ConfigLoader();
    loader.loadCity("/Users/s.smolina/Documents/yyy/QtProjects/Pipeline/cities.json");
    loader.loadMap("/Users/s.smolina/Documents/yyy/QtProjects/Pipeline/maps.json");
    loader.loadUser("/Users/s.smolina/Documents/yyy/QtProjects/Pipeline/users.json");
    int z = 5;
    tree::Tree<int>* tree = new tree::Tree<int>(z);
    return a.exec();
}
