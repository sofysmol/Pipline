#include "treeservice.h"
#include <QDebug>
#include "treeiterator.h"
#include <QJsonArray>

TreeService::TreeService()
{
    parser = TreeParser();
    loader = JsonLoader();
}

TreeService* TreeService::instance = 0;
TreeService* TreeService::getInstance() {
    if(!TreeService::instance)
        TreeService::instance = new TreeService();
    return TreeService::instance;
}

tree::Tree<QString>* TreeService::createTree(QList<QString> alts, QList<QString> criterias)
{
    tree::Tree<QString>* tree = new tree::Tree<QString>("Цель");
    for(int i=0; i<criterias.size(); i++){
        tree->addBranch("Цель", criterias[i]);
        for(int j=0; j<alts.size(); j++){
            tree->addBranch(criterias[i], alts[j]);
        }
    }
    QJsonObject json = parser.serialize(tree);
    loader.save("/Users/s.smolina/Documents/yyy/QtProjects/Pipeline/tree.json", json);
    return tree;
}
