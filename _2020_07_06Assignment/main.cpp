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
		cout << "계산을 선택하세요(0:Add, 1:Sub, 2:Mul, 3:Div) : ";
		cin >> sel;
		switch (sel)
		{
		case 0:
		{
			cout << "Add 계산입니다" << endl;
			cout << "숫자 두개를 입력하세요 >> ";
			cin >> num0 >> num1;
			calc[0]->setValue(num0, num1);
			cout << calc[0]->calculate() << endl;
			break;
		}
		case 1:
		{
			cout << "Sub 계산입니다" << endl;
			cout << "숫자 두개를 입력하세요 >> ";
			cin >> num0 >> num1;
			calc[1]->setValue(num0, num1);
			cout << calc[1]->calculate() << endl;
			break;
		}
		case 2:
			cout << "Mul 계산입니다" << endl;
			cout << "숫자 두개를 입력하세요 >> ";
			cin >> num0 >> num1;
			calc[2]->setValue(num0, num1);
			cout << calc[2]->calculate() << endl;
			break;
		case 3:
			cout << "Mul 계산입니다" << endl;
			cout << "숫자 두개를 입력하세요 >> ";
			cin >> num0 >> num1;
			calc[3]->setValue(num0, num1);
			cout << calc[3]->calculate() << endl;
			break;

		default:
			cout << "잘못입력하셨습니다!! 다시입력하세요!!" << endl;
			break;
		}
	}
}