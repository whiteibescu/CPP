#include "_07_struct_01.h"
#include "_07_struct_02.h"
#include "_07_namespace.h"
#include <iostream>

using namespace A::Score;
using namespace std;

void main()
{
	//A::Score::Student st = { "홍길동", 90, 88, 100 };
	Student st = { "홍길동", 90, 88, 100 };
	std::cout << "이름: " << st.name << '\n';
	std::cout << "국어: " << st.kor << '\n';
	std::cout << "수학: " << st.math << '\n';
	std::cout << "영어: " << st.eng << '\n';

	cout << endl << endl;

	B::Personal::Student st1 = { "홍길동", "지리산",
				24, 174.5f, 76.5f };
	std::cout << "이름: " << st1.name << '\n';
	std::cout << "주소: " << st1.address << '\n';
	std::cout << "나이: " << st1.age << '\n';
	std::cout << "키: " << st1.height << '\n';
	std::cout << "몸무게: " << st1.weight << '\n';

	cout << endl << endl;

	std::cout << A::name << std::endl;
	std::cout << B::name << std::endl;

	cout << endl << endl;

	std::cout << A::job << std::endl;
	std::cout << B::job << std::endl;
}