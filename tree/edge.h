#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

namespace tree {

template <class V>
class Edge {

public:
    Edge(Vertex<V> *src = nullptr, Vertex<V> *dst = nullptr);
    Edge(const Edge<V> &other);
    Edge() = delete;

    ~Edge();

    Edge<V> &operator=(const Edge<V> &right);

    void attachSrc(Vertex<V> *source);
    void attachDst(Vertex<V> *destination);

    Vertex<V> *deattachSrc();
    Vertex<V> *deattachDst();

    Vertex<V> *getSrc() const;
    Vertex<V> *getDst() const;

private:
    Vertex<V> *src;
    Vertex<V> *dst;
};

template <class V>
inline Edge<V>::Edge(Vertex<V> *src, Vertex<V> *dst)
  : src(src), dst (dst)
{
}

template <class V>
inline Edge<V>::Edge(const Edge<V> &other)
  : src(other.src), dst (other.dst)
{

}

template <class V>
inline Edge<V>::~Edge() {

}

template <class V>
inline Edge<V> & Edge<V>::operator=(const Edge<V> &right) {
    if (this == &right) {
        return *this;
    }
    this->edge = right.edge;
    this->src = right.src;
    this->dst = right.dst;

    return this;
}

template <class V>
inline void Edge<V>::attachSrc(Vertex<V> *source) {
    this->src = source;
}

template <class V>
inline void Edge<V>::attachDst(Vertex<V> *destination) {
    this->dst = destination;
}

template <class V>
inline Vertex<V> * Edge<V>::deattachSrc() {
    Vertex<V> *vertex = this->src;
    this->src = nullptr;

    return vertex;
}

template <class V>
inline Vertex<V> * Edge<V>::deattachDst() {
    Vertex<V> *vertex = this->dst;
    this->dst = nullptr;

    return vertex;
}

template <class V>
inline Vertex<V> * Edge<V>::getSrc() const {
    return this->src;
}

template <class V>
inline Vertex<V> * Edge<V>::getDst() const {
    return this->dst;
}


}
#endif // EDGE_H
