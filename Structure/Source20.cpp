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
	cout << "관객수 : " << Theater::GetViewerCount() << "명" << endl;

	Theater theater1 ("단성사");
	Theater theater2 ("서울극장");
	Theater theater3 ("명동CGV");

	for (int i = 0; i < 1000000; ++i)
		theater1.AddViewerCount();
	for (int i = 0; i < 1500000; ++i)
		theater2.AddViewerCount();
	for (int i = 0; i < 2000000; ++i)
		theater3.AddViewerCount();

	cout << "관객수 : " << Theater::GetViewerCount() << "명" << endl;




}