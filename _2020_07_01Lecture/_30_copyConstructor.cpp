#include <iostream>

using namespace std;

class Student
{
private:
	char name[20];

public:
	void setName(const char* _name)
	{
		strncpy_s(name, sizeof(name), _name, strlen(_name));
	}
	void showName()
	{
		cout << "�̸�: " << name << endl;
	}
};

void main()
{
	Student st;	// default ������ ȣ��
	st.setName("ȫ�浿");
	st.showName();

	// ��������� ȣ��
	// ����������� ���簡 �̷������
	Student st1 = st;// Student st1(st);
	st1.showName();
}