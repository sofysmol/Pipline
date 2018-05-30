#ifndef TREEITERATOR_H
#define TREEITERATOR_H

namespace tree {

template <class T>
class Tree;

template<class V>
class TreeIterator {

    friend class Tree<V>;

    template <class _V>
    friend bool operator==(const TreeIterator<_V> &left, const TreeIterator<_V> &right);
    template <class _V>
    friend bool operator!=(const TreeIterator<_V> &left, const TreeIterator<_V> &right);

    template <class _V>
    friend TreeIterator<_V> &operator++(TreeIterator<_V> &g);

    template <class _V>
    friend TreeIterator<_V> &operator+(TreeIterator<_V> &g, int i);

public:
    TreeIterator(const TreeIterator<V> *other)
        : tree(other->tree), index(other->index)
    {
    }

    TreeIterator<V> &first() {
        index = 0;
        return *this;
    }

    TreeIterator<V> &end() {
        index = tree->nodes.size();
        return *this;
    }

    bool isEnd() {
        return (index == tree->nodes.size());
    }

    void next() {
        index++;
    }

    V *current() {
        return tree->nodes[index]->getData();
    }

    V &operator*() {
        return *(tree->nodes[index]->getData());
    }

private:
    TreeIterator(const Tree<V> *g, size_t i = 0)
        : tree(g), index(i)
    {
    }

    const Tree<V> *tree;
    size_t index;
};

template <class V>
bool operator==(const TreeIterator<V> &left, const TreeIterator<V> &right) {
    return (left.index == right.index);
}

template <class V>
bool operator!=(const TreeIterator<V> &left, const TreeIterator<V> &right) {
    return (left.index != right.index);
}

template <class V>
TreeIterator<V> &operator++(TreeIterator<V> &g) {
    g.index++;
    return g;
}

template <class V>
TreeIterator<V> &operator+(TreeIterator<V> &g, int i) {
    TreeIterator<V> *it = new TreeIterator<V>(&g);
    it->index = it->index + i;
    return it;
}

}
#endif // TREEITERATOR_H
