#include "Human.h"

Human::Human(string name, int age) {
	this->name = name;
	this->age = age;
	cout << "Human ������ ȣ��" << endl;
}
Human::~Human()
{
	cout << "Human �Ҹ��� ȣ��" << endl;
}
void Human::eat()
{
	cout << this->name << "�� ���� �Դ´�" << endl;
}
void Human::sleep()
{
	cout << this->name << "�� ���� �ܴ�" << endl;
}
void Human::work()
{
	cout << this->name << "�� ���� �Ѵ�" << endl;
}
void Human::info()
{
	cout << "�̸� : " << this->name << endl;
	cout << "���� : " << this->age << endl;
}
