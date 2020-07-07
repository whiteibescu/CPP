#include "Korea.h"


Korea::Korea()
{
	srand((unsigned int)time(NULL));//턴마다 난수생성
	this->Population = 200;
	this->Mask = 50;
	this->Infected = 0;
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

