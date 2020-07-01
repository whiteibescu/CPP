/* <���� ���� ����>
1) class�� ����ο� �����η� �и��Ѵ�
2) ����δ� h(�������)�� �����Ѵ�
3) �����δ� cpp(�ҽ�����)�� �����Ѵ�
4) �ش� ���Ͽ� ���� ������ #include�� ���ش�
*/
#include <iostream>

using namespace std;

// Ŭ������ ������
class FruitSeller
{
private:
	int numOfApple = 20;
	int money = 100000;
	const int APPLE_PRICE = 1000;

public:
	int saleApple(int money);
	void showSaleResult();
};

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

// Ŭ������ ������
class FruitBuyer
{
private:
	int money = 10000;
	int numOfApple = 0;

public:
	void buyApple(FruitSeller& seller, int money);
	void showBuyResult();
};

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
void main()
{
	FruitSeller seller;
	FruitBuyer buyer;
	buyer.buyApple(seller, 2000);

	seller.showSaleResult();
	buyer.showBuyResult();
}