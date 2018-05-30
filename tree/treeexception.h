#ifndef TREEXCEPTION_H
#define TREEXCEPTION_H

namespace tree {

template <class V>
class TreeNodeExistException
{
public:
    TreeNodeExistException(const V &n) : node(n) { }

    const V &getNode() const {
        return node;
    }

private:
    const V &node;
};

template <class V>
class TreeNodeNotExistException {
public:
    TreeNodeNotExistException(const V &n) : node(n) { }

    const V &getNode() const {
        return node;
    }

private:
    const V node;
};

template <class V>
class TreeEdgeNotExistException
{
public:
    TreeEdgeNotExistException(const V &src, const V &dst)
        : src(src), dst(dst)
    { }

    const V &getSource() const {
        return src;
    }

    const V &getDestination() const {
        return dst;
    }

private:
    const V &src;
    const V &dst;
};

template <class V>
class TreeEdgeExistException
{
public:
    TreeEdgeExistException(const V &src, const V &dst)
        : src(src), dst(dst)
    { }

    const V &getSource() const {
        return src;
    }

    const V &getDestination() const {
        return dst;
    }

private:
    const V &src;
    const V &dst;
};


}
#endif // TREEXCEPTION_H
