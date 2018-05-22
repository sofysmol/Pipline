#ifndef CRITERION_H
#define CRITERION_H
#include <QString>

class Criterion
{
public:
    Criterion();
    int id;
    QString name;
    float weight;
    Criterion(int id, QString name, float weight);
};

#endif // CRITERION_H
