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
   값 복사에 의한 호출
   함수 안에서만 값이 바뀌며, 함수 밖으로 나가보면 아무일도 일어나지 않았음

   [Call By Reference]
   참조 값에 의한 호출
   참조 값이 변경(함수 내부)되면 원본의 값(함수 외부)도 변경됨

   [Call By Address]
   주소에 의한 호출
   Call By Value의 한 형태이지만 값이 아닌 원본의 메모리 주소를 복사하므로
   메모리 주소가 바뀌면 원본도 같이 바뀐다.
   Pointer를 쓰는 언어에서만 가능한 값 평가 전략
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