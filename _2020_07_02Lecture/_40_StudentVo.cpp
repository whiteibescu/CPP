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
	// ������ ���� getter/setter �Լ�
	string getName()
	{
		return this->name;
	}
	void setName(string name)
	{
		this->name = name;
	}

	void setName(string name)
	{
		this->name = name;
	}
	string getAddress()
	{
		return this->address;
	}
	void setAddress(string address)
	{
		this->address = address;
	}
	int getAge()
	{
		return this->age;
	}
	void setAge(int age)
	{
		this->age = age;
	}
};

void main()
{
	Student st;
	st.setName("ȫ�浿");
	st.setAddress("������");
	st.setAge(24);
}