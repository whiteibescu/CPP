#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
	int i, j;
	int multiplication[10][10]; //2���� �迭 ����

	for (i = 9; i >= 2; i--)  
	{
		cout << "\n[" << i << "��]\n\n";

		for (j = 1; j <= 9; j++)
		{
			multiplication[i][j] = i * j;
			cout << i << "X" << j << "=" << multiplication[i][j] << endl;
		}
	}

	return 0;
}
	/*
	2���� �迭�� ���� ������ ����� �ϴ� �����Դϴ�.
	INT I J
	2���迭�� �����߽��ϴ� = MULTIPLICATION
	FOR FOR��
	*/