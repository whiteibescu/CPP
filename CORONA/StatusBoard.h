#pragma once
#include "Corona.h"

class StatusBoard
{
private:
	//int newInfected;
	Corona* corona = NULL;
public:
	StatusBoard(Corona* pcorona = NULL);

private:
	void statusMask();
	void statusInfectee();
	
public:
	void beforeTotalStatus(int left, int top);
	void afterTotalStatus(int left, int top);	
	void setCorona(Corona* pcorona);

};

