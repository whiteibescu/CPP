#pragma once
#include <iostream>
using namespace std;

/* ���� ���� �Լ��� 1���̻��� ������
�߻� Ŭ����(Abstract Class)�� �θ���
�� Ŭ������ ��ü�� ���� �� ����

������ ����� ������ �Ѵ�
*/
class Employee
{
private:
	string name;
	string companyNum;
public:
	virtual void inputEmployee();
	virtual void showEmployee();
	virtual int calcPay() = 0;	// ���� ���� �Լ�
};

