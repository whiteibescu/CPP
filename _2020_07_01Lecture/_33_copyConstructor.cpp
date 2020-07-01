#include <iostream>

#define NAME_LEN	20

using namespace std;

class Student
{
private:
	char* name;

public:
	Student()
	{
		name = new char[NAME_LEN]();
	}
	/*
	Student(Student stParam)
	{
		name = new char[NAME_LEN]();
		memcpy(name, st.name, NAME_LEN);
	}
	*/
	// ����������� �Ű������� �ݵ�� reference
	// ���� �Ѵ�
	Student(const Student& st)
	{
		name = new char[NAME_LEN]();
		memcpy(name, st.name, NAME_LEN);
	}
	~Student()
	{
		delete[] name;
	}
public:
	void setName(const char* _name)
	{
		strncpy_s(name, NAME_LEN, _name, strlen(_name) + 1);
	}
	void showName()
	{
		cout << "�̸�: " << name << endl;
	}
};

void main()
{
	Student st;// �Ű����� ���� ������ ȣ��
	st.setName("ȫ�浿");
	st.showName();

	Student st1 = st;// Student st1(st);
	st1.showName();

	st1.setName("�Ӳ���");
	st.showName();
	st1.showName();
}