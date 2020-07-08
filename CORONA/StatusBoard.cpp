#include "StatusBoard.h"
#include "turboc.h"

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
	cout << "--- Current Infected ---" << endl;
	cout << result << endl;
}

void StatusBoard::totalStatus()
{

	//statusMask();
	//statusInfectee();	
	cout << "<" << this->corona->CountryName << ">" << endl;
	cout << "�α�  ==> " << this->corona->Population << endl;
	cout << "������==>" << this->corona->Infected << endl;
	cout << "������==>" << (this->corona->Population) - this->corona->Infected << endl;	
	cout << "����ũ==>" << this->corona->Mask << endl;
}

void StatusBoard::setCorona(Corona* pcorona)
{
	this->corona = pcorona;
}



