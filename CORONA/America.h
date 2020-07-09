#pragma once
#include "Corona.h"

#define A_BASIC_MASK_NUM 10
#define A_COUNTRY_MASK_NUM 100
#define A_BASIC_INFECTEE_NUM 20
#define A_COUNTRY_INFECTEE_NUM 70

class America :
    public Corona
{

public:
    America();
    virtual void maskQuantity();
    virtual void infectee();
    virtual int getMask_NUM();
    virtual int getInfected_NUM();
    virtual int getSavedPopulation();
};

