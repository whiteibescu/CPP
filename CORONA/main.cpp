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

	cout << "---시작합니다---" << endl;
	cout << "에취 콜록 콜록 " << endl;

	Sleep(1000);

	
	//while (cnt != END_NUM)
	{

		for (int i = 0; i < END_NUM; ++i)
		{
			statusboard.setCorona(arrcorona[i]);
			statusboard.totalStatus();
		}
		cout << "who에서 마스크가 " << getMask() << " 개 지급되었습니다. " << endl;
		cout << "어느 나라에게 지급하겠습니까?" << endl;
		cout << "1.[ 중국 ] 2.[ 한국 ] 3.[ 미국 ]" << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:
			
			CountryTotalAddMask(arrcorona, sizeof(arrcorona) / sizeof(arrcorona[0]), sel);
			break;
		default:
			cout << "잘못 입력 하셨습니다!!" << endl;
		}

		cnt++;


		//턴생성
		//delete[];
	}
}