#pragma once
#include "Corona.h"

#define COUNTRY_MASK_NUM 100
#define BASIC_MASK_NUM 100

class StatusBoard			
{
private:
	Corona* corona = NULL;	// 코로나 클래스 값

public:
	StatusBoard(Corona* pcorona = NULL);		
	int statusinfectee;
private:

	void statusInfectee();
	void dangerLevel();
	void dangerLevelBar();
	
public:					
	void TotalStatus(int left, int top);
	void setCorona(Corona* pcorona);	
	int getMaskQuantity();
};

