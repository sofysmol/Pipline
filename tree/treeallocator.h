#ifndef TREEALLOCATOR_H
#define TREEALLOCATOR_H

#include <list>
#include "vertex.h"
#include "edge.h"

namespace tree {

template <class V>
class TreeAllocator {

public:
    TreeAllocator();
    explicit TreeAllocator(size_t n_nodes, size_t n_edges);
    virtual ~TreeAllocator();

    Vertex<V> *allocVertex(V *data);
    Vertex<V> *allocVertex(const V &data);

    Edge<V> *allocEdge(Vertex<V> *src, Vertex<V> *dst);

    void freeAll();
private:
    TreeAllocator(TreeAllocator &) = delete;

    std::list<Vertex<V> *> vertices_pool;
    std::list<Edge<V> *> edges_pool;
};

template <class V>
TreeAllocator<V>::TreeAllocator()
    : vertices_pool(100), edges_pool(100)
{
}


template <class V>
TreeAllocator<V>::TreeAllocator(size_t n_nodes, size_t n_edges)
    : vertices_pool(n_nodes), edges_pool(n_edges)
{
}

template <class V>
TreeAllocator<V>::~TreeAllocator() {
    freeAll();
}

template <class V>
Vertex<V> * TreeAllocator<V>::allocVertex(V *data) {
    Vertex<V> *vertex = new Vertex<V>(data);
    vertices_pool.push_back(vertex);
    return vertex;
}

template <class V>
Vertex<V> * TreeAllocator<V>::allocVertex(const V &data) {
    Vertex<V> *vertex = new Vertex<V>(data);
    vertices_pool.push_back(vertex);
    return vertex;
}

template <class V>
Edge<V> * TreeAllocator<V>::allocEdge(Vertex<V> *src, Vertex<V> *dst) {
    Edge<V> *edge = new Edge<V>(src, dst);
    edges_pool.push_back(edge);
    return edge;
}

template <class V>
void TreeAllocator<V>::freeAll() {
    for (auto &v : vertices_pool) {
        delete v;
    }
    for (auto &e: edges_pool) {
        delete e;
    }
    vertices_pool.clear();
    edges_pool.clear();
}


}
#endif // TREEALLOCATOR_H
