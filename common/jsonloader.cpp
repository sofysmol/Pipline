#include "jsonloader.h"
#include <QFile>
#include <QStringLiteral>
#include <QString>
#include <exceptions/filenotfoundexception.h>
#include <QJsonDocument>
#include <QByteArray>
#include <QJsonArray>
#include <QDebug>

JsonLoader::JsonLoader()
{

}

void JsonLoader::save(QString filename, QJsonArray json){
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open save file.");
            throw FileNotFoundException();
        }
    QJsonDocument saveDoc(json);
    file.write(saveDoc.toJson());
}

QJsonArray JsonLoader::load(QString filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open save file.");
            throw FileNotFoundException();
        }
    QByteArray saveData = file.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    qDebug() << loadDoc.array().count();
    return loadDoc.array();
}
