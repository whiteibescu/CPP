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
		memset(this->m_strName, 0, NAME_LEN);
		strcpy(this->m_strName, _Name);
	}
	Theater(const Theater& theater)
	{
		this->m_strName = new char[NAME_LEN];
		memset(this->m_strName, 0, NAME_LEN);
	}
	~Theater()
	{
		delete[] this->m_strName;
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



/* It is rahter for us to be here dedicated to the great task remaining before us - that from these honored men we take increased devotion to that cause
from which they gave the last full measurement of devotion  */