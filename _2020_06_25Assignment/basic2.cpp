#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;
	int sum;
	cout << "첫번째 정수 입력 : ";
	cin >> a;
	cout << "두번째 정수 입력 : ";
	cin >> b;
	cout << "세번째 정수 입력 : ";
	cin >> c;
	sum = a * a + b * b + c * c;
	cout << "합은 : " << sum << endl;
}