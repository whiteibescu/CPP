#include "_06_struct_01.h"
#include "_06_struct_02.h"
#include <iostream>

void main()
{
	Score::Student st = { "ȫ�浿", 90, 88, 100 };
	std::cout << "�̸�: " << st.name << '\n';
	std::cout << "����: " << st.kor << '\n';
	std::cout << "����: " << st.math << '\n';
	std::cout << "����: " << st.eng << '\n';

	std::cout << std::endl << std::endl;

	Personal::Student st1 = { "ȫ�浿", "������",
				24, 174.5f, 76.5f };
	std::cout << "�̸�: " << st1.name << '\n';
	std::cout << "�ּ�: " << st1.address << '\n';
	std::cout << "����: " << st1.age << '\n';
	std::cout << "Ű: " << st1.height << '\n';
	std::cout << "������: " << st1.weight << '\n';
}