#include "Employee.h"

void Employee::inputEmployee()
{
	cout << "�̸��� �Է�: ";
	cin >> this->name;
	cout << "����� �Է�: ";
	cin >> this->companyNum;
}
void Employee::showEmployee()
{
	cout << "�̸� : " << this->name << endl;
	cout << "��� : " << this->companyNum << endl;
}