#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int num = 1;
	int total = 0;

	while (num != 0)
	{
		cout << "정수(integer)를 입력하시고 합을 원하시면 0을 눌러주세요  - > ";
		cin >> num;
		total += num;
	}
	cout << "입력된 정수의 합 - > " << total;
}