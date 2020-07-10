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

void StatusBoard::afterTotalStatus(int left, int top)
{
	
	//statusMask();
	statusInfectee();
	
	gotoxy(left, top);  cout << "<" << this->corona->CountryName << ">" << endl;
	gotoxy(left, top+1);  cout << "인구  ==> " << this->corona->Population << endl;
	/*gotoxy(left, top + 2);  cout << "생존자==>" << this->corona->Population - this->corona->Infected + this->corona->Mask << endl;*/
	gotoxy(left, top+2);  cout << "감염자==>" << this->corona->Infected << endl;
	/*gotoxy(left, top + 4);  cout << "마스크==>" << this->corona->Mask << endl;*/
	//gotoxy(left, top + 5);  cout << "MASK==>" << this->corona->getMask_NUM();
	
}

void StatusBoard::setCorona(Corona* pcorona)
{
	this->corona = pcorona;
}

//void StatusBoard::beforeTotalStatus(int left, int top)
//{
//	statusInfectee();
//	gotoxy(left, top);  cout << "<" << this->corona->CountryName << ">" << endl;
//	gotoxy(left, top + 1);  cout << "인구  ==> " << this->corona->Population << endl;
//	gotoxy(left, top + 2);  cout << "감염자==>" << this->corona->Infected << endl;
//}



