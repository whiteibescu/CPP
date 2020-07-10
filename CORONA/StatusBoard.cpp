#include "StatusBoard.h"
#include "turboc.h"

extern int g_cnt;

StatusBoard::StatusBoard(Corona* pcorona)
{
	setCorona(pcorona);
}

void StatusBoard::statusMask()
{
	int num = this->corona->getMask_NUM();
	this->corona->Mask += num;
	int result = this->corona->Mask;
	cout << "--- Current Mask ---" << endl;
	cout << result << endl;

}
void StatusBoard::statusInfectee()
{
	int num = this->corona->getInfected_NUM();
	this->corona->Infected += num;
	int result = this->corona->Infected;
}

void StatusBoard::TotalStatus(int left, int top)
{
	statusInfectee();
	gotoxy(left, top);  cout << "<" << this->corona->CountryName << ">" << endl;
	gotoxy(left, top+1);  cout << "ÀÎ±¸  ==> " << this->corona->Population << endl;
	gotoxy(left, top+2);  cout << "°¨¿°ÀÚ==>" << this->corona->Infected << endl;

	
}

void StatusBoard::setCorona(Corona* pcorona)
{
	this->corona = pcorona;
}


