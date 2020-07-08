#include "America.h"


America::America()
{
	srand((unsigned int)time(NULL));//턴마다 난수생성
	this->Population = 200;
	this->Mask = 50;
	this->Infected = 0;
	this->CountryName = "America";
}

void America::maskQuantity()
{
	int num = rand() % A_COUNTRY_MASK_NUM + A_BASIC_MASK_NUM;
	this->Mask += num;
	

}
void America::infectee()
{
	int num = rand() % A_COUNTRY_INFECTEE_NUM + A_BASIC_INFECTEE_NUM;
	this->Infected += num;
	

}

int America::getMask_NUM()
{
	maskQuantity();
	cout << "getMask_NUM" << Mask << endl;
	return this->Mask;
}

int America::getInfected_NUM()
{
	return this->Infected;
}