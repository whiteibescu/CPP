#pragma once
#include "Corona.h"

class StatusBoard								// 계산 클래스
{
private:
	Corona* corona = NULL;						// 코로나 클래스 값

public:
	StatusBoard(Corona* pcorona = NULL);		// 
	int statusinfectee;
public:
	int statusMask();							// 
	void statusInfectee();
	void dangerLevel();
	
public:
	void TotalStatus(int left, int top);
	void TotalStatus1(int left, int top,int x);
	void setCorona(Corona* pcorona);	
	
};

