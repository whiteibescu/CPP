#include "ComputerEngineer.h"

ComputerEngineer::ComputerEngineer(string name, int age,
									int nComputer)
	:Human(name, age)
{
	this->nComputer = nComputer;
	cout << "ConputerEngineer ������ ȣ��" << endl;
}

ComputerEngineer::~ComputerEngineer()
{
	cout << "ComputerEngineer �Ҹ��� ȣ��" << endl;
}

void ComputerEngineer::overTime()
{
	cout << this->name << "�� �߱��� ���� �Ѵ�" << endl;
}
void ComputerEngineer::info()
{
	Human::info();
	cout << this->name << "�� ��ǻ�͸� " <<
		this->nComputer << "�� ������ �ִ�" << endl;
}