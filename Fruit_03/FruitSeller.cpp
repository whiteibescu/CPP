#include "FruitSeller.h"
#include <iostream>

using namespace std;

// Ŭ������ ������
int FruitSeller::saleApple(int money)
{
	int num = money / APPLE_PRICE;
	this->numOfApple -= num;
	this->money += money;
	return num;
}
void FruitSeller::showSaleResult()
{
	cout << "[�Ǹ����� ��Ȳ]" << endl;
	cout << "���� ���: " << this->numOfApple << endl;
	cout << "��ü �Ѿ�: " << this->money << endl;
	cout << endl;
}