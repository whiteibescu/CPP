#include "ToyotaCar.h"
#include <iostream>
#include <ctime>	// time.h
#include <cstdlib>	// stdlib.h
#include <windows.h>

using namespace std;

ToyotaCar::ToyotaCar(string companyName)
{
	srand((unsigned int)time(NULL));
	this->score = 0;
	this->companyName = companyName;
}
void ToyotaCar::driver()
{
	int num = rand() % T_DRIVER_SKILL
				+ T_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME -
		(num * BASIC_MULTIPLE_NUM));
	cout << "ToyotaCar::�ƺ��� �����Ѵ�. ����� ���ڴ�~" << endl;
}
void ToyotaCar::accel()
{
	int num = rand() % T_ACCEL_SKILL
				+ T_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME -
		(num * BASIC_MULTIPLE_NUM));
	cout << "ToyotaCar::�ƺ��� �� ��ƴ��.�� ����~" << endl;
}
void ToyotaCar::brake()
{
	int num = rand() % T_BRAKE_SKILL
		+ T_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME -
		(num * BASIC_MULTIPLE_NUM));
	cout << "ToyotaCar::�ƺ��� ���÷� �����.~" << endl;
}
int ToyotaCar::getScore()
{
	return this->score;
}
string ToyotaCar::getCompanyName()
{
	return this->companyName;
}