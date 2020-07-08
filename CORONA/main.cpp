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
	int num = rand() % START_NUM;
	cout << "getMask" << num << endl;
	return num;
}

void CountryTotalAddMask(Corona** pcorona, int len, int sel,int m)
{
	int result = pcorona[sel - 1]->getMask_NUM() + m;
	pcorona[sel - 1]->Mask = result;
	cout << "CountryTotalAddMask" << result << endl;
	
}

void srandTime()
{
		srand((unsigned int)time(NULL));
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

	
	while (cnt != END_NUM)
	{

		for (int i = 0; i < END_NUM; ++i)
		{
			statusboard.setCorona(arrcorona[i]);
			statusboard.totalStatus();
		}
		int m = getMask();
		cout << "who���� ����ũ�� " << m << " �� ���޵Ǿ����ϴ�. " << endl;
		cout << "��� ���󿡰� �����ϰڽ��ϱ�?" << endl;
		cout << "1.[ �߱� ] 2.[ �ѱ� ] 3.[ �̱� ]" << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:			
			CountryTotalAddMask(arrcorona, sizeof(arrcorona) / sizeof(arrcorona[0]), sel,m);
			break;
		case 2:
			CountryTotalAddMask(arrcorona, sizeof(arrcorona) / sizeof(arrcorona[0]), sel, m);
			break;
		case 3:
			CountryTotalAddMask(arrcorona, sizeof(arrcorona) / sizeof(arrcorona[0]), sel, m);
			break;
		default:
			cout << "�߸� �Է� �ϼ̽��ϴ�!!" << endl;
		}

		cnt++;


		//�ϻ���
		//delete[];
	}
}