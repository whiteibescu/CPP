#include <iostream>

using namespace std;

class Student
{
private:
	// �������(�ʵ�)
	char name[20];

public:
	// ����Լ�(�޼���)
	void setName(const char* _name)
	{
		strncpy(name, _name, strlen(_name));
	}
	void showName()
	{
		cout << "�̸�: " << name << endl;
	}
};

void main()
{
	/* ������ ������/�Ҹ��ڸ� �������� ������
	  �����Ϸ��� �����Ͻ� default������/�Ҹ��ڸ�
	  �߰��ؼ� �ִ´�.
	  �ٸ� �ƹ��ϵ� ���� �ʴ´�.
	*/
	Student st;	// ������ ȣ��
}	// �Ҹ��� ȣ��