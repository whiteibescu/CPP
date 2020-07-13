#include "America.h"

America::America()
{
	srand((unsigned int)time(NULL));//턴마다 난수생성
	this->Population = 500;
	this->Infected = 200;
	this->CountryName = "America";
}

void America::infectee()
{
	int num = rand() % A_COUNTRY_INFECTEE_NUM + A_BASIC_INFECTEE_NUM;
	this->Infected += num;
}

int America::getInfected_NUM()
{
	infectee();
	return this->Infected;
}