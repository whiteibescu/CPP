#pragma once
#include "Corona.h"

#define K_BASIC_INFECTEE_NUM 30
#define K_COUNTRY_INFECTEE_NUM 80

class Korea : public Corona
{
public:
    Korea();
    virtual void infectee();
    virtual int getInfected_NUM();
};

