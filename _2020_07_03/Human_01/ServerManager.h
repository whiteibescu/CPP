#pragma once
#include "ComputerEngineer.h"
#include <iostream>
using namespace std;

class ServerManager : public ComputerEngineer
{
protected:
	int nManagedServer;

public:
	ServerManager(string name="����������", int age=0,
		int nComputer=0, int nManagedServer=0);
	~ServerManager();

public:
	void work();	// ���� �Լ�
	void info();	// Ȯ�� �Լ�
};

