/* �����Ҵ�
1) ���󵵼��� �ſ� ���� ������
   �ƿ� �ӵ������ ���ؼ� �Լ�->�����ڷ� ����
2) ����� ���ϰ� ����
C :  malloc, calloc, realloc, free �Լ� ���
C++ : new delete �����ڷ� �����Ϸ��� ����
*/
#include <iostream>

using namespace std;

void main()
{
	// 4byte int 1�� �����Ҵ�
	int* num = (int*)malloc(sizeof(int));
	*num = 10;
	cout << *num << endl;
	free(num);

	int* num1 = new int;	// malloc()
	//int* num1 = new int();	// calloc()
	*num1 = 20;
	cout << *num1 << endl;
	delete num1;
}