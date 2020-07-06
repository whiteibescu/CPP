#include "Developer.h"

Developer::Developer(string name, int age,
	int nComputer, int nLanguage)
	:ComputerEngineer(name, age, nComputer)
{
	this->nLanguage = nLanguage;
	cout << "Developer ������ ȣ��" << endl;
}
Developer::~Developer()
{
	cout << "Developer �Ҹ��� ȣ��" << endl;
}

void Developer::neverEndingStudy()
{
	cout << this->name << "�� �� ���θ� �Ѵ�" << endl;
}
void Developer::sleep()
{
	cout << this->name << "�� �ʰ� �� ���� �ִ�" << endl;
}
void Developer::overTime()
{
	ComputerEngineer::overTime();
	cout << "������ �޽��� ������" << endl;
}
void Developer::info()
{
	ComputerEngineer::info();
	cout << this->name << "�� ����ϴ� �� " <<
		    this->nLanguage << "�����̴�" << endl;
}