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
	//	//감염자 = 새로생긴 감염자 + 기존감염자
	//
	//	statusboard.setCorona(pcorona[i]);
	//	statusboard.TotalStatus(10, 8);
	//	left += 20;
	//}

	gotoxy(10, 16);
	cout << "마스크가 " << pcorona[sel - 1]->CountryName << " 에게 " << m << "개" << "지급되었습니다" << endl;
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

	cout << "---시작합니다---" << endl;
	cout << "코로나가 퍼집니다" << endl;
	cout << "에취 콜록 콜록 " << endl;

	Sleep(500);
	Beep(900, 500);
	cout << "에취 콜록 콜록 에취 콜록 콜록에취 콜록 콜록에취 콜록 콜록에취 콜록 콜록 에취 콜록 콜록에취 콜록 콜록" << endl;

	Sleep(500);
	Beep(900, 500);
	for (int i = 0; i < 40; i++) 
		{
			cout << "에취 콜록 콜록 에취 콜록 콜록에취 콜록 콜록에취 콜록 콜록에취 콜록 콜록에취 콜록 콜록에취 콜록 콜록" << endl;
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

	cout << "당신은 UN 사무총장입니다. 코로나가 발병하였습니다. \n"
		"당신의 선택이 앞으로 인류를 좌우 할 것입니다.\n"
		"앞으로 3번의 기회가 있습니다." << endl;
}

void main()
{

	int sel;
	
	Corona* arrcorona[] = { new China(), new Korea(), new America()};
	StatusBoard statusboard;

	/*startCoronaVirus();*/
	cout << "당신은 UN 사무총장입니다. 코로나가 발병하였습니다. \n"
		"각 나라별로 마스크를 생산하고 있지만 역부족입니다.\n"
		"WHO에서도 마스크를 생산하고 지원할 예정입니다.\n"
		"하지만 생산량이 많지 않아 한번에 한 국가에만 지원 할 수 있습니다.\n "
		"당신의 선택이 앞으로 인류를 좌우 할 것입니다.\n"	
		"총 3번 지원해줄 수가 있습니다." << endl;
	cout << "================================================================" << endl;
	

	while (g_cnt <= END_NUM)
	{
		int left = 10;
		int top = 8;
		gotoxy(1, 7);
		cout << "<" << g_cnt + 1 << "회차>";
		
		if (g_cnt != 0) {
			gotoxy(10, 7);
			cout << "밤사이 감염자들이 늘어났습니다." << endl;			
		}
		//delay(2000);



		for (int i = 0; i < END_NUM; ++i)
		{
			//감염자 = 새로생긴 감염자 + 기존감염자
			
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
		cout << "who에서 마스크가 " << x << " 개 지급되었습니다. " << endl;
		cout << "어느 나라에게 지급하겠습니까?" << endl;
		cout << "1.[ 중국 ] 2.[ 한국 ] 3.[ 미국 ]" << endl;
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
			cout << "잘못 입력 하셨습니다!!" << endl;
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
