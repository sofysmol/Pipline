#include "treeparser.h"
#include "treeiterator.h"
#include <QJsonArray>

TreeParser::TreeParser()
{

}

tree::Tree<QString>* TreeParser::deserialize(){
    return new tree::Tree<QString>("");
}

QJsonObject TreeParser::serialize(tree::Tree<QString>* tree){
    tree::TreeIterator<QString> iterator = tree->getRoot();
    return addBranch(tree, *iterator.current());
}

QJsonObject TreeParser::addBranch(tree::Tree<QString>* tree, QString node){
    QJsonObject json = QJsonObject();
    json["id"] = node;
    QJsonArray array = QJsonArray();
    QList<QString> nodes = tree->getDstVertexs(node);
    for(int i=0; i<nodes.size(); i++)
    {
        QJsonObject branch = addBranch(tree, nodes[i]);
        array.append(branch);
    }
    json["branches"] = array;
    return json;
}
