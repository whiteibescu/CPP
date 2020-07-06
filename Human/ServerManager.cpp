#include "ServerManager.h"

ServerManager(string name, int age,
	int nComputer, int nManagedServer)
	:ComputerEngineer(name, age, nComputer)
{
	this->nManagedServer = nManagedServer;
	cout << "ServerManager 생성자 호출" << endl;
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
