#include "Developer.h"

/* member initialize ����
1) ������ �Ʒ� : ������ ��ġ�Ѵ�
2) ������ ȣ�� ��ü ���� ����Ǵ� ����
3) �θ� ������ ȣ���� ���� �θ� ��ü �ʱ�ȭ
4) ���� ��� ��ü�� �ʱ�ȭ
5) ��� ������ �ʱ�ȭ(���� ����)
*/

Developer::Developer(string name, int age,
	int nComputer, int _nLanguage)
	// member initialize ����
	:ComputerEngineer(name, age, nComputer)
	, nLanguage(_nLanguage)
{
	//this->nLanguage = nLanguage;
	cout << "Developer ������ ȣ��" << endl;
}
Developer::~Developer()
{
	cout << "Developer �Ҹ��� ȣ��" << endl;
}

void Developer::neverEndingStudy()
{
	cout << this->name << "�� �� ���θ� �Ѵ�" << endl;
}
void Developer::sleep()
{
	cout << this->name << "�� �ʰ� �� ���� �ִ�" << endl;
}
void Developer::overTime()
{
	ComputerEngineer::overTime();
	cout << "������ �޽��� ������" << endl;
}
void Developer::info()
{
	ComputerEngineer::info();
	cout << this->name << "�� ����ϴ� �� " <<
		    this->nLanguage << "�����̴�" << endl;
}