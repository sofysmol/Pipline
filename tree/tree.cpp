#include "graph.h"

Graph::Graph()
{
}
Vertex * Graph::findVertex(int v){
    for(auto it : vertexs){
        if(it->getValue() == v)
            return it;
    }
    return NULL;
}

bool Graph::addVertex(int v){
    Vertex * t = findVertex(v);
    if(t == NULL){
        return vertexs.insert(new Vertex(v)).second;
    }
    return false;
}

bool Graph::removeVertex(int v){
    Vertex * t = findVertex(v);
    if(t != NULL){
        for(auto r : t->getRev())
        {
            r->removeEdge(t);
        }
        vertexs.erase(t);
        return true;
    }
    return false;
}

bool Graph::addEdge(int head, int tail){
    Vertex * headV = findVertex(head);
    Vertex * tailV = findVertex(tail);
    if(headV != NULL && tailV != NULL){
        headV->addEdge(tailV);
        return true;
    }
    return false;
}

bool Graph::removeEdge(int head, int tail){
    Vertex * headV = findVertex(head);
    Vertex * tailV = findVertex(tail);
    if(headV != NULL && tailV != NULL){
        headV->removeEdge(tailV);
        return true;
    }
    return false;
}
