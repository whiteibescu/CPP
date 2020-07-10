#include "China.h"

China::China()
{
	srand((unsigned int)time(NULL));//턴마다 난수생성
	this->Population = 700;
	this->Mask = 0;
	this->Infected = 0;
	this->CountryName = "China";
}

void China::maskQuantity()
{
	int num = /*rand() % C_COUNTRY_MASK_NUM +*/ C_BASIC_MASK_NUM;
	this->Mask = num;
}
void China::infectee()
{
	int num = /*rand() % C_COUNTRY_INFECTEE_NUM +*/ C_BASIC_INFECTEE_NUM;
	this->Infected = num;
	
}

int China::getMask_NUM()
{	
	maskQuantity();
	return this->Mask;
}
int China::getInfected_NUM()
{
	infectee();
	return this->Infected;
	
}

int China::getSavedPopulation()
{
	int result;
	result = getInfected_NUM() - getMask_NUM();
	return result;
}
