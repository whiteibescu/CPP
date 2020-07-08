#include "China.h"

China::China()
{
	srand((unsigned int)time(NULL));//턴마다 난수생성
	this->Population = 1000;
	this->Mask = 100;
	this->Infected = 0;
	this->CountryName = "China";
}

void China::maskQuantity()
{
	int num = rand() % C_COUNTRY_MASK_NUM + C_BASIC_MASK_NUM;
	cout << "maskQuantity num" << num << endl;
	this->Mask += num;
	cout << "maskQuantity Mask" << Mask << endl;
}
void China::infectee()
{
	int num = rand() % C_COUNTRY_INFECTEE_NUM + C_BASIC_INFECTEE_NUM;
	this->Infected += num;
}

int China::getMask_NUM()
{	
	maskQuantity();
	cout << "getMask_NUM" << Mask << endl;
	return this->Mask;
}
int China::getInfected_NUM()
{
	return this->Infected;
}
