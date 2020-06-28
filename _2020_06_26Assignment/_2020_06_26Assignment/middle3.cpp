#include <iostream>

using namespace std;


void swap(int* a, int* b, int* c);

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	swap(&a, &b, &c);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
}

//   [Call By Address]
void swap(int* a, int* b, int* c) {
	int temp;
	temp = *c;
	*c = *b;
	*b = *a;
	*a = temp;
}