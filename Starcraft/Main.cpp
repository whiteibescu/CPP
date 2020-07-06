#include "StarUnit.h"
#include "Scv.h"
#include "Marine.h"
#include "Hydra.h"
#include <windows.h>
#include <time.h>
#include <stdlib.h>

/* 다형성이란?
1) 하나의 부모로부터 파생된 여러 클래스
2) 공통점(부모로부터 상속)
3) 특성을 부여한다(재정의가 이루어진다)
*/

int randomSleep()
{
	int delay = rand() % 2000 + 500;// 500 ~ 2499
	Sleep(delay);
	return delay;
}
void hitAndRun(StarUnit* pUnit)
{
	pUnit->attack();
	int delay = randomSleep();
	if (delay < 1500)
		pUnit->die();
	else			  
		pUnit->move();
}

void main()
{
	srand((unsigned int)time(NULL));

	StarUnit* unit[] = { new Scv(), 
						new Marine(),
						new Hydra() };
}