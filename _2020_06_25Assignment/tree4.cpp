#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
	int i, j;
	int multiplication[10][10]; //2차원 배열 선언

	for (i = 9; i >= 2; i--)  
	{
		cout << "\n[" << i << "단]\n\n";

		for (j = 1; j <= 9; j++)
		{
			multiplication[i][j] = i * j;
			cout << i << "X" << j << "=" << multiplication[i][j] << endl;
		}
	}

	return 0;
}
	/*
	2차원 배열을 통한 구구단 출력을 하는 문제입니다.
	INT I J
	2차배열을 선언했습니다 = MULTIPLICATION
	FOR FOR문
	*/