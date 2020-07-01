/* <파일 분할 절차>
1) class를 선언부와 구현부로 분리한다
2) 선언부는 h(헤더파일)로 생성한다
3) 구현부는 cpp(소스파일)로 생성한다
4) 해당 파일에 없는 정보는 #include를 해준다
*/
#include <iostream>

using namespace std;

// 클래스의 구현부
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

// 클래스의 구현부
int FruitSeller::saleApple(int money)
{
	int num = money / APPLE_PRICE;
	this->numOfApple -= num;
	this->money += money;
	return num;
}
void FruitSeller::showSaleResult()
{
	cout << "[판매자의 현황]" << endl;
	cout << "남은 사과: " << this->numOfApple << endl;
	cout << "전체 총액: " << this->money << endl;
	cout << endl;
}

// 클래스의 구현부
class FruitBuyer
{
private:
	int money = 10000;
	int numOfApple = 0;

public:
	void buyApple(FruitSeller& seller, int money);
	void showBuyResult();
};

// 클래스의 구현부
void FruitBuyer::buyApple(FruitSeller& seller, int money)
{
	this->numOfApple = seller.saleApple(money);
	this->money -= money;
}
void FruitBuyer::showBuyResult()
{
	cout << "[구매자의 현황]" << endl;
	cout << "사과 개수: " << this->numOfApple << endl;
	cout << "현재 잔액: " << this->money << endl;
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