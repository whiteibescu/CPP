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

int g_cnt = 0;

#define END_NUM 3
using namespace std; 
#define LEFT 10
#define TOP 8

void CountrySelectAddMask(Corona** pcorona, int len, int sel, int m)
{
	//int left = 10;
	/*int result = 0;
	result = m;
	pcorona[sel - 1]->Mask += result;*/
	//StatusBoard statusboard;
	pcorona[sel - 1]->Infected = pcorona[sel - 1]->Infected - m;
	//for (int i = 0; i < END_NUM; ++i)
	//{
	//	//������ = ���λ��� ������ + ����������
	//
	//	statusboard.setCorona(pcorona[i]);
	//	statusboard.TotalStatus(10, 8);
	//	left += 20;
	//}

	gotoxy(10, 16);
	cout << "����ũ�� " << pcorona[sel - 1]->CountryName << " ���� " << m << "��" << "���޵Ǿ����ϴ�" << endl;
	//delay(1000);
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
		
		if (g_cnt != 0) {
			gotoxy(10, 7);
			cout << "����� �����ڵ��� �þ���ϴ�." << endl;			
		}
		//delay(2000);



		for (int i = 0; i < END_NUM; ++i)
		{
			//������ = ���λ��� ������ + ����������
			
			statusboard.setCorona(arrcorona[i]);
			statusboard.TotalStatus(left, top);	
			left += 20;
		}

		if (g_cnt == END_NUM)
		{
			gotoxy(0, 23);
			exit(0);
		}
		int x = statusboard.statusMask();
		cout << "\n\n\n" << endl;
		cout << "================================================================" << endl;
		cout << "who���� ����ũ�� " << x << " �� ���޵Ǿ����ϴ�. " << endl;
		cout << "��� ���󿡰� �����ϰڽ��ϱ�?" << endl;
		cout << "1.[ �߱� ] 2.[ �ѱ� ] 3.[ �̱� ]" << endl;
		cin >> sel;

		switch (sel)
		{
		case 1:			
			CountrySelectAddMask(arrcorona, sizeof(arrcorona) / sizeof(arrcorona[0]), sel, x);
			break;
		case 2:
			CountrySelectAddMask(arrcorona, sizeof(arrcorona) / sizeof(arrcorona[0]), sel, x);
			break;
		case 3:
			CountrySelectAddMask(arrcorona, sizeof(arrcorona) / sizeof(arrcorona[0]), sel, x);
			break;
		default:
			cout << "�߸� �Է� �ϼ̽��ϴ�!!" << endl;
		}

		//for (int i = 0; i < END_NUM; i++)
		//{

		//	statusboard.TotalStatus1(LEFT, TOP, x);
		//	left += 20;
		//}
		//delay(1000);
		

		g_cnt++;

		//delete[];
	}
}
