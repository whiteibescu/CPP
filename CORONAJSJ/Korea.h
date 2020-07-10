#pragma once
#include "Corona.h"

#define K_BASIC_MASK_NUM 10
#define K_COUNTRY_MASK_NUM 100
#define K_BASIC_INFECTEE_NUM 20
#define K_COUNTRY_INFECTEE_NUM 100

class Korea : public Corona
{

public:
    Korea();
    virtual void maskQuantity();
    virtual void infectee();
    virtual int getMask_NUM();
    virtual int getInfected_NUM();

};

