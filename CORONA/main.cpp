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
#include "turboc.h"


#define START_NUM 150
#define END_NUM 3
#define XJUMP_NUM 30
using namespace std;

int g_cnt = 0;

int getMask()
{	
	int num = rand() % START_NUM + XJUMP_NUM;
	return num;
}

void CountryTotalAddMask(Corona** pcorona, int len, int sel,int m)
{
	//pcorona[sel - 1]->getMask_NUM()
	int result = 0;
	result = m;
	pcorona[sel - 1]->Mask += result;
}

void srandTime()
{
		srand((unsigned int)time(NULL));
}

void startCoronaVirus()
{
	system("title Corona Virus");
	system("color 04");
	
	for (int i = 0; i < 5; ++i)
	{
		Beep(900, 600);
	}

	cout << "---�����մϴ�---" << endl;
	cout << "�ڷγ��� �����ϴ�" << endl;
	cout << "���� �ݷ� �ݷ� " << endl;

	Sleep(500);
	Beep(900, 500);
	cout << "���� �ݷ� �ݷ� ���� �ݷ� �ݷϿ��� �ݷ� �ݷϿ��� �ݷ� �ݷϿ��� �ݷ� �ݷ� ���� �ݷ� �ݷϿ��� �ݷ� �ݷ�" << endl;

	Sleep(500);
	Beep(900, 500);
	for (int i = 0; i < 40; i++) 
		{
			cout << "���� �ݷ� �ݷ� ���� �ݷ� �ݷϿ��� �ݷ� �ݷϿ��� �ݷ� �ݷϿ��� �ݷ� �ݷϿ��� �ݷ� �ݷϿ��� �ݷ� �ݷ�" << endl;
			if (i == 2) {
				Sleep(600);
				Beep(900, 500);
			}
			if (i == 9) {
				Sleep(300);
				Beep(900, 500);
			}
			if (i == 25) {
				Sleep(200);
				Beep(900, 500);
			}
		}

	system("cls");
	system("color 0F");

	cout << "����� UN �繫�����Դϴ�. �ڷγ��� �ߺ��Ͽ����ϴ�. \n"
		"����� ������ ������ �η��� �¿� �� ���Դϴ�.\n"
		"������ 3���� ��ȸ�� �ֽ��ϴ�." << endl;
}

void main()
{

	int sel;
	//int cnt = 0;
	int x = 30;
	Corona* arrcorona[] = { new China(), new Korea(), new America()};
	StatusBoard statusboard;


	/*startCoronaVirus();*/
	cout << "����� UN �繫�����Դϴ�. �ڷγ��� �ߺ��Ͽ����ϴ�. \n"
		"�� ���󺰷� ����ũ�� �����ϰ� ������ �������Դϴ�.\n"
		"WHO������ ����ũ�� �����ϰ� ������ �����Դϴ�.\n"
		"������ ���귮�� ���� �ʾ� �ѹ��� �� �������� ���� �� �� �ֽ��ϴ�.\n "
		"����� ������ ������ �η��� �¿� �� ���Դϴ�.\n"	
		"�� 3�� �������� ���� �ֽ��ϴ�." << endl;
	cout << "================================================================" << endl;
	

	while (g_cnt <= END_NUM)
	{
		int left = 10;
		int top = 8;
		gotoxy(1, 7);
		cout << "<" << g_cnt + 1 << "ȸ��>";

		for (int i = 0; i < END_NUM; ++i)
		{
			
			statusboard.setCorona(arrcorona[i]);
			/*statusboard.beforeTotalStatus(left, top);*/
			
			statusboard.afterTotalStatus(left, top);	
			left += 20;
		}


		if (g_cnt == END_NUM)
		{
			gotoxy(0, 23);
			exit(0);
		}

		int m = getMask();
		cout << "\n\n\n" << endl;
		cout << "================================================================" << endl;
		cout << "who���� ����ũ�� " << m << " �� ���޵Ǿ����ϴ�. " << endl;
		cout << "��� ���󿡰� �����ϰڽ��ϱ�?" << endl;
		cout << "1.[ �߱� ] 2.[ �ѱ� ] 3.[ �̱� ]" << endl;
		cin >> sel;
		getchar();
		getchar();
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
		
		g_cnt++;


		//�ϻ���
		//delete[];
	}
}
