#include "ServerManager.h"

ServerManager::ServerManager(string name, int age,
	int nComputer, int nManagedServer)
	:ComputerEngineer(name, age, nComputer)
{
	this->nManagedServer = nManagedServer;
	cout << "ServerManager ������ ȣ��" << endl;
}
ServerManager::~ServerManager()
{
	cout << "ServerManager �Ҹ��� ȣ��" << endl;
}

void ServerManager::work()
{
	cout << this->name << "�� ���� �ҽÿ� ���ϱ�" << endl;
}
void ServerManager::info()
{
	ComputerEngineer::info();
	cout << this->name << "�� �����ϴ� ��ǻ�� ����"
		<< this->nManagedServer << "���̴�" << endl;
}
