#ifndef TREESERVICE_H
#define TREESERVICE_H


class TreeService
{
public:
    static TreeService * getInstance();
private:
    static TreeService * instance;
    TreeService();
};

#endif // TREESERVICE_H
