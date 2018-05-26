#include "uogservice.h"
#include <numeric>
#include <QJsonDocument>
#include <QJsonObject>
using namespace std;
using namespace System;
UogService::UogService()
{
    criterionstorage->CriterionStorage::getInstance();
    citystorage->CityStorage::getInstance();
    alternativeservice->AlternativesService::getInstance();
    storage->ResultsStorage::getInstance();
}

UogService* UogService::instance = 0;
UogService * UogService::getInstance() {
    if(!UogService::instance)
        UogService::instance = new UogService();
    return UogService::instance;
}

double UogService:: choosefield (City city, QString criterion)  //выбераем поле по критерию
{
    double a = 1.0;
    switch (criterion) {
    case 'relief':
        QString relief = city.relief;
        if (relief == 'Равнина') a = 9.0;
        else if (relief == 'Возвышенность') {
            a = 5.0;
        }
        else a = 3.0;
        break;
    case 'piplineMaterial':
        QString material =  city.piplineMaterial;
        if (material == 'Сталь') a = 9.0;
        else if (material == 'Чугун') {
            a = 5.0;
        }
        else a = 3.0;
        break;
    case 'strenght':
        a = (double) city.strenght;
        break;
    case 'hasImportantFacilities':
        bool b = city.hasImportantFacilities;
        if (b) a = (double) 2;
        break;
    case 'hasDifficultObjects':
        bool myb = city.hasDifficultObjects;
        if (myb) a = (double) 2;
        break;
    default:
        break;
    }
    return a;
}

AlternativesMatrix UogService::createAlternativeMatrix(QString criterion, int id_matrix) // создание матрицы альтернатив по критерию
{
    AlternativesMatrix alternativematrix (id_matrix);
    QVector<QVector<double>> tmp_matrix;
    QList<QString> listidcity = alternativeservice->getListCity();
    for (int i=0; i < listidcity.size(); i++)
    {
        QVector<double> tmp_vector;
        double a_1 = UogService::choosefield(citystorage->get(listidcity[i]), criterion); //выбераем поле по критерию
        for(int j=0; j < listidcity.size(); j++)
        {
           double a_2 = UogService::choosefield(citystorage->get(listidcity[j]), criterion);
            tmp_vector.push_back(a_1/a_2);
        }
        tmp_matrix.push_back(tmp_vector);
    }
    alternativematrix.matrix = tmp_matrix;
    alternativematrix.getEigenvector();
    alternativematrix.checkConsistency();
    return alternativematrix;

}

void UogService::createListAlternativeMatrix()      //создание списка матриц альтернатив
{
    if (listalternativematrix.isEmpty() == false) listalternativematrix.clear();

    for(int i=0; i < criterionstorage->list().size(); i++)
    {
        Criterion tmp_criterion = criterionstorage->list()[i];
        QString criterion = tmp_criterion.name;
        AlternativesMatrix tmp_matrix  = createAlternativeMatrix(criterion, i);       // создание матрицы альтернатив по критерию
        listalternativematrix.push_back(tmp_matrix);
    }
}

QVector<AlternativesMatrix> UogService::getListAlternativeMatrix()      // предоставление списка матриц альтернатив
{
    UogService::createListAlternativeMatrix();      //создание списка матриц альтернатив
    return listalternativematrix;
}

QVector<double> UogService::calcUog()
{
    QVector<double> uogs;
    QVector<double> vectorcriterion = criterionstorage->getMatrix().getEigenvector(); // собственный вектор матрицы критериев

    for (int i=0; i<criterionstorage->list().size(); i++)
    {
        QVector<double> tmp;                //произведение компанент векторов альтернатив и вектора критериев
        for (int j=0; j<listalternativematrix.size(); j++)
        {
            double a = listalternativematrix[j].getEigenvector()[i];
           tmp.push_back( a * vectorcriterion[i]);
        }
        uogs.push_back(accumulate(tmp.begin(), tmp.end(),0.0););
    }
}

void UogService::createListResponse()           //создание ответа в виде списка UogResponce
{
    QVector<double> uogs = UogService::calcUog();
    QList<QString> idcity =alternativeservice->getListCity();

    for(int i=0; listalternativematrix.size();i++)
    {
        int id = idcity[i].toInt();
        QString name = citystorage->get(id).name;
        UogResponce tmp = UogResponce(id, name, uogs[i]);
        results.push_back(tmp);
    }
}

QList<UogResponce> UogService::getResults() // результаты алгоритма
{
        UogService::createListResponse();   //создание ответа в виде списка UogResponce
        storage->update(results);
        return results;
}
