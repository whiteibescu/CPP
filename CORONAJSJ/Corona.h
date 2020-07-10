#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <combaseapi.h>

using namespace std;

interface Corona						// �������̽� �ڷγ�
{
	int Population;						// �α�(������)
	int Mask;							// ����ũ(������)
	int Infected;   					// ������(������)
	string CountryName;					// ������(���ڿ�)
	
	virtual void maskQuantity() = 0;	// ���� ����ũ ���� �Լ�
	virtual void infectee() = 0;		// ���� ������ ���� �Լ�
	virtual int getMask_NUM() = 0;		// ���� ����ũ ���� �Լ� -> Ŭ���� Mask ������ �Ѱ��ִ� ������ �ϴ� �Լ�
	virtual int getInfected_NUM() = 0;	// ���� ������ ���� �Լ� -> Ŭ���� Infected ������ �Ѱ��ִ� ������ �ϴ� �Լ�
};


