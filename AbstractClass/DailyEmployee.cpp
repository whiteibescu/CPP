#include "DailyEmployee.h"

void DailyEmployee::inputEmployee()
{
	Employee::inputEmployee();
	cout << "�ñ� �Է�: ";
	cin >> this->perTimePay;
	cout << "���� �ð� �Է�: ";
	cin >> this->workHour;

	DailyEmployee::showEmployee();
}
void DailyEmployee::showEmployee()
{
	Employee::showEmployee();
	cout << "�ñ� : " << this->perTimePay << endl;
	cout << "���� �ð� : " << this->workHour << endl;
	cout << "���� : " << calcPay() << endl;
}
int DailyEmployee::calcPay()
{
	return this->perTimePay * this->workHour;
}