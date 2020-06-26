#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int a, b, sum, sum2;
	cout << "첫번째 정수 입력 : ";
	cin >> a;
	cout << "두번째 정수 입력 : ";
	cin >> b;
	sum = a % b;
	sum2 = a / b;
	cout << "몫 : " << sum << "   나머지 : " << sum2 << endl;
}