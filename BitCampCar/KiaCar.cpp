#include "KiaCar.h"
#include <iostream>
#include <ctime>	// time.h
#include <cstdlib>	// stdlib.h
#include <windows.h>

using namespace std;

KiaCar::KiaCar(string companyName)
{
	srand((unsigned int)time(NULL));
	this->score = 0;
	this->companyName = companyName;
}
void KiaCar::driver()
{
	int num = rand() % K_DRIVER_SKILL
				+ K_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME -
		(num * BASIC_MULTIPLE_NUM));
	cout << "KiaCar::�Ų����� ����ȴ�~" << endl;
}
void KiaCar::accel()
{
	int num = rand() % K_ACCEL_SKILL
					+ K_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME -
		(num * BASIC_MULTIPLE_NUM));
	cout << "KiaCar::�ε巴�� ���ӵȴ�~" << endl;
}
void KiaCar::brake()
{
	int num = rand() % K_BRAKE_SKILL
				+ K_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME -
		(num * BASIC_MULTIPLE_NUM));
	cout << "KiaCar::�ε巴�� ������ �ɸ���~" << endl;
}
int KiaCar::getScore()
{
	return this->score;
}
string KiaCar::getCompanyName()
{
	return this->companyName;
}