#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	char str[256] = { 0 };
	int i = 0;

	cout << "�ҹ��ڳ� �빮�� �Է��ϼ��� - > : ";
	cin >> str, sizeof(str);

	for (i = 0; i < (int)strlen(str); i++)
	
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	
	else if (str[i] >= 'a' && str[i] <= 'z')
	
	str[i] -= 32;
	
	cout << "�Է��� ���� ��/�ҹ��� ��ȯ" << endl;
	cout << str;
}