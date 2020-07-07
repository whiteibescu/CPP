#include "StarUnit.h"
#include "Scv.h"
#include "Marine.h"
#include "Hydra.h"
#include "FireSoldier.h"
#include <windows.h>
#include <time.h>
#include <stdlib.h>

/*�������� �������� ǥ��
1) ���ȿ����� �θ������ �����ϴ� �ڽ�
2) ���۽ô� �ڽŸ��� ������ �� ����*/

// 3. �������� ����
// 1) ������ �迭�� ��� �Ļ� Ŭ������ �ϰ� ���� �� �ִ�
// 2) �θ� ������ ������ ���� �ڽ� ��ü�� �����ص�
//    virtual�Լ��� �ڽ� ��ü ������ ������ �ϰ� �ȴ�
// 3) ���ο� Unit�� �ʿ��� �� �θ� ��Ӹ� �޾Ƶ�
//    ���� �ڵ忡 ������ �� �ִ�.
//    3-1) �θ� ������ �迭 : ��� ����
//    3-2) �θ� ������ �Ű����� : �ڽİ�ü : ������ ���
//    �θ�Ŭ���� ����� virtual�Լ� �߰����ָ�
//    ������ �ڵ带 ��ġ�� �ʰ� �״�� ��밡��

int randomSleep()
{
	int delay = rand() % 2000 + 500;// 500 ~ 2499
	Sleep(delay);
	return delay;
}
/* SCV, Marine, Hydra, FireSoldier�� 
StarUnit�� ����� ���� �ʾҴٸ�
hitAndRun�Լ��� ���� Ŭ���� ����
4���� ������ �Ѵ�.
���� ���ο� Ŭ������ �߰��ȴٸ�
�� ������ �Ѵ�.

������ �Ʒ�ó�� StarUnit�� ����� �޵��� �ϸ�
����� ���� ��� �ڽ� ��ü�� 
�θ� ������ ������ ���Ե� �� �ִ�.
�׷��� virtual�Լ��� ����Ǿ��� ������
1���� �Լ��ε� ���� ��ü�� ������ �� �ִ�.
<������>
1) �迭�� �ϰ� ����
2) �Ű����� 1���� ���� ��ü ����
=> Ȯ�强�� �־ �ּ��� �������� ����
   ���ο� Ŭ����(ĳ����)�� �߰��Ǿ
   ���� �ڵ� �״�� ��� ����
*/
void hitAndRun(StarUnit* pUnit)
{
	pUnit->attack();
	int delay = randomSleep();
	if (delay < 1500)
		pUnit->die();
	else			  
		pUnit->move();
}

/* int�迭�� �Ű����� int *
   StarUnit* �迭�� �Ű����� StarUnit**
*/
void heapDeleteAll(StarUnit** unit, int len)
{
	for (int i = 0; i < len; i++)
		delete unit[i];
}

void main()
{
	srand((unsigned int)time(NULL));

	// 1. ������ �ڽ� ����
	// �ڽİ�ü���� �θ� ������ ����
	// �迭�� �ϰ� ������ �� �ִ�
	StarUnit* unit[] = { new Scv(), 
						new Marine(),
						new Hydra(),
						new FireSoldier()};

	// 2. ������ �ڽ� ������ Ư¡ ����
	// �ڽ��� �������� �Լ��� virtual��
	// �����ϸ� �θ� ������ ������ �Ѱܵ�
	// �� ��ü ������ ������ ����ȴ�
	hitAndRun(unit[3]);

	heapDeleteAll(unit, sizeof(unit) / sizeof(unit[0]));

	//delete unit[0];
	//delete unit[1];
	//delete unit[2];
	//delete unit[3];
}