/* static ��� ������
  Ŭ������ �����ϰ� �����ϴ� �����̹Ƿ�
  �ַ� ��ü���� ����������/�����ϰ� �����ϴ�
  �����͸� �����ؼ� ����Ѵ�
*/

#include <iostream>

#define NAME_LEN	30

using namespace std;

class Bitcamp
{
private:
	/*�Ϲ� ��������� ��ü������
	��ü���� �����ȴ�*/
	char name[NAME_LEN];
	int studentCnt = 0;

	//int sumStudentCnt = 0;

	/*Ŭ������ ����� static ��������� �����ȴ�
	  ��ü���ٵ� ���� �����ȴ�
	  �ƹ��� ��ü�� ���Ƶ� Ŭ������ ������
	  ������ �����Ѵ�
	  ��� ��ü�� �� static��������� ������ �� �ִ�*/
	  /*static�� ��ü�Ҽ��� �ƴ϶� Ŭ���� �Ҽ��̴�
	  �ٸ� ��ü�ε� ���ٰ����ϴ�*/
	static int bitcampStudentCnt;

public:
	Bitcamp(const char* _name, int _studentCnt)
	{
		strncpy_s(name, sizeof(name),
			_name, strlen(_name) + 1);
		studentCnt = _studentCnt;

		//sumStudentCnt += _studentCnt;
		bitcampStudentCnt += _studentCnt;
	}
	void showInfo()
	{
		cout << "������ : " << name << endl;
		cout << "�л��� : " << studentCnt << endl;
	}

	//int getSumStudentCnt()
	//{
	//	return sumStudentCnt;
	//}

	static int getBitcampStudentCnt()
	{
		return bitcampStudentCnt;
	}
};

// static ��������� �ʱ�ȭ ���
int Bitcamp::bitcampStudentCnt = 0;

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

	cout << "��Ʈķ���� ���л����� " <<
		Bitcamp::getBitcampStudentCnt()
		//bitSeomyun.getBitcampStudentCnt()
		<< " �Դϴ�" << endl;

	//cout << "��Ʈķ���� ���л����� " <<
	//	bitSeomyun.getSumStudentCnt()
	//	<< " �Դϴ�" << endl;
}