#include "ServerManager.h"

ServerManager(string name, int age,
	int nComputer, int nManagedServer)
	:ComputerEngineer(name, age, nComputer)
{
	this->nManagedServer = nManagedServer;
	cout << "ServerManager ������ ȣ��" << endl;
}
~ServerManager()
{

}

void work()
{

}
void info()
{

}
