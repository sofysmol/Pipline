#ifndef GRAPH_H
#define GRAPH_H
#include <set>
#include "vertex.h"

class Graph
{
private:
    std::set<Vertex *> vertexs;
public:
    Graph();
    Vertex * findVertex(int v);
    bool addVertex(int v);
    bool removeVertex(int v);
    bool addEdge(int head, int tail);
    bool removeEdge(int head, int tail);
};

#endif // GRAPH_H
