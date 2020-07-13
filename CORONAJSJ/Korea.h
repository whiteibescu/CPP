#pragma once
#include "Corona.h"

#define K_BASIC_INFECTEE_NUM 50
#define K_COUNTRY_INFECTEE_NUM 100

class Korea : public Corona
{
public:
    Korea();
    virtual void infectee();
    virtual int getInfected_NUM();
};

