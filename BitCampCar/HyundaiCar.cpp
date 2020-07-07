#include "HyundaiCar.h"
#include <iostream>
#include <ctime>	// time.h
#include <cstdlib>	// stdlib.h
#include <windows.h>

using namespace std;

HyundaiCar::HyundaiCar(string companyName)
{
	srand((unsigned int)time(NULL));
	this->score = 0;
	this->companyName = companyName;
}
void HyundaiCar::driver()
{
	int num = rand() % H_DRIVER_SKILL
					+ H_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME -
		(num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::�� ����ȴ�~" << endl;
}
void HyundaiCar::accel()
{
	int num = rand() % H_ACCEL_SKILL
					+ H_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME -
		(num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::�� ���ӵȴ�~" << endl;
}
void HyundaiCar::brake()
{
	int num = rand() % H_BRAKE_SKILL
					+ H_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - 
		(num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::�ε巴�� �����~" << endl;
}
int HyundaiCar::getScore()
{
	return this->score;
}
string HyundaiCar::getCompanyName()
{
	return this->companyName;
}