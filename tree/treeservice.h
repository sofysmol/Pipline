#ifndef TREESERVICE_H
#define TREESERVICE_H
#include "tree.h"
#include <QList>
#include <QString>
#include "treeparser.h"
#include "common/jsonloader.h"

class TreeService
{
public:
    static TreeService * getInstance();
    tree::Tree<QString>* createTree(QList<QString> alts, QList<QString> criterias);
private:
    static TreeService * instance;
    TreeService();
    TreeParser parser;
    JsonLoader loader;
};

#endif // TREESERVICE_H
