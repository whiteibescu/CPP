#include <iostream>

using namespace std;

int Sum(char* str)
{
	int sum = 0;
	int i;

	for (i = 0; i < strlen(str); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			sum += str[i] - '0';
		}
	}
	return sum;
}

int main()
{
	char str[200];

	cout << "���ڿ� ��� : ";
	cin >> str;

	cout << "���� ���� : ", Sum(str);
}