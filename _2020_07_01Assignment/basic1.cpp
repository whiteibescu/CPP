//1. main()�� ���� ����� ������ ������ TowerŬ������ �ۼ��ϼ���
//
//���̴� 1����
//���̴� 100����

#include <iostream>

using namespace std;

class Tower {
private:
	int meter;

public:
	Tower()
	{
		meter = 5;
	}

	Tower(int m)
	{
		meter = m;
	}
	int getHeight()
	{
		return meter;
	}
};


void main()
{
	Tower myTower;
	Tower seoulTower(100);
	cout << "���̴� " << myTower.getHeight() << "����" << endl;
	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
}