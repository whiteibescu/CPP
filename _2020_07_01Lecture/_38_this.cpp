/* ��������� ��ü���� ���� �����Ѵ�
   ����Լ��� ù��° ��ü�� ������ �� �޸𸮿� �ö󰣴�.
   �� ���� ��ü���� �޸𸮰� �ö� �Լ��� �����ؼ� ����Ѵ�.

   �Լ��� ������ �׷��̹Ƿ� ������ ǥ���̱� ������
   ��ü���� �����ؼ� ����ϰ� �ȴ�.

   ��. st0.showInfo()�� ȣ���� ���� st0�� name�� age�� ���
	   st1.showInfo()�� ȣ���� ���� st1�� name�� age�� ���
*/
#include <iostream>

using namespace std;

class Student
{
private:
	string name;
	int age;
public:
	Student(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void showInfo()
	{
		cout << "�̸� : " << this->name << endl;
		cout << "���� : " << this->age << endl;
	}
};

void main()
{
	Student st0("ȫ�浿", 24);
	Student st1("�Ӳ���", 33);
	st0.showInfo();
	st1.showInfo();
}