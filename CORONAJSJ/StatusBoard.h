#pragma once
#include "Corona.h"

class StatusBoard								// ��� Ŭ����
{
private:
	Corona* corona = NULL;						// �ڷγ� Ŭ���� ��

public:
	StatusBoard(Corona* pcorona = NULL);		// 
	int statusinfectee;
private:

	void statusInfectee();
	void dangerLevel();
	void dangerLevelBar();
	
public:
	int statusMask();							// 
	void TotalStatus(int left, int top);
	//void TotalStatus1(int left, int top,int x);
	void setCorona(Corona* pcorona);	
	
};

