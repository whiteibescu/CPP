#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <combaseapi.h>

using namespace std;

interface Corona						// �������̽� �ڷγ�
{
	double Population;					// �α�(�Ǽ���)
	double Infected;   					// ������(�Ǽ���)
	string CountryName;					// ������(���ڿ�)
	
	virtual void infectee() = 0;		// ���� ������ ���� �Լ�
	virtual int getInfected_NUM() = 0;	// ���� ������ ���� �Լ� -> Ŭ���� Infected ������ �Ѱ��ִ� ������ �ϴ� �Լ�
};


