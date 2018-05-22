#ifndef ALTERNATIVESMATRIX_H
#define ALTERNATIVESMATRIX_H
#include <QList>
#include <QString>
#include <QVector>

class AlternativesMatrix
{
public:
    QVector<QVector<float>> matrix;
    QList<QString> indexes;
    AlternativesMatrix();
};

#endif // ALTERNATIVESMATRIX_H
