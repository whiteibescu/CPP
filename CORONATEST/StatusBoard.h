#pragma once
#include "Corona.h"

class StatusBoard
{
private:
	Corona* corona = NULL;
	int newInfected;
public:
	StatusBoard(Corona* pcorona = NULL);

private:
	
public:
	void firstTotalStatus(int left, int top);
	void TotalStatus(int left, int top);
	void setCorona(Corona* pcorona);
	void Temp();
};

