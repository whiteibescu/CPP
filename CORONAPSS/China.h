#pragma once
#include "Corona.h"

#define C_BASIC_MASK_NUM 10
#define C_COUNTRY_MASK_NUM 100
#define C_BASIC_INFECTEE_NUM 10
#define C_COUNTRY_INFECTEE_NUM 200

class China :public Corona
{

public:
    China();
    virtual void maskQuantity();
    virtual void infectee();
    virtual int getMask_NUM();
    virtual int getInfected_NUM();
    virtual int getSavedPopulation();
};


