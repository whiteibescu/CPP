#include "China.h"

China::China()
{
	srand((unsigned int)time(NULL));//턴마다 난수생성
	this->Population = 1000;
	this->Mask = 100;
	this->Infected = 0;
}

void China::maskQuantity()
{
	int num = rand() % C_COUNTRY_MASK_NUM + C_BASIC_MASK_NUM;
	this->Mask += num;
	cout << this->Mask << endl;

}
void China::infectee()
{
	int num = rand() % C_COUNTRY_INFECTEE_NUM + C_BASIC_INFECTEE_NUM;
	this->Infected += num;
}