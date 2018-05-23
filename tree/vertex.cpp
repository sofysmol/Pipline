#include "vertex.h"

Vertex::Vertex(int value)
{
    this->value = value;
}

void Vertex::addEdge(Vertex* v){
    if(v != NULL)
    {
        adj.insert(v);
        v->rev.insert(v);
    }
}

bool Vertex::removeEdge(Vertex *v){
    if(v != NULL){

        typename std::set<Vertex *>::iterator pos = adj.find(v);

        if(pos == adj.end())
        {
            return false;
        }

        this->adj.erase(pos);
        v->rev.erase(v->rev.find(this));

        return true;
    } else return false;
}

bool Vertex::edgeExists(Vertex *v){
    if(v != NULL){
        return adj.find(v) != adj.end();
    } else return false;
}

int Vertex::getValue(){
    return value;
}

std::set<Vertex*> Vertex::getRev(){
    return rev;
}
