#pragma once
#include "Corona.h"

class StatusBoard								// ��� Ŭ����
{
private:
	Corona* corona = NULL;						// �ڷγ� Ŭ���� ��

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

