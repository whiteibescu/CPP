#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <combaseapi.h>

#define BASIC_MASK_NUM 10
#define COUNTRY_MASK_NUM 100
#define BASIC_INFECTEE_NUM 50
#define COUNTRY_INFECTEE_NUM 100

using namespace std;

interface Corona
{
	int Population;
	int Mask;
	int Infected;
	string CountryName;
	
	virtual void maskQuantity() = 0;
	virtual void infectee() = 0;
	virtual int getMask_NUM() = 0;
	virtual int getInfected_NUM() = 0;
	virtual int getSavedPopulation() = 0;
};


