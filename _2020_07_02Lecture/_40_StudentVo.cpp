/* MVC ����
Model : ������, �����ͺ��̽�, ����
 1) VO(Value Object)
   ; ���� �����ϴ� ������ ��ü
 2) DAO(Data Access Object)
   ; ����ҿ� ������� ����ϴ� ��ü
*/
#include <iostream>

using namespace std;

class Student
{
private:
	string name;
	string address;
	int age;

public:
	Student(string name="", string address="", int age=0) {
		this->name = name;
		this->address = address;
		this->age = age;
	}

public:
	// ������ ���� getter/setter �Լ�
	string getName() {
		return this->name;
	}
	void setName(string name) {
		this->name = name;
	}
	string getAddress() {
		return this->address;
	}
	void setAddress(string address) {
		this->address = address;
	}
	int getAge() {
		return this->age;
	}
	void setAge(int age) {
		this->age = age;
	}
};

void main()
{
	Student st;
	st.setName("ȫ�浿");
	st.setAddress("������");
	st.setAge(24);
	cout << st.getName() << ":" <<
		st.getAddress() << ":" <<
		st.getAge() << endl;

	cout << endl;

	Student st1("�Ӳ���", "������", 33);
	cout << st1.getName() << ":" <<
		st1.getAddress() << ":" <<
		st1.getAge() << endl;
}