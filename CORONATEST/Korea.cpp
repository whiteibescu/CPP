#include "Korea.h"


Korea::Korea()
{
	srand((unsigned int)time(NULL));//턴마다 난수생성
	this->Population = 200;
	this->Mask = 0;
	this->Infected = 0;
	this->CountryName = "Korea";
}

void Korea::maskQuantity()
{
	int num = rand() % K_COUNTRY_MASK_NUM + K_BASIC_MASK_NUM;
	this->Mask += num;
	
}
void Korea::infectee()
{
	int num = rand() % K_COUNTRY_INFECTEE_NUM + K_BASIC_INFECTEE_NUM;
	this->Infected += num;
	
}

int Korea::getMask_NUM()
{
	maskQuantity();
	return this->Mask;
}
int Korea::getInfected_NUM() 
{
	infectee();
	return this->Infected;
}

int Korea::getSavedPopulation()
{
	int result;
	result = this->Population - getInfected_NUM() + getMask_NUM();
	return result;
}

