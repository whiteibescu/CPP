#include "FruitBuyer.h"
#include <iostream>

using namespace std;

// Ŭ������ ������
void FruitBuyer::buyApple(FruitSeller& seller, int money)
{
	this->numOfApple = seller.saleApple(money);
	this->money -= money;
}
void FruitBuyer::showBuyResult()
{
	cout << "[�������� ��Ȳ]" << endl;
	cout << "��� ����: " << this->numOfApple << endl;
	cout << "���� �ܾ�: " << this->money << endl;
	cout << endl;
}
