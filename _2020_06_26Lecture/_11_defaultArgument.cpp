#include <iostream>

using namespace std;

void showInfo(const char* nation, const char* name,
	int exPhoneNum, const char* phone)
{
	cout << "���� : " << nation << endl;
	cout << "�̸� : " << name << endl;
	cout << "���� : " << exPhoneNum << endl;
	cout << "��ȭ : " << phone << endl;
}
void main()
{
	showInfo("���ѹα�", "ȫ�浿", 82, "010-1111-2222");
}
