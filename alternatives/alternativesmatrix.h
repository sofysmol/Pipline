#ifndef ALTERNATIVESMATRIX_H
#define ALTERNATIVESMATRIX_H
#include <QList>
#include <QString>
#include <QVector>

class AlternativesMatrix
{
public:
    QVector<QVector<double>> matrix;
    //QList<QString> indexes;
    AlternativesMatrix();
    QVector<double> getEigenvector();
    bool checkConsistency();        //проверка ИС
private:
    QVector<double> eigenvector;    //вектор приоритетов
    double index_consistency;       //индекс согласованности
    void calcEigenvector();
    void calcIndex();
};

#endif // ALTERNATIVESMATRIX_H
