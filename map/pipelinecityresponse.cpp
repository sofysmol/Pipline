#include "pipelinecityresponse.h"

PipelineCityResponse::PipelineCityResponse(int id,
                                           bool isAdded,
                                           QString name,
                                           bool gasified)
{
    this->id = id;
    this->isAdded = isAdded;
    this->name = name;
    this->gasified = gasified;
}
