#pragma once
#include "Human.h"
class ComputerEngineer : public Human
{
protected:
	int nComputer;

public:
	ComputerEngineer(string name="��ǻ�� �����Ͼ�", 
					int age=0, 
					int nComputer=0);
	~ComputerEngineer();

public:
	void overTime();	// ���� �߰��� �Լ�
	void info();		// Ȯ���ϴ� �Լ�
};

