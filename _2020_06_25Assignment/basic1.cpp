#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int a, b, sum, sum2;
	cout << "ù��° ���� �Է� : ";
	cin >> a;
	cout << "�ι�° ���� �Է� : ";
	cin >> b;
	sum = a % b;
	sum2 = a / b;
	cout << "�� : " << sum << "   ������ : " << sum2 << endl;
}