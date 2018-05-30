#include "criterionmatrix.h"
#include <math.h>
#include <numeric>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
using namespace std;
CriterionMatrix::CriterionMatrix()
{

}
CriterionMatrix* CriterionMatrix::instance = 0;
CriterionMatrix * CriterionMatrix::getInstance() {
    if(!CriterionMatrix::instance)
        CriterionMatrix::instance = new CriterionMatrix();
    return CriterionMatrix::instance;
}

void CriterionMatrix::full(QVector<QVector<double> > inmatrix)
{
    for (int i=0; i<inmatrix.size();i++){
        QVector <double> tmp;
        for(int j=0; j<inmatrix.size();j++){
            tmp.push_back(inmatrix[i][j]);
        }
        matrix.push_back(tmp);
    }
}

void CriterionMatrix::calcEigenvector()
{
    QVector<double> geometricmean; //вектор средних геометрических
    double mult;
    double exp = 1/(double)matrix.size();
    //расчет средних геометрических в каждой строке матрицы
    for(int i=0; i<matrix.size();i++){
        mult = 1;
        for(int j=0; j<matrix.size();j++){
            mult = mult*matrix[i][j];
        }
        double a_i = pow(mult, exp);
        geometricmean.push_back(a_i);
    }
    //расчет суммы средних геометрических
    double sum = accumulate(geometricmean.begin(), geometricmean.end(),0.0);
    //расчет компанентов вектора приоритетов
    for (int i=0; i<geometricmean.size();i++){
        eigenvector.push_back(geometricmean[i]/sum);
    }
}
QVector<double> CriterionMatrix::getEigenvector(){
    CriterionMatrix::calcEigenvector();
    return eigenvector;
}

void CriterionMatrix::calcIndex(){
    double lambda = 0.0;//собственное значение матрицы
    QVector<double> lambdis;
    for (int j=0;j<matrix.size();j++){
        double sum = 0;
        //расчет суммы элементов по столбцам
        for(int i=0;i<matrix.size();i++){
            sum = sum + matrix[i][j];
        }
        lambdis.push_back( sum*eigenvector[j] );
    }
    lambda = accumulate(lambdis.begin(), lambdis.end(), 0.0);
    //расчет ИС
    index_consistency = (lambda - (double) matrix.size() )/ ((double) matrix.size() - 1.0);
}


bool CriterionMatrix::checkConsistency(){
    CriterionMatrix::calcIndex();

    QFile file ("/home/kristina/QT/Projects/TestCriterion/PSS.json");
    file.open(QIODevice::ReadOnly);
    QByteArray dataFile = file.readAll();
    file.close();
    QJsonDocument doc (QJsonDocument::fromJson(dataFile));
    QJsonObject json = doc.object();
    QString size = QString::number(matrix.size());
    double pss = json.value(size).toDouble();
    double oc = index_consistency/pss; //отношение согласованности
    //проверка ОС
    if (oc <= 0.1){
        return true;
    }
    else return false;
}
