#include <iostream>

using namespace std;

int main()
{
	char str[50];
	int len = 0;

	cout << "���� ������ �Է����ּ���: - > ";

	cin >> str;

	while (str[len] != 0)
		len++;
	len--;
	while (len > -1)
	{
		cout << str[len];
		len--;
	}
	cout << "\n";

}