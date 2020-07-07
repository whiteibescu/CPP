#pragma once
#include "Corona.h"

#define A_BASIC_MASK_NUM 10
#define A_COUNTRY_MASK_NUM 100
#define A_BASIC_INFECTEE_NUM 50
#define A_COUNTRY_INFECTEE_NUM 100

class America :
    public Corona
{
public:
    America();
    virtual void maskQuantity();
    virtual void infectee();

};

