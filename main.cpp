#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QtDebug>
//#include "common/storage.h"
#include "city/citystorage.h"
#include "city/cityservice.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
