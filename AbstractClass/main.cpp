#include "EmployeeManager.h"

void main()
{
	EmployeeManager em;
	while (1)
	{
		em.showMenu();
		int sel = em.getSelNum();
		if (sel == 3) break;
		switch (sel)
		{
		case 1:
			em.insertEmployee();
			break;
		case 2:
			em.showAllEmployee();
			break;
		}
	}
}

/*
1. CalcŬ������ 4���� ����� ������ �ֽ��ϴ�
Calc�� �ڽ��� Add, Sub, Mul, Div Ŭ������ ����ϴ�.
int a, b;
void setValue(int x, int y);	// x�� a��, y�� b�� ����
virtual int calculate() = 0;					// ������ �����ϰ� ��� ����

calculate()�Լ��� Ŭ���� ���� ������ ������� �������ϼ���

main()�Լ����� �Ʒ�ó�� ��ü�� �����ϼ���
Calc* calc[4] = {new Add(), new Sub(), new Mul(), new Div()};

�׸��� �Ʒ�ó�� ȭ���� �����ϼ���

[����ȭ��]
����� �����ϼ��� (0:Add, 1:Sub, 2:Mul, 3:Div) >>  0
=> Add ����Դϴ�
=> ���� 2���� �Է��ϼ��� >> 10 20
=> ����� 30�Դϴ�

����� �����ϼ��� (0:Add, 1:Sub, 2:Mul, 3:Div) >>


2. AbstractClass�� �ϼ��ϼ���

*/