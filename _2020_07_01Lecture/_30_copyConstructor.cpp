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
		cout << "이름: " << name << endl;
	}
};

void main()
{
	Student st;	// default 생성자 호출
	st.setName("홍길동");
	st.showName();

	// 복사생성자 호출
	// 멤버변수간의 복사가 이루어진다
	Student st1 = st;// Student st1(st);
	st1.showName();
}