#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "human.h"

using namespace std;

Human::Human(int age, char* Name)
{
	m_nAge = age;
	m_strName = new char[strlen(Name) + 1];
	strcpy(m_strName, Name);
	cout << "Human ������ ȣ��" << endl;
}

Human::~Human()
{
	delete[] m_strName;
	cout << "Human �Ҹ��� ȣ��" << endl;
}

void Human::Eat()
{
	cout << m_strName << "�� ���� �Դ´�" << endl;
}

void Human::Sleep()
{
	cout << m_strName << "�� ���� �ܴ�" << endl;
}

void Human::Work()
{
	cout << m_strName << "�� ���� �Ѵ�" << endl;
}

void Human::Info()
{
	cout << "�̸�: " << m_strName << endl;
	cout << "����: " << m_nAge << endl;
}

void main()
{
	
}