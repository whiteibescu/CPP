#include <iostream>

using namespace std;

/* 
int* ptr���� 
int*�� �ڷ����̰� ptr�� �����̸��̴�
�ٸ� ptr�� int������ int�迭�� �����ּҸ�
���� �� �ִ� ���ҷ� ������ ���̴�
�׷��� ptr�� &ptr�� ����ϸ�
ptr�� �ּҰ� ����� �ȴ�.
*/
void main()
{
	int num = 10;
	int* ptr = &num;

	cout << &num << endl;
	cout << *ptr << endl;
	cout << sizeof(ptr) << endl;
	cout << &ptr << endl;
}