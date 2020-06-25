#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define NAME_LEN 30

class Theater
{
private:
	char* m_strName;
	static int m_nViewerCount;

public:
	Theater(char* _Name)
	{
		this->m_strName = new char[NAME_LEN];
		memset(m_strName, 0, NAME_LEN);
		strcpy(m_strName, _Name);
	}
	Theater(const Theater& theater)
	{
		m_strName = new char[NAME_LEN];
		memset(m_strName, 0, NAME_LEN);
		memcpy(m_strName, theater.m_strName, NAME_LEN);
	}
	~Theater()
	{
		delete[] m_strName;
	}
	static void AddViewerCount()
	{
		m_nViewerCount++;
	}
	static int GetViewerCount()
	{
		return m_nViewerCount;
	}
};

int Theater::m_nViewerCount = 0;

void main()
{
	cout << "������ : " << Theater::GetViewerCount() << "��" << endl;

	Theater theater1 ("�ܼ���");
	Theater theater2 ("�������");
	Theater theater3 ("��CGV");

	for (int i = 0; i < 1000000; ++i)
		theater1.AddViewerCount();
	for (int i = 0; i < 1500000; ++i)
		theater2.AddViewerCount();
	for (int i = 0; i < 2000000; ++i)
		theater3.AddViewerCount();

	cout << "������ : " << Theater::GetViewerCount() << "��" << endl;




}