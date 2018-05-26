#ifndef CRITERIONSTORAGE_H
#define CRITERIONSTORAGE_H
#include <QMap>
#include <QList>
#include "criterionmatrix.h"
#include "criterion.h"

class CriterionStorage
{
public:
    static CriterionStorage * getInstance();
    void add(int id, Criterion v);
    void update(int id, Criterion v);
    void remove(int id);
    bool contains(int id);
    Criterion get(int id);
    QList<Criterion> list();
    CriterionMatrix getMatrix();
    void editMatrix(CriterionMatrix matrix);

private:
    QMap<int, Criterion>* storage;
    CriterionMatrix  * matrix;
    static CriterionStorage * instance;
    CriterionStorage();
};

#endif // CRITERIONSTORAGE_H
