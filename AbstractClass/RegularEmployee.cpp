#include "RegularEmployee.h"

void RegularEmployee::inputEmployee()
{
	Employee::inputEmployee();
	cout << "���� �Է�: ";
	cin >> this->annualPay;
	cout << "���ʽ� �Է�: ";
	cin >> this->bonus;
}
void RegularEmployee::showEmployee()
{
	Employee::showEmployee();
	cout << "���� : " << this->annualPay << endl;
	cout << "���ʽ� : " << this->bonus << endl;
	cout << "���� : " << calcPay() << endl;
}
int RegularEmployee::calcPay()
{
	return (this->annualPay + this->bonus)/12;
}