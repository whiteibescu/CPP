#include <iostream>

using namespace std;
/*
������ �迭�� �����ּҸ� �Լ��� ������ ����
2���� �����ͷ� �Ű������� ������ �Ѵ�.
*/
void printNames(const char** names, int len)
{
	for (int i = 0; i < len; i++)
		cout << names[i] << endl;
}
void main()
{
	const char* names[] = 
		{ "ȫ�浿", "�Ӳ���", "����" };
	printNames(names, sizeof(names)/sizeof(names[0]));
}