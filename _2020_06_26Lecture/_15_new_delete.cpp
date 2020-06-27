/* 동적할당
1) 사용빈도수가 매우 높기 때문에
   아예 속도향상을 위해서 함수->연산자로 내장
2) 사용이 편하게 만듬
C :  malloc, calloc, realloc, free 함수 사용
C++ : new delete 연산자로 컴파일러에 내장
*/
#include <iostream>

using namespace std;

void main()
{
	// 4byte int 1개 동적할당
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