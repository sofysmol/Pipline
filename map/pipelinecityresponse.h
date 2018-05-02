#ifndef PIPELINECITYRESPONSE_H
#define PIPELINECITYRESPONSE_H
#include <QString>

class PipelineCityResponse
{
public:
    PipelineCityResponse(int id,
                        bool isAdded,
                        QString name,
                        bool gasified);
    int id;
    bool isAdded;
    QString name;
    bool gasified;
};

#endif // PIPELINECITYRESPONSE_H
