#pragma once
#include "ComputerEngineer.h"
class Developer : public ComputerEngineer
{
protected:
	int nLanguage;

public:
	Developer(string name="������", int age=0,
		int nComputer=0, int nLanguage=0);
	~Developer();

public:
	void neverEndingStudy(); // ���� �߰� �Լ�
	void sleep();			 // ���� �Լ�
	void overTime();		 // Ȯ�� �Լ�
	void info();			 // Ȯ�� �Լ�
};

