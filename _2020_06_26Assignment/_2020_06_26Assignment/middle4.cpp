#include <iostream>
using namespace std;

// void swap(int a, int b);
void swap(int* a, int* b);
void swap(int& a, int& b);
void swap(int* a, int* b, int* c);
void swap(int& a, int& b, int& c);

int main() {
	int a = 10;
	int b = 20;
	int c = 30;

	// swap(&a, &b);
	// swap(a, b);
	/*swap(&a, &b, &c);*/
	swap(a, b, c);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

}

/*
   [Call By Value]
   �� ���翡 ���� ȣ��
   �Լ� �ȿ����� ���� �ٲ��, �Լ� ������ �������� �ƹ��ϵ� �Ͼ�� �ʾ���

   [Call By Reference]
   ���� ���� ���� ȣ��
   ���� ���� ����(�Լ� ����)�Ǹ� ������ ��(�Լ� �ܺ�)�� �����

   [Call By Address]
   �ּҿ� ���� ȣ��
   Call By Value�� �� ���������� ���� �ƴ� ������ �޸� �ּҸ� �����ϹǷ�
   �޸� �ּҰ� �ٲ�� ������ ���� �ٲ��.
   Pointer�� ���� ������ ������ �� �� ����
*/

//   [Call By Value]
//   This evaluation strategy CANNOT swap a with b
/*
void swap(int a, int b) {
   int temp = a;
   a = b;
   b = temp;
}
*/

//   [Call By Address]
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//   [Call By Reference]
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//   [Call By Address]
void swap(int* a, int* b, int* c) {
	int temp;
	temp = *c;
	*c = *b;
	*b = *a;
	*a = temp;
}

//   [Call By Reference]
void swap(int& a, int& b, int& c) {
	int temp;
	temp = c;
	c = b;
	b = a;
	a = temp;
}