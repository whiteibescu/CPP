#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

struct Student
{
	char name[20];
	int age;

	void inputStudent()
	{
		cout << "�̸� �Է�: ";
		cin >> name;
		cout << "���� �Է�: ";
		cin >> age;
	}
	void showStudent()
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
};


void main()
{
	Student st;
	st.inputStudent();
	strcpy(st.name, "�� �ٺ�!");
	st.age = -200;
	st.showStudent();
}