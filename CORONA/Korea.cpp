#include "Korea.h"


Korea::Korea()
{
	srand((unsigned int)time(NULL));//턴마다 난수생성
	this->Population = 200;
	this->Mask = 50;
	this->Infected = 0;
	this->CountryName = "Korea";
}

void Korea::maskQuantity()
{
	int num = rand() % K_COUNTRY_MASK_NUM + K_BASIC_MASK_NUM;
	this->Mask += num;
	cout << this->Mask << endl;
	
}
void Korea::infectee()
{
	int num = rand() % K_COUNTRY_INFECTEE_NUM + K_BASIC_INFECTEE_NUM;
	this->Infected += num;
	
}

int Korea::getMask_NUM()
{
	return this->Mask;
}
int Korea::getInfected_NUM() 
{
	return this->Infected;
}

