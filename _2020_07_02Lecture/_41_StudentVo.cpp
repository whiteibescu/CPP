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
	Student(string name = "", string address = "", int age = 0) {
		this->name = name;
		this->address = address;
		this->age = age;
	}

public:
	// ������ ���� getter/setter �Լ�
	string getName() {
		return this->name;
	}
	Student& setName(string name) {
		this->name = name;
		return *this;
	}
	string getAddress() {
		return this->address;
	}
	Student& setAddress(string address) {
		this->address = address;
		return *this;
	}
	int getAge() {
		return this->age;
	}
	Student& setAge(int age) {
		this->age = age;
		return *this; // �� ������ ����ִ� ������ 
	}
};

void main()
{
	Student st;
	//setName(&st, "ȫ�浿");
	st.setName("ȫ�浿")
	  .setAddress("������")
	  .setAge(24);

	cout << st.getName() << ":" <<
		st.getAddress() << ":" <<
		st.getAge() << endl;

}