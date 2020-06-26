#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int num;
	int i = 0;
	cout <<"양의 정수를 입력해주세요 : ";
	cin >> num;
	do
	{
		printf("감사합니다!\n");
		++i;
	} while (i < num);
}