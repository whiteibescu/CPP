#include "TempEmployee.h"

void TempEmployee::inputEmployee()
{
	Employee::inputEmployee();
	cout << "��� ���� �Է� : ";
	cin >> this->pay;
}
void TempEmployee::showEmployee()
{
	Employee::showEmployee();
	cout << "��� ���� : " << this->pay << endl;
	cout << "���� : " << calcPay() << endl;
}
int TempEmployee::calcPay()
{
	return this->pay / 12;
}
