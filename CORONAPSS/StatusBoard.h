#pragma once
#include "Corona.h"

class StatusBoard
{
private:
	Corona* corona = NULL;
public:
	StatusBoard(Corona* pcorona = NULL);

private:
	void statusMask();
	void statusInfectee();
	void dangerLevel();
public:
	void TotalStatus(int left, int top);	
	void setCorona(Corona* pcorona);
};

