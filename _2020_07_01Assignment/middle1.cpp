/* 1. Fruit ������Ʈ��
  seller.saleApple(buyer, 2000); 
  ó�� ȣ���� �� �ֵ��� �����ϼ���
*/
#include <iostream>

using namespace std;

class FruitSeller	
{
private:
	int numOfApple = 20;
	int money = 100000;
	const int APPLE_PRICE = 1000;

public:
	int saleApple(int money)
	{
		int num = money / APPLE_PRICE;
		this->numOfApple -= num;
		this->money += money;
		return num;
	}
	void showSaleResult()
	{
		cout << "[�Ǹ����� ��Ȳ]" << endl;
		cout << "���� ���: " << this->numOfApple << endl;
		cout << "��ü �Ѿ�: " << this->money << endl;
		cout << endl;
	}
};

class FruitBuyer
{
private:
	int money = 10000;
	int numOfApple = 0;

public:
	void buyApple(FruitSeller& seller, int money)
	{
		this->numOfApple = seller.saleApple(money);
		this->money -= money;
	}
	void showBuyResult()
	{
		cout << "[�������� ��Ȳ]" << endl;
		cout << "��� ����: " << this->numOfApple << endl;
		cout << "���� �ܾ�: " << this->money << endl;
		cout << endl;
	}
};

void main()
{
	FruitSeller seller;
	FruitBuyer buyer;
	seller.saleApple(buyer, 2000);
	//buyer.buyApple(seller, 2000);

	seller.showSaleResult();
	buyer.showBuyResult();
}