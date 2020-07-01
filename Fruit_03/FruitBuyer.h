#pragma once

#include "FruitSeller.h"

// 클래스의 선언부
class FruitBuyer
{
private:
	int money = 10000;
	int numOfApple = 0;

public:
	void buyApple(FruitSeller& seller, int money);
	void showBuyResult();
};

