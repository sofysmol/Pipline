#ifndef UOGRESPONCE_H
#define UOGRESPONCE_H
#include <QString>

class UogResponce
{
public:
    UogResponce(int id, QString name, double uog);
    int id;
    QString name;
    double uog;
};

#endif // UOGRESPONCE_H
