#include "uogservice.h"
#include <numeric>
using namespace std;
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

QVector<QVector<double>> UogService::createAlternativeMatrix(int criterionId ) //список альтернатив
{
    //выбераем поле по критерию


}

void UogService::createListAlternativeMatrix() //список критериев из дерева
{

}

QVector<double> UogService::calcUog(){
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

void UogService::createListResponse()
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

QList<UogResponce> UogService::getResults()
{
        UogService::createListResponse();
        storage->update(results);
        return results;
}
