#include "StatusBoard.h"
#include "turboc.h"

extern int g_cnt;




void StatusBoard::dangerLevelBar()
{
	if ((this->corona->Infected / this->corona->Population) * 100 <= 30)
	{
		cout << "【■ 】" << endl;
	}
	else if ((this->corona->Infected / this->corona->Population) * 100 > 30 && (this->corona->Infected / this->corona->Population) * 100 < 60)
	{
		cout << "【■■ 】" << endl;
	}
	else if ((this->corona->Infected / this->corona->Population) * 100 > 50)
	{
		cout << "【■■■ 】" << endl;
	}

}

void StatusBoard::dangerLevel()
{	
	/*cout << (this->corona->Infected / this->corona->Population) * 100 << endl;*/
	//cout << (this->corona->Infected)<< endl;
	//cout << (this->corona->Population) << endl;
	
	if ((this->corona->Infected / this->corona->Population) * 100 <= 30)
	{
		cout << "양호" << endl;
	}

	else if ((this->corona->Infected / this->corona->Population) * 100 > 30 && (this->corona->Infected / this->corona->Population) * 100 < 60)
	{
		cout << "주의" << endl;
	}
	else if ((this->corona->Infected / this->corona->Population) * 100 > 60)
	{
		cout << "위험" << endl;
	}
}


StatusBoard::StatusBoard(Corona* pcorona)
{
	setCorona(pcorona);
}

void StatusBoard::statusMask()
{
	int num = this->corona->getMask_NUM();
	this->corona->Mask = num;
	int result = this->corona->Mask;
	cout << "--- Current Mask ---" << endl;
	cout << result << endl;

}
void StatusBoard::statusInfectee()
{
	int num = this->corona->getInfected_NUM();
	this->corona->Infected = num;
	int result = this->corona->Infected;
}

void StatusBoard::TotalStatus(int left, int top)
{
	statusInfectee();
	gotoxy(left, top);  cout << "<" << this->corona->CountryName << ">" << endl;
	gotoxy(left, top+1);  cout << "인구  ==> " << this->corona->Population << endl;
	gotoxy(left, top+2);  cout << "감염자==>" << this->corona->Infected << endl; 	
	gotoxy(left, top + 5); dangerLevel();
	gotoxy(left, top + 6); dangerLevelBar();
}

void StatusBoard::setCorona(Corona* pcorona)
{
	this->corona = pcorona;
}


