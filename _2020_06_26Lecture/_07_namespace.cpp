#include "_07_struct_01.h"
#include "_07_struct_02.h"
#include "_07_namespace.h"
#include <iostream>

using namespace A::Score;
using namespace std;

void main()
{
	//A::Score::Student st = { "ȫ�浿", 90, 88, 100 };
	Student st = { "ȫ�浿", 90, 88, 100 };
	std::cout << "�̸�: " << st.name << '\n';
	std::cout << "����: " << st.kor << '\n';
	std::cout << "����: " << st.math << '\n';
	std::cout << "����: " << st.eng << '\n';

	cout << endl << endl;

	B::Personal::Student st1 = { "ȫ�浿", "������",
				24, 174.5f, 76.5f };
	std::cout << "�̸�: " << st1.name << '\n';
	std::cout << "�ּ�: " << st1.address << '\n';
	std::cout << "����: " << st1.age << '\n';
	std::cout << "Ű: " << st1.height << '\n';
	std::cout << "������: " << st1.weight << '\n';

	cout << endl << endl;

	std::cout << A::name << std::endl;
	std::cout << B::name << std::endl;

	cout << endl << endl;

	std::cout << A::job << std::endl;
	std::cout << B::job << std::endl;
}