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
1. Calc클래스는 4개의 멤버를 가지고 있습니다
Calc의 자식인 Add, Sub, Mul, Div 클래스를 만듭니다.
int a, b;
void setValue(int x, int y);	// x를 a에, y를 b에 저장
virtual int calculate() = 0;					// 연산을 실행하고 결과 리턴

calculate()함수는 클래스 마다 고유의 계산으로 재정의하세요

main()함수에서 아래처럼 객체를 생성하세요
Calc* calc[4] = {new Add(), new Sub(), new Mul(), new Div()};

그리고 아래처럼 화면을 구현하세요

[실행화면]
계산을 선택하세요 (0:Add, 1:Sub, 2:Mul, 3:Div) >>  0
=> Add 계산입니다
=> 숫자 2개를 입력하세요 >> 10 20
=> 결과는 30입니다

계산을 선택하세요 (0:Add, 1:Sub, 2:Mul, 3:Div) >>


2. AbstractClass를 완성하세요

*/