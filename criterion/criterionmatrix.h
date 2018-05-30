#ifndef CRITERIONMATRIX_H
#define CRITERIONMATRIX_H
#include <QVector>
#include <QList>

class CriterionMatrix
{
public:
    static CriterionMatrix * getInstance();
    QVector<QVector<double>> matrix;
    //QList<QString> indexes;
    void full (QVector<QVector<double>> matrix);
    QVector<double> getEigenvector();
    bool checkConsistency();        //проверка ИС
private:
    CriterionMatrix();
    static CriterionMatrix * instance;
    QVector<double> eigenvector;    //вектор приоритетов
    double index_consistency;       //индекс согласованности
    void calcEigenvector();
    void calcIndex();
};

#endif // CRITERIONMATRIX_H
