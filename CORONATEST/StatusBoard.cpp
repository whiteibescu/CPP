#include "StatusBoard.h"
#include "turboc.h"

extern int g_cnt;

StatusBoard::StatusBoard(Corona* pcorona)
{
	setCorona(pcorona);
}

//void StatusBoard::Temp()
//{
//	newInfected += this->corona->Infected - this->corona->Mask;	
//}

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
	gotoxy(left, top + 1);  cout << "�α�  ==> " << this->corona->Population << endl;
	gotoxy(left, top + 2);  cout << "������==>" << this->corona->Infected << endl;

	//Temp();
	//this->corona->getInfected_NUM();
	
	//gotoxy(left, top + 4);  cout << "<" << this->corona->CountryName << ">" << endl;
	//gotoxy(left, top + 5);  cout << "�α�  ==> " << this->corona->Population << endl;
	//gotoxy(left, top + 6);  cout << "������==>" << newInfected + this->corona->Infected << endl;	
}
 
//void StatusBoard::firstTotalStatus(int left, int top)
//{	
//	gotoxy(left, top);  cout << "<" << this->corona->CountryName << ">" << endl;
//	gotoxy(left, top+1);  cout << "�α�  ==> " << this->corona->Population<< endl;
//	gotoxy(left, top+2);  cout << "������==>" <<this->corona->Infected<< endl;
//}


void StatusBoard::setCorona(Corona* pcorona)
{
	this->corona = pcorona;
}

