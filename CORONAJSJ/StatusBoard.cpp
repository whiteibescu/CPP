#include "StatusBoard.h"
#include "turboc.h"

extern int g_cnt;

StatusBoard::StatusBoard(Corona* pcorona)
{
	setCorona(pcorona);
}

void StatusBoard::dangerLevelBar()
{
	if ((this->corona->Infected / this->corona->Population) * 100 <= 30)
	{
		cout << "����    ��" << endl;
	}	   
	else if ((this->corona->Infected / this->corona->Population) * 100 > 30 && (this->corona->Infected / this->corona->Population) * 100 <= 60)
	{
		cout << "�����    ��" << endl;
	}	
	else if ((this->corona->Infected / this->corona->Population) * 100 > 60)
	{
		cout << "������ ��" << endl;
	}
}

void StatusBoard::dangerLevel()
{

	if ((this->corona->Infected / this->corona->Population) * 100 <= 30)
	{
		cout << "��ȣ" << endl;

	}

	else if ((this->corona->Infected / this->corona->Population) * 100 > 30 && (this->corona->Infected / this->corona->Population) * 100 <= 60)
	{
		cout << "����" << endl;

	}
	else if ((this->corona->Infected / this->corona->Population) * 100 > 60)
	{
		cout << "����" << endl;

	}
}

int StatusBoard::statusMask()
{
	int num = this->corona->getMask_NUM();			// ���� ����ũ ���� �Լ� -> Ŭ���� Mask ������ �Ѱ��ִ� ������ �ϴ� �Լ��� ȣ�� -> num�� �� ����
	this->corona->Mask = num;						// corona Ŭ���� mask ������ num ���� ��� ����
	return this->corona->Mask;
}
void StatusBoard::statusInfectee()
{
			// ���� ������ ���� �Լ� -> Ŭ���� Infected ������ �Ѱ��ִ� ������ �ϴ� �Լ��� ȣ�� -> num�� �� ����
	this->corona->Infected = this->corona->getInfected_NUM();					// corona Ŭ���� Infected ������ num ���� ��� ����
	
}

void StatusBoard::TotalStatus(int left, int top)	// ����ڰ� �� �� �ִ� ��ü ����â
{		

	if(g_cnt !=0){ statusInfectee(); }
	
	gotoxy(left, top);  cout << "<" << this->corona->CountryName << ">" << endl;
	gotoxy(left, top+1);  cout << "�α�  ==> " << this->corona->Population << endl;
	gotoxy(left, top + 2); cout << "������ ==>" << this->corona->Infected << endl;
	gotoxy(left, top + 5); dangerLevel();
	gotoxy(left, top + 6); dangerLevelBar();
}

void StatusBoard::setCorona(Corona* pcorona)
{
	this->corona = pcorona;
}

//void StatusBoard::TotalStatus1(int left, int top, int x)
//{
//	statusinfectee += this->corona->Infected - x;
//	if (g_cnt != 0) { statusInfectee(); }
//
//	gotoxy(left, top);  cout << "<" << this->corona->CountryName << ">" << endl;
//	gotoxy(left, top + 1);  cout << "�α�  ==> " << this->corona->Population << endl;
//	gotoxy(left, top + 2); cout << "������ ==>" << statusinfectee << endl;
//	gotoxy(left, top + 5); dangerLevel();
//	gotoxy(left, top + 6); dangerLevelBar();
//}





