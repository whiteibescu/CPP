#include <iostream>

using namespace std;

void main()
{
	int num = 10;
	int* ptr = &num;
	int** dptr = &ptr;
	int*** tptr = &dptr;

	cout << num << endl;
	cout << *ptr << endl;
	cout << endl;

	cout << dptr << endl; // ptr�� �ּ�
	cout << *dptr << endl; // ptr ����(����)
	cout << **dptr << endl; // num
	cout << ***tptr << endl; // num
}