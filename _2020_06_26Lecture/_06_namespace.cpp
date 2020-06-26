#include "_06_struct_01.h"
#include "_06_struct_02.h"
#include <iostream>

void main()
{
	Score::Student st = { "홍길동", 90, 88, 100 };
	std::cout << "이름: " << st.name << '\n';
	std::cout << "국어: " << st.kor << '\n';
	std::cout << "수학: " << st.math << '\n';
	std::cout << "영어: " << st.eng << '\n';

	std::cout << std::endl << std::endl;

	Personal::Student st1 = { "홍길동", "지리산",
				24, 174.5f, 76.5f };
	std::cout << "이름: " << st1.name << '\n';
	std::cout << "주소: " << st1.address << '\n';
	std::cout << "나이: " << st1.age << '\n';
	std::cout << "키: " << st1.height << '\n';
	std::cout << "몸무게: " << st1.weight << '\n';
}