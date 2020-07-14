#pragma once
#include "Corona.h"

#define COUNTRY_MASK_NUM 100
#define BASIC_MASK_NUM 200

class StatusBoard			
{
private:
	Corona* corona = NULL;	// �ڷγ� Ŭ���� ��

public:
	StatusBoard(Corona* pcorona = NULL);	//������ ��ü�� ��������鼭
	//����ȴ�
private:
	void statusInfectee();
	void dangerLevel();
	void dangerLevelBar();
	
public:					
	void TotalStatus(int left, int top);
	void setCorona(Corona* pcorona);	
	int getMaskQuantity();
};

