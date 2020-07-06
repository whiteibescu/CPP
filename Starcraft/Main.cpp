#include "StarUnit.h"
#include "Scv.h"
#include "Marine.h"
#include "Hydra.h"
#include <windows.h>
#include <time.h>
#include <stdlib.h>

/* �������̶�?
1) �ϳ��� �θ�κ��� �Ļ��� ���� Ŭ����
2) ������(�θ�κ��� ���)
3) Ư���� �ο��Ѵ�(�����ǰ� �̷������)
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