#include "Korea.h"
#include "China.h"
#include "Corona.h"
#include "America.h"
#include "StatusBoard.h"
#include <iostream>
#pragma comment(lib, "winmm.lib")
#include <ctime>
#include <stdlib.h>
#include <combaseapi.h>
#include <windows.h>
#include "turboc.h"
#include <mmstream.h>

#define END_NUM 3
#define LEFT 10
#define TOP 8
#define music "bgm.wav"

using namespace std;
int g_cnt = 0;

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
		if (i == 2)
		{
			Sleep(600);
			Beep(900, 500);
		}
		if (i == 9)
		{
			Sleep(300);
			Beep(900, 500);
		}
		if (i == 25)
		{
			Sleep(200);
			Beep(900, 500);
		}
	}
	system("cls");
	system("color 0F");

}

void startScript()
{
	const char* script = "����� UN �繫�����Դϴ�. �ڷγ��� �ߺ��Ͽ����ϴ�. \n"
		"�� ���󺰷� ����ũ�� �����ϰ� ������ �������Դϴ�.\n"
		"WHO������ ����ũ�� �����ϰ� ������ �����Դϴ�.\n"
		"������ ���귮�� ���� �ʾ� �ѹ��� �� �������� ���� �� �� �ֽ��ϴ�.\n"
		"����� ������ ������ �η��� �¿� �� ���Դϴ�.\n"
		"�� 3�� �������� ���� �ֽ��ϴ�.\n";
	int length = strlen(script);

	for (int i = 0; i < length; i++)
	{
		printf("%c", script[i]);
		Sleep(40);
	}

	system("color 04");
	delay(1000);
	delay(1000);
	system("color 0F");
}

int showSelect(int x)
{
	int sel;
	cout << "\n\n\n" << endl;
	cout << "================================================================" << endl;
	cout << "who���� ����ũ�� " << x << " �� ���޵Ǿ����ϴ�. " << endl;
	cout << "��� ���󿡰� �����ϰڽ��ϱ�?" << endl;
	cout << "1.[ �߱� ] 2.[ �ѱ� ] 3.[ �̱� ]" << endl;
	cin >> sel;

	return sel;
}

void CountrySelectAddMask(Corona** pcorona, int len, int sel, int m)
{
	pcorona[sel - 1]->Infected = pcorona[sel - 1]->Infected - m;

	gotoxy(10, 16);
	cout << "����ũ�� " << pcorona[sel - 1]->CountryName << " ���� " << m << "��" << "���޵Ǿ����ϴ�" << endl;
}

void eraseMem(Corona** pcorona, int len)
{
	for (int i = 0; i < len; i++)
	{
		delete pcorona[i];
	}	
}

void showFail()
{
	int num = 20;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num + 30; j++) {
			if (i == j || i + j == num - 1) { cout << "*"; }
			else { cout << " "; }
		}
		cout << endl;
	}

}

void main()
{
	PlaySound(TEXT(music), NULL, SND_ASYNC); // 3.5sec
	_getch();
	int sel;

	Corona* arrcorona[] = { new China(), new Korea(), new America() };
	StatusBoard statusboard;

	startCoronaVirus();
	startScript();
	cout << "================================================================" << endl;
	
	while (g_cnt <= END_NUM)
	{
		int left = 10;
		int top = 8;

		gotoxy(1, 7);
		cout << "<" << g_cnt + 1 << "ȸ��>";
		if (g_cnt == END_NUM)
		{
			gotoxy(1, 7);
			cout << "<3ȸ��>";
		}

		if (g_cnt != 0) 
		{
			gotoxy(10, 7);
			cout << "����� �����ڵ��� �þ���ϴ�." << endl;
		}

		for (int i = 0; i < END_NUM; ++i)
		{
			//������ = ���λ��� ������ + ����������

			statusboard.setCorona(arrcorona[i]);
			statusboard.TotalStatus(left, top);
			left += 20;
		}

		for (int i = 0; i < END_NUM; ++i)
		{
			if (arrcorona[i]->Infected >= arrcorona[i]->Population) 
			{
				_getch();
				system("cls");
				cout << "����" << endl;				
				eraseMem(arrcorona, sizeof(arrcorona) / sizeof(arrcorona[0]));
				showFail();
				exit(0);
				//�ذ񹮾�
			}
			if (g_cnt == END_NUM) {
				//����
				_getch();
				system("cls");
				cout << "����" << endl;
				eraseMem(arrcorona, sizeof(arrcorona) / sizeof(arrcorona[0]));
				exit(0);

			}
		}

		int x = statusboard.getMaskQuantity();
		sel = showSelect(x);

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
		//���� �ϳ��� ������ �����ڰ� �α��� �ʰ��ϸ� ���ӿ��� �׷��� ������ Ŭ����
		g_cnt++;		
	}
}
