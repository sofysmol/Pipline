#ifndef CRITERIONMATRIX_H
#define CRITERIONMATRIX_H
#include <QVector>
#include <QList>

class CriterionMatrix
{
public:
    QVector<QVector<float>> matrix;
    QList<QString> indexes;
    CriterionMatrix();
};

#endif // CRITERIONMATRIX_H
