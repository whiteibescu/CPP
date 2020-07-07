#include "Calc.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"
#include <iostream>

using namespace std;



void main()
{
	int num0, num1;
	int sel;
	Calc* calc[] = { new Add(), new Sub(),new Mul(),new Div() };
	while (true)
	{
		cout << "����� �����ϼ���(0:Add, 1:Sub, 2:Mul, 3:Div) : ";
		cin >> sel;
		switch (sel)
		{
		case 0:
		{
			cout << "Add ����Դϴ�" << endl;
			cout << "���� �ΰ��� �Է��ϼ��� >> ";
			cin >> num0 >> num1;
			calc[0]->setValue(num0, num1);
			cout << calc[0]->calculate() << endl;
			break;
		}
		case 1:
		{
			cout << "Sub ����Դϴ�" << endl;
			cout << "���� �ΰ��� �Է��ϼ��� >> ";
			cin >> num0 >> num1;
			calc[1]->setValue(num0, num1);
			cout << calc[1]->calculate() << endl;
			break;
		}
		case 2:
			cout << "Mul ����Դϴ�" << endl;
			cout << "���� �ΰ��� �Է��ϼ��� >> ";
			cin >> num0 >> num1;
			calc[2]->setValue(num0, num1);
			cout << calc[2]->calculate() << endl;
			break;
		case 3:
			cout << "Mul ����Դϴ�" << endl;
			cout << "���� �ΰ��� �Է��ϼ��� >> ";
			cin >> num0 >> num1;
			calc[3]->setValue(num0, num1);
			cout << calc[3]->calculate() << endl;
			break;

		default:
			cout << "�߸��Է��ϼ̽��ϴ�!! �ٽ��Է��ϼ���!!" << endl;
			break;
		}
	}
}