#include "StatusBoard.h"
#include "turboc.h"

extern int g_cnt;

StatusBoard::StatusBoard(Corona* pcorona)
{
	setCorona(pcorona);
}

int StatusBoard::getMaskQuantity()
{
	srand((unsigned int)time(NULL));

	int num = rand() % COUNTRY_MASK_NUM + BASIC_MASK_NUM;

	return num;
}

void StatusBoard::dangerLevelBar()
{
	if ((this->corona->Infected / this->corona->Population) * 100 <= 30)
	{
		cout << "【■    】" << endl;
	}
	else if ((this->corona->Infected / this->corona->Population) * 100 > 30 && (this->corona->Infected / this->corona->Population) * 100 <= 60)
	{
		cout << "【■■   】" << endl;
	}
	else if ((this->corona->Infected / this->corona->Population) * 100 > 60)
	{
		cout << "【■■■ 】" << endl;
	}
}

void StatusBoard::dangerLevel()
{

	if ((this->corona->Infected / this->corona->Population) * 100 <= 30)
	{
		cout << "양호" << endl;

	}

	else if ((this->corona->Infected / this->corona->Population) * 100 > 30 && (this->corona->Infected / this->corona->Population) * 100 <= 60)
	{
		cout << "주의" << endl;

	}
	else if ((this->corona->Infected / this->corona->Population) * 100 > 60)
	{
		cout << "위험" << endl;

	}
}

void StatusBoard::statusInfectee()
{
	// 랜덤 감염자 생산 함수 -> 클래스 Infected 변수에 넘겨주는 역할을 하는 함수를 호출 -> num에 값 저장
	this->corona->Infected = this->corona->getInfected_NUM();					// corona 클래스 Infected 변수에 num 값을 계속 저장

}

void StatusBoard::TotalStatus(int left, int top)	// 사용자가 볼 수 있는 전체 상태창
{

	if (g_cnt != 0) { statusInfectee(); }

	gotoxy(left, top);  cout << "<" << this->corona->CountryName << ">" << endl;
	gotoxy(left, top + 1);  cout << "인구  ==> " << this->corona->Population << endl;
	gotoxy(left, top + 2); cout << "감염자 ==>" << this->corona->Infected << endl;
	gotoxy(left, top + 5); dangerLevel();
	gotoxy(left, top + 6); dangerLevelBar();
}

void StatusBoard::setCorona(Corona* pcorona)
{
	this->corona = pcorona;
}




