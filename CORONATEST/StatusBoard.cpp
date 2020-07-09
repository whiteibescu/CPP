#include "StatusBoard.h"
#include "turboc.h"

extern int g_cnt;

StatusBoard::StatusBoard(Corona* pcorona)
{
	setCorona(pcorona);
}

void StatusBoard::Temp()
{
	newInfected = this->corona->Infected - this->corona->Mask;	
}

void StatusBoard::TotalStatus(int left, int top)
{
	int num = this->corona->Infected - this->corona->Mask;
	
	gotoxy(left, top);  cout << "<" << this->corona->CountryName << ">" << endl;
	gotoxy(left, top + 1);  cout << "ÀÎ±¸  ==> " << this->corona->Population << endl;
	gotoxy(left, top + 2);  cout << "°¨¿°ÀÚ==>" << num << endl;

	Temp();
	this->corona->getInfected_NUM();

	gotoxy(left, top + 4);  cout << "<" << this->corona->CountryName << ">" << endl;
	gotoxy(left, top + 5);  cout << "ÀÎ±¸  ==> " << this->corona->Population << endl;
	gotoxy(left, top + 6);  cout << "°¨¿°ÀÚ==>" << newInfected + this->corona->Infected << endl;

	
}
 
void StatusBoard::firstTotalStatus(int left, int top)
{	
	gotoxy(left, top);  cout << "<" << this->corona->CountryName << ">" << endl;
	gotoxy(left, top+1);  cout << "ÀÎ±¸  ==> " << this->corona->Population<< endl;
	gotoxy(left, top+2);  cout << "°¨¿°ÀÚ==>" <<this->corona->Infected<< endl;
}


void StatusBoard::setCorona(Corona* pcorona)
{
	this->corona = pcorona;
}

