#ifndef TREE_H
#define TREE_H

#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <iterator>
#include <queue>

#include "edge.h"
#include "vertex.h"
#include "treeiterator.h"
#include "treeexception.h"
#include "treeallocator.h"
#include <QString>
#include <QList>

namespace tree {


template <class V>
class Tree {
    template <class _V>
    friend class TreeIterator;

public:

    typedef TreeIterator<V> iterator;

    Tree(V& root);
    Tree(const V& root);
    Tree(Tree<V> &other);
    ~Tree();

    //virtual TreeIterator<V> begin_vertex() const;
    //virtual TreeIterator<V> end_vertex() const;

    void addBranch(V &src, V &node);
    void addBranch(const V &src, const V &node);
    void removeBranch(V &src, V &dst);
    TreeIterator<V> getRoot();
    QList<QString> getBranches(V &node);
    QList<QString> getBranches(const V &node);
protected:
    typedef Vertex<V> VType;

    Vertex<V> *findNode(const V &node) const;
    Edge<V> *findEdge(const V &src, const V &dst) const;
    Edge<V> * startWith(const V &node) const;
    Vertex<V>* addNode(V &node);
    Vertex<V>* addNode(const V &node);
    void addEdge(V &src, V &dst);
    void addEdge(const V &src,const V &dst);

    void removeNode(V &node);
    void removeEdge(V &src, V &dst);
    void removeEdge(iterator &src, iterator &dst);

    std::vector<Vertex<V> *> nodes;
    std::vector<Edge<V> *> edges;
    Vertex<V>* root;

    TreeAllocator<V> allocator;
};

template <class V>
QList<QString> Tree<V>::getBranches(V &node){
    QList<V> list = QList<QString>();
    Vertex<V>* nodeV = findNode(node);
    for(int i=0; i<edges.size(); i++){
        if(edges[i]->getSrc()->getData() == node) {
            list.append(*(edges[i]->getDst()->getData()));
        }
    }
    return list;
}

template <class V>
QList<QString> Tree<V>::getBranches(const V &node){
    QList<V> list = QList<QString>();
    Vertex<V>* nodeV = findNode(node);
    for(int i=0; i<edges.size(); i++){
        if(edges[i]->getSrc() == node) {
            list.append(*(edges[i]->getDst()->getData()));
        }
    }
    return list;
}

template <class V>
inline Tree<V>::Tree(V& root){
    addNode(root);
}

template <class V>
inline Tree<V>::Tree(const V& root){
    addNode(root);
}

template <class V>
inline Tree<V>::Tree(Tree<V> &other){
    addNode(other.root);
}

template <class V>
inline Tree<V>::~Tree() {
    allocator.freeAll();
    nodes.clear();
    edges.clear();
}

template <class V>
inline void Tree<V>::removeBranch(V &src, V &dst){

    Vertex<V>* d = findNode(src);
    if(!d){
        throw TreeNodeNotExistException<V>(dst);
    }
    Vertex<V>* s = findNode(src);
    if(!s){
        throw TreeNodeNotExistException<V>(src);
    }

    while(!startWith(dst)){
        Edge<V>* e = startWith(dst);
        removeBranch(dst, e->getDst());
    }
}

template <class V>
inline TreeIterator<V> Tree<V>::getRoot(){
    return iterator(this);
}

template <class V>
inline void Tree<V>::addBranch(V &src, V &node) {
    Vertex<V>* srcV = findNode(src);
    if (!srcV) {
        throw TreeNodeNotExistException<V>(src);
    }
    Vertex<V>* dst = findNode(node);

    if(!dst){
        dst = addNode(node);
    }
    addEdge(src, node);
}

template <class V>
inline void Tree<V>::addBranch(const V &src,const V &node) {
    Vertex<V>* srcV = findNode(src);
    if (srcV == nullptr) {
        throw TreeNodeNotExistException<V>(src);
    }
    Vertex<V>* dst = findNode(node);

    if(!dst){
        dst = addNode(node);
    }
    addEdge(src, node);
}

template <class V>
inline Vertex<V>* Tree<V>::addNode(V &node) {
    if (findNode(node)) {
        throw TreeNodeExistException<V>(node);
    }
    Vertex<V>* v = allocator.allocVertex(node);
    nodes.push_back(v);
    return v;
}

template <class V>
inline Vertex<V>* Tree<V>::addNode(const V &node) {
    if (findNode(node)) {
        throw TreeNodeExistException<V>(node);
    }
    Vertex<V>* v = allocator.allocVertex(node);
    nodes.push_back(v);
    return v;
}

template <class V>
inline void Tree<V>::addEdge(V &src, V &dst) {
    VType *source = findNode(src);
    VType *destination = findNode(dst);

    if (source && destination && findEdge(src, dst)) {
        throw TreeEdgeExistException<V>(src, dst);
    }
    if (source == nullptr) {
        source = allocator.allocVertex(src);
        nodes.push_back( source );
    }
    if (destination == nullptr) {
        destination = allocator.allocVertex(dst);
        nodes.push_back( destination );
    }
    edges.push_back( allocator.allocEdge(source, destination) );
}

template <class V>
inline void Tree<V>::addEdge(const V &src, const V &dst) {
    VType *source = findNode(src);
    VType *destination = findNode(dst);

    if (source && destination && findEdge(src, dst)) {
        throw TreeEdgeExistException<V>(src, dst);
    }
    if (source == nullptr) {
        source = allocator.allocVertex(src);
        nodes.push_back( source );
    }
    if (destination == nullptr) {
        destination = allocator.allocVertex(dst);
        nodes.push_back( destination );
    }
    edges.push_back( allocator.allocEdge(source, destination) );
}

template <class V>
void Tree<V>::removeNode(V &node) {
    VType *n = findNode(node);

    if (n == nullptr) {
        throw TreeNodeNotExistException<V>(node);
    }

    auto pos = std::find(nodes.begin(), nodes.end(), n);
    if (pos != nodes.end()) {
        nodes.erase(pos);
    }
}

template <class V>
void Tree<V>::removeEdge(V &src, V &dst) {
    VType *edge = findEdge(src, dst);

    if (edge == nullptr) {
        throw TreeEdgeNotExistException<V>(src, dst);
    }

    auto pos = std::find(edges.begin(), edges.end(), edge);
    if (pos != edges.end()) {
        edges.erase(pos);
    }
}

template <class V>
void Tree<V>::removeEdge(iterator &src, iterator &dst) {
    removeEdge(*src, *dst);
}

template <class V>
inline Vertex<V> * Tree<V>::findNode(const V &node) const {
    for(Vertex<V>* v : nodes){
        if(*(v->getData())== node)
            return v;
    }

    return nullptr;
}

template <class V>
inline Edge<V> * Tree<V>::startWith(const V &node) const {
    auto pos = std::find_if(
        std::begin(edges),
        std::end(edges),
        [&node](Edge<V> &elem) {
            return ((*elem->getSrc()->getData() == node));
        }
    );
    if (pos != edges.cend()) {
        return *pos;
    }

    return nullptr;
}

template <class V>
inline Edge<V> *
        Tree<V>::findEdge(const V &src, const V &dst) const {
    for(int i=0; i < edges.size(); i++){
        if(edges[i]->getSrc()->getData() == src && edges[i]->getDst()->getData() == src)
            return edges[i];
    }

    return nullptr;
}
}
#endif // TREE_H
