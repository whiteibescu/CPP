/* 1. Fruit 프로젝트를
  seller.saleApple(buyer, 2000); 
  처럼 호출할 수 있도록 수정하세요
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
		cout << "[판매자의 현황]" << endl;
		cout << "남은 사과: " << this->numOfApple << endl;
		cout << "전체 총액: " << this->money << endl;
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
		cout << "[구매자의 현황]" << endl;
		cout << "사과 개수: " << this->numOfApple << endl;
		cout << "현재 잔액: " << this->money << endl;
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