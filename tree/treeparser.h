#ifndef TREEPARSER_H
#define TREEPARSER_H
#include "tree.h"
#include <QString>
#include <QJsonObject>

class TreeParser
{
public:
    TreeParser();
    tree::Tree<QString>* deserialize();
    QJsonObject serialize(tree::Tree<QString>* tree);
private:
    QJsonObject addBranch(tree::Tree<QString>* tree, QString node);
};

#endif // TREEPARSER_H
