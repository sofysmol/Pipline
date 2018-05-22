#include "criterion.h"

Criterion::Criterion()
{

}

Criterion::Criterion(int id, QString name, float weight){
    this->id = id;
    this->name = name;
    this->weight = weight;
}
