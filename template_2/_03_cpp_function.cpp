#include <iostream>

using namespace std;

/* C++ ������
function overloading�� �����ȴ�
������ �̸��� �Լ���������
�Ű������� �ٸ��� �����Ϸ��� ����
 ȣ���� ���еȴ�*/

int add(int a, int b) {
	return a + b;
}
double add(double a, double b) {
	return a + b;
}
void main()
{
	cout << add(100, 200) << endl;
	cout << add(2.5, 3.4) << endl;
}