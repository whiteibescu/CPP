#pragma once
#include "Corona.h"

#define C_BASIC_MASK_NUM 10
#define C_COUNTRY_MASK_NUM 100
#define C_BASIC_INFECTEE_NUM 50
#define C_COUNTRY_INFECTEE_NUM 100

class China :public Corona
{
public:
    China();
    virtual void maskQuantity();
    virtual void infectee();

};


