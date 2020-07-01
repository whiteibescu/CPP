#include <iostream>

#define NAME_LEN	30

using namespace std;

class Bitcamp
{
private:
	char name[NAME_LEN];
	int studentCnt = 0;

public:
	Bitcamp(const char* _name, int _studentCnt)
	{
		strncpy_s(name, sizeof(name),
			_name, strlen(_name) + 1);
		studentCnt = _studentCnt;
	}
	void showInfo()
	{
		cout << "������ : " << name << endl;
		cout << "�л��� : " << studentCnt << endl;
	}
	int getStudentCnt()
	{
		return studentCnt;
	}
};

void main()
{
	Bitcamp bitSeocho("��Ʈķ�� ����", 300);
	Bitcamp bitGangnam("��Ʈķ�� ����", 120);
	Bitcamp bitJongro("��Ʈķ�� ����", 200);
	Bitcamp bitSinchon("��Ʈķ�� ����", 150);
	Bitcamp bitSeomyun("��Ʈķ�� ����", 22);

	bitSeocho.showInfo();
	bitGangnam.showInfo();
	bitJongro.showInfo();
	bitSinchon.showInfo();
	bitSeomyun.showInfo();

	int totalStudentCnt =
		bitSeocho.getStudentCnt() +
		bitGangnam.getStudentCnt() +
		bitJongro.getStudentCnt() +
		bitSinchon.getStudentCnt() +
		bitSeomyun.getStudentCnt();

	cout << "��Ʈķ���� �� �л����� " << totalStudentCnt
		<< " �Դϴ�" << endl;
}