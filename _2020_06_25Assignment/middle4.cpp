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
		cout << "����(integer)�� �Է��Ͻð� ���� ���Ͻø� 0�� �����ּ���  - > ";
		cin >> num;
		total += num;
	}
	cout << "�Էµ� ������ �� - > " << total;
}