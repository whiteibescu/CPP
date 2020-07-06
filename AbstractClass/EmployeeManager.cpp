#include "EmployeeManager.h"
#include "RegularEmployee.h"
#include "TempEmployee.h"
#include "DailyEmployee.h"
#include <iostream>

using namespace std;

void EmployeeManager::showMenu()
{
	cout << "1. ����Է�" << endl;
	cout << "2. �����ü���" << endl;
	cout << "3. ���α׷� ����" << endl;
}
int EmployeeManager::getSelNum()
{
	int num = 0;
	cout << "�޴��� ���� >> ";
	cin >> num;
	return  num;
}
void EmployeeManager::insertEmployee()
{
	if (this->empNum == EMP_NUM) {
		// �� �̻� �Է� ���ؿ�
		return;
	}

	cout << "---��� ������ �����ϼ���---" << endl;
	cout << "1. ������" << endl;
	cout << "2. �ӽ���" << endl;
	cout << "3. �Ͽ���" << endl;
	int sel = getSelNum();

	if (sel == 1) {
		RegularEmployee* regularEmp =
			new RegularEmployee();
		regularEmp->inputEmployee();

		this->employee[this->empNum] = regularEmp;
		this->empNum++;
	}
	else if (sel == 2) {
		TempEmployee* tempEmp =
			new TempEmployee();
		tempEmp->inputEmployee();

		this->employee[this->empNum] = tempEmp;
		this->empNum++;
	}
	else if (sel == 3) {
		DailyEmployee* dailyEmp =
			new DailyEmployee();
		dailyEmp->inputEmployee();

		this->employee[this->empNum] = dailyEmp;
		this->empNum++;
	}
	else {
		// �߸� �Է�
	}
}
void EmployeeManager::showAllEmployee()
{
	//Employee �迭�� this->empNum���� ��� ���
}