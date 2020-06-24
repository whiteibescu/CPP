#include <iostream>

using namespace std;

void main()
{
	int* num = new int();
	*num = 100;
	cout << *num << endl;
	delete num;
}