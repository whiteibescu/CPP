#include "China.h"

China::China()
{
	srand((unsigned int)time(NULL)); //턴마다 난수생성
	this->Population = 700;
	this->Infected = 500;
	this->CountryName = "China";
}

void China::infectee()
{
	int num = rand() % C_COUNTRY_INFECTEE_NUM + C_BASIC_INFECTEE_NUM;
	this->Infected += num; 
}

int China::getInfected_NUM()
{
	infectee();
	return this->Infected;
}