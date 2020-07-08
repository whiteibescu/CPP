#include "Korea.h"
#include "China.h"
#include "Corona.h"
#include "America.h"
#include "StatusBoard.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <combaseapi.h>
#include <windows.h>

#define START_NUM 150
#define END_NUM 3
using namespace std;

int getMask()
{
	srand((unsigned int)time(NULL));
	int num = rand() % START_NUM;
	return num;
}

void CountryTotalAddMask(Corona** pcorona, int len, int sel)
{
	int result = pcorona[sel - 1]->getMask_NUM() + getMask();
	cout << result << endl;
	
}


void main()
{
	int sel;
	int cnt = 0;

	Corona* arrcorona[] = { new China(), new Korea(), new America()};
	StatusBoard statusboard;

	cout << "---�����մϴ�---" << endl;
	cout << "���� �ݷ� �ݷ� " << endl;

	Sleep(1000);

	
	//while (cnt != END_NUM)
	{

		for (int i = 0; i < END_NUM; ++i)
		{
			statusboard.setCorona(arrcorona[i]);
			statusboard.totalStatus();
		}
		cout << "who���� ����ũ�� " << getMask() << " �� ���޵Ǿ����ϴ�. " << endl;
		cout << "��� ���󿡰� �����ϰڽ��ϱ�?" << endl;
		cout << "1.[ �߱� ] 2.[ �ѱ� ] 3.[ �̱� ]" << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:
			
			CountryTotalAddMask(arrcorona, sizeof(arrcorona) / sizeof(arrcorona[0]), sel);
			break;
		default:
			cout << "�߸� �Է� �ϼ̽��ϴ�!!" << endl;
		}

		cnt++;


		//�ϻ���
		//delete[];
	}
}