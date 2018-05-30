#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <algorithm>
#include <iostream>

#include "edge.h"

namespace tree {


template <class V>
class Edge;

template <class V>
class Vertex {

public:
    Vertex(V *data);
    Vertex(const V &data);
    Vertex(const Vertex<V> &other);
    Vertex() = delete;

    ~Vertex();
    Vertex<V> &operator=(const Vertex<V> &right);

    V *getData() const;
    void setData(V *data);

private:
    V *data;
};

template <class V>
inline Vertex<V>::Vertex(V *data)
  : data(data)
{
}

template <class V>
inline Vertex<V>::Vertex(const V &data) {
    this->data = new V(data);
}

template <class V>
inline Vertex<V>::Vertex(const Vertex<V> &other)
  : data(other.data)
{
}

template <class V>
inline Vertex<V>::~Vertex() {
    delete data;
}

template <class V>
inline Vertex<V> & Vertex<V>::operator=(const Vertex<V> &right) {
    if (this == &right) {
        return *this;
    }
    this->data = right.data;

    return *this;
}

template <class V>
inline V * Vertex<V>::getData() const {
    return this->data;
}

template <class V>
inline void Vertex<V>::setData(V *data) {
    this->data = data;
}


}
#endif // VERTEX_H
