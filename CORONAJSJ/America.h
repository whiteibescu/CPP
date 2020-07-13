#pragma once
#include "Corona.h"

#define A_BASIC_INFECTEE_NUM 70
#define A_COUNTRY_INFECTEE_NUM 100

class America : public Corona
{
public:
    America();
    virtual void infectee();
    virtual int getInfected_NUM();
};

