#ifndef VERTEX_H
#define VERTEX_H
#include <set>

class Vertex
{
private:
    int value;
    std::set<Vertex *> adj;
    std::set<Vertex *> rev;
public:
    Vertex(int value);
    void addEdge(Vertex* v);
    bool removeEdge(Vertex *v);
    bool edgeExists(Vertex *v);
    std::set<Vertex*> getRev();
    int getValue();
};

#endif // VERTEX_H
