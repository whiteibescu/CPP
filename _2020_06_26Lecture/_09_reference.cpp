#include <iostream>

using namespace std;

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapPtr(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

// 레퍼런스 : 별명, 김두한 == 긴또깡
//1) 포인터의 low레벨 느낌을 제거
//2) 포인터 ( 포인터 연산을 통해 시스템의 다른 부분을 접근 할 수 있는데
//이런 것이 프로그래밍의 잠재적 위험을 가져올 수 있따
//-> 그래서 제한적인 해당 변수만의 접근을 허용하는 방식으로 바꾼 것)
void swapRef(int& ra, int& rb)
{
	int temp = ra;
	ra = rb;
	rb = temp;
}

void main()
{
	int num0 = 10, num1 = 20;
	cout << "num0: " << num0 << endl;
	cout << "num1: " << num1 << endl;
	//swap(num0, num1);
	//swapPtr(&num0, &num1);
	swapRef(num0, num1);
	cout << "num0: " << num0 << endl;
	cout << "num1: " << num1 << endl;
}