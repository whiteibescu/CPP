#pragma once
#include "Gun.h"
#include <iostream>

using namespace std;

class Police : public Gun
{
private:
	string hat="��������";
	string suit="������";
public:
	void wearSuit() {
		cout << hat << "�� �����ϴ�" << endl;
		cout << suit << "�� �����ϴ�" << endl;
	}
};

