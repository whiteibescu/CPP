#include "Korea.h"

Korea::Korea()
{
	srand((unsigned int)time(NULL));//턴마다 난수생성
	this->Population = 300;
	this->Infected = 50;
	this->CountryName = "Korea";
}

void Korea::infectee()
{
	int num = rand() % K_COUNTRY_INFECTEE_NUM + K_BASIC_INFECTEE_NUM;
	this->Infected += num;	
}

int Korea::getInfected_NUM() 
{
	infectee();
	return this->Infected;
}