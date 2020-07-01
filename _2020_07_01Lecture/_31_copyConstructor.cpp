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
	~Student()
	{
		delete[] name;
	}
public:
	void setName(const char* _name)
	{
		strncpy_s(name, NAME_LEN, _name, strlen(_name)+1);
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

	/* ��������� �����ͺ����̹Ƿ�
	st�� name�� �ּҰ� st1�� name�� ����ȴ�
	�׷��Ƿ� st.name�� st1.name�� ���� 
	���޸��� ������ ����Ű�� �ȴ�.
	1) st.name�� ���ڿ��� �ٲٸ� 
	   st1.name�� ���ڿ��� ������ �޴´�
	2) st�� �Ҹ��ڰ� ȣ��� �� ���޸𸮸� �����ϹǷ�
	   st1�� �Ҹ��ڿ��� ���޸𸮸� �����õ��� ��
	   ������ �߻��Ѵ�

	* �ذ�å : ��������ڸ� ���鶧
	          name������ ������ ������ ���޸�
			  ������ ����Ű���� �����ϴ�
	*/
	
	// �����Ϸ��� ������ default ��������� ȣ��
	// ����������� ���簡 �̷������
	Student st1 = st;// Student st1(st);
	st1.showName();

	st1.setName("�Ӳ���");
	st.showName();
	st1.showName();
}// st�Ҹ���, st1�Ҹ���